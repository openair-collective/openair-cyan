/*
David Wilson
OpenAir Collective
Version 3 6/17/2022
This version is used with the balanced EC meter design. Requires
an ARM M0 processor such as the Adafruit Feather M0. Not tested
with any other device.
Hardware design:
A5 and A4 connected.
A1 and A0 connected.
R1 between A4 and A3.
R1 between A2 and A1.
EC Probe between A3 and A2.
Version 3 added a second probe and set ADC resolution to 12
*********************************************************************/

#include <Arduino.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
#include <SoftwareSerial.h>
#endif

#define NAVGS 500
#define NCHAN 2
#define CYCLE_TIME_SECS 60 //Freely adjust this to set measurement repetition time

const int V1SourcePin   =   6;
const int V2SourcePin   =   12;
const int V1SensePin    =   A5; 
const int VaSensePin[2] =   {A4, A3}; 
const int VbSensePin[2] =   {A2, A1};
const int V2SensePin    =   A0;

uint32_t startMeasMs, startTimeMs;
float eTime;

const float cal[2] = {1545000.0, 1384000.0}; //Relates measured resistance Rx to EC in uS/cm. User needs to calibrate for EACH SENSOR.
const float R1Tot[2] = {7576, 7586}; //Sum of both R1's together; Make sure to update this and recompile if R1 is changed.
const float offsetR[2] = {-10.0, -10.0}; //Empirical adjustment

float RxMeas;  //Measured value of lumped resistance of fluid across probe

/***************************************Setup ******************************************************/
void setup(void)
{
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }

  pinMode(V1SensePin, INPUT);
  pinMode(V1SourcePin,OUTPUT);
  pinMode(VaSensePin[0], INPUT);
  pinMode(VaSensePin[1], INPUT);
  pinMode(VbSensePin[0], INPUT);  
  pinMode(VbSensePin[1], INPUT);  
  pinMode(V2SourcePin,OUTPUT);
  pinMode(V2SensePin, INPUT);
 
  digitalWrite(V1SourcePin, LOW);  
  digitalWrite(V2SourcePin, LOW);

  startMeasMs = startTimeMs = millis();
  startMeasMs += (uint32_t) CYCLE_TIME_SECS * 1000;
  Serial.println("Starting...");
  Serial.println("Time         Channel 0  Red                Channel 1 Wht");
  Serial.println(" (h)        R (ohm)  S(uS/cm)    ||     R(ohm)    S(uS/cm)");

}

void loop(void) {
  int i;
  float rMeasTop[2], rMeasBot[2], rMeasAvg[2];
  float ecTop[2], ecBot[2], ecAvg[2];
  rMeasTop[0] = 0.0;
  rMeasBot[0] = 0.0;
  rMeasTop[1] = 0.0;
  rMeasBot[1] = 0.0;  

  while ((millis() - startMeasMs) < CYCLE_TIME_SECS * 1000) {
    }  
  startMeasMs = millis();

  for (i=0; i<NAVGS; i++) {
    rMeasTop[0] += readTop(0);
    rMeasBot[0] += readBot(0);
    rMeasTop[1] += readTop(1);
    rMeasBot[1] += readBot(1);
    }
  
  rMeasTop[0] /= NAVGS;
  rMeasBot[0] /= NAVGS;
  rMeasAvg[0] = (rMeasTop[0] + rMeasBot[0])/2.0 + offsetR[0];
  rMeasTop[1] /= NAVGS;
  rMeasBot[1] /= NAVGS;
  rMeasAvg[1] = (rMeasTop[1] + rMeasBot[1])/2.0 + offsetR[1];
  
  ecAvg[0] = cal[0] / rMeasAvg[0];
  ecAvg[1] = cal[1] / rMeasAvg[1];

  eTime = (millis() - startTimeMs) / 3600000.0;
     
 Serial.print(eTime, 4); Serial.print("       ");
 Serial.print(rMeasAvg[0],2);Serial.print("     "); 
    Serial.print(ecAvg[0],2);Serial.print("       ");
 Serial.print(rMeasAvg[1],2);Serial.print("       ");
    Serial.println(ecAvg[1],2);
}

/**************************************************************************************
*                     Other Functions 
**************************************************************************************/
//************Read EC probe functions****************
float readTop(int chan){
  float dVs, dVx, rout;
  uint16_t readA, readB;
  analogReadResolution(12);
  digitalWrite(V1SourcePin, HIGH);
  readA = analogRead(VaSensePin[chan]);
  readB = analogRead(VbSensePin[chan]);
  dVs = (float) (analogRead(V1SensePin) - analogRead(V2SensePin));
  digitalWrite(V1SourcePin, LOW);
  dVx = (float) (readA - readB);
  rout = R1Tot[chan] * dVx / (dVs - dVx);
  delay(1);
  return rout;
}  

float  readBot(int chan){
  float dVs, dVx, rout;
  uint16_t readA, readB;
  analogReadResolution(12);
  digitalWrite(V2SourcePin, HIGH);
  readB = analogRead(VbSensePin[chan]);
  readA = analogRead(VaSensePin[chan]);
  dVs = (float) (analogRead(V2SensePin) - analogRead(V1SensePin));
  digitalWrite(V2SourcePin, LOW);
  dVx = (float) (readB - readA);
  rout = R1Tot[chan] * dVx / (dVs - dVx);
  delay(1);
  return rout;
}  
