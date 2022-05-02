/*
David Wilson
OpenAir Collective
Version 1 4/18/22
*********************************************************************/

#include <Arduino.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
#include <SoftwareSerial.h>
#endif

#define NAVGS 100

const int V1SensePin = A5;
const int V1SourcePin= A4; 
const int VreadPin = A2;
const int V2SourcePin= A1;
const int V2SensePin=A0;

const float cal=1384000.0; //Relates measured resistance R2 to EC in uS/cm. User needs to calibrate for each sensor.
const float R1= 326.8; //Make sure to update this and recompile if R1 is changed.
float R2;  //Measured value of lumped resistance of fluid across probe

/***************************************Setup ******************************************************/
void setup(void)
{

  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }

  pinMode(V1SensePin, INPUT);
  pinMode(V1SourcePin,OUTPUT);
  pinMode(VreadPin, INPUT);  
  pinMode(V2SourcePin,OUTPUT);
  pinMode(V2SensePin, INPUT);
 
  digitalWrite(V1SourcePin, LOW);  
  digitalWrite(V2SourcePin, LOW);

}

void loop(void) {
  int i;
  float rMeasTop, rMeasBot, rMeasAvg;
  float ecTop, ecBot, ecAvg;
  rMeasTop = 0.0;
  rMeasBot = 0.0;
  
  for (i=0; i<NAVGS; i++) {
    rMeasTop += readTop();
    delay(10);
    rMeasBot += readBot();
    delay(10); 
  }
  rMeasTop /= NAVGS;
  rMeasBot /= NAVGS;
  rMeasAvg = (rMeasTop + rMeasBot)/2.0;

  ecTop = cal / rMeasTop;
  ecBot = cal / rMeasBot;
  ecAvg = cal / rMeasAvg;
   
  Serial.print("R2:  ");Serial.print(  rMeasAvg);Serial.print("    EC:  ");Serial.println(ecAvg,4);

}

/**************************************************************************************
*                     Other Functions 
**************************************************************************************/
//************Read EC probe functions****************
float readTop(){
  int i, v1, v2, vout;
  float rout;
  digitalWrite(V1SourcePin, HIGH);
  //Throw away first reading
  analogRead(V1SensePin);
  analogRead(V2SensePin);
  analogRead(VreadPin);  
  v1 = analogRead(V1SensePin);
  v2 = analogRead(V2SensePin);
  vout = analogRead(VreadPin); 
  digitalWrite(V1SourcePin, LOW);
  rout = R1 * (float) (vout - v2) / (v1 - vout);
  return rout;
}  

float  readBot(){
  int i, v1, v2, vout;
  float rout;
  digitalWrite(V2SourcePin, HIGH);
  //Throw away first reading
  analogRead(V1SensePin);
  analogRead(V2SensePin);
  analogRead(VreadPin);  
  v1 = analogRead(V1SensePin);
  v2 = analogRead(V2SensePin);
  vout = analogRead(VreadPin); 
  digitalWrite(V2SourcePin, LOW);
  rout = R1 * (float) (v2 - vout) / (vout - v1);
  return rout;;
}  
