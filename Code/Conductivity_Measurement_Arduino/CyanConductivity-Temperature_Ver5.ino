
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
Version 5 added temperature probes (8/16/2022). 
    --Can support one optional DHT temperature probe (or comment out)
    --Can support two one-wire DS18B20 probes, more by changing MAX_DEVS and output 
         print statements.
*********************************************************************/
/* Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
*********************************************************************/
// OneWire DS18S20, DS18B20, DS1822 Temperature Example
//
// http://www.pjrc.com/teensy/td_libs_OneWire.html
//
// The DallasTemperature library can do all this work for you!
// https://github.com/milesburton/Arduino-Temperature-Control-Library

#include <Arduino.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
#include <SoftwareSerial.h>
#endif
#include "DHT.h"
#include <OneWire.h>

#define CYCLE_TIME_SECS 60 //Freely adjust this to set measurement repetition time
#define NAVGS 500
#define NCHAN 2
#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define ONEWIREPIN 9 //Digital pin connected so any number of One-Wire devices
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define DHTTYPE DHT21   // DHT 21 (AM2301)

const int V1SourcePin   =   6;
const int V2SourcePin   =   12;
const int V1SensePin    =   A5; 
const int VaSensePin[2] =   {A4, A3}; 
const int VbSensePin[2] =   {A2, A1};
const int V2SensePin    =   A0;

uint32_t startMeasMs, startTimeMs;
float eTime;

#define K_CAL0 1.458 //Cell Constant for Probe 0
#define K_CAL1 1.423 //Cell Constant for Probe 1
const float cal[2] = {K_CAL0 * 1000000.0, K_CAL1 * 1000000.0}; //Relates measured resistance Rx to EC in uS/cm. User needs to calibrate for EACH SENSOR.
const float R1Tot[2] = {7576, 7586}; //Sum of both R1's together; Make sure to update this and recompile if R1 is changed.
const float offsetR[2] = {-10.0, -10.0}; //Empirical adjustment

float RxMeas;  //Measured value of lumped resistance of fluid across probe

DHT dht(DHTPIN, DHTTYPE);
OneWire  ds(ONEWIREPIN);  

#define MAX_DEVS 2
uint8_t addr[8], addrx[MAX_DEVS][8];
int dev;
/***************************************Setup ******************************************************/
void setup(void)
{
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }

  pinMode(V1SensePin, INPUT);
  pinMode(V1SourcePin,OUTPUT);
  pinMode(VaSensePin[0], OUTPUT);
  pinMode(VaSensePin[1], OUTPUT);
  pinMode(VbSensePin[0], OUTPUT);  
  pinMode(VbSensePin[1], OUTPUT);  
  pinMode(V2SourcePin,OUTPUT);
  pinMode(V2SensePin, INPUT);
 
  digitalWrite(V1SourcePin, LOW);  
  digitalWrite(V2SourcePin, LOW);
  digitalWrite(VaSensePin[0], LOW);
  digitalWrite(VaSensePin[1], LOW);
  digitalWrite(VbSensePin[0], LOW);  
  digitalWrite(VbSensePin[1], LOW); 

  dht.begin();
  
  startMeasMs = startTimeMs = millis();
  startMeasMs += (uint32_t) CYCLE_TIME_SECS * 1000;
  Serial.println("Starting...");
  Serial.println("Time    Channel 0  Red      Channel 1 Wht   Air Temp  Temp0  Temp1");
  Serial.println(" (h)       S(uS/cm)    ||     S(uS/cm)     (C)");

  //Find One-wire devices
    dev=0;
    while ((ds.search(addr)) && (dev<MAX_DEVS)) {
        memcpy(addrx[dev], addr, 8);
        Serial.print("Found device "); Serial.print(dev);
        Serial.print(" at address ");
        for( int i = 0; i < 8; i++) {
            Serial.write(' ');
            Serial.print(addrx[dev][i], HEX);
        }
        Serial.println("");
        dev++;
    }
    Serial.print("Found ");Serial.print(dev);Serial.println(" devices.");
    ds.reset_search();

}

void loop(void) {
  int i;
  float rMeasTop[2], rMeasBot[2], rMeasAvg[2];
  float ecTop[2], ecBot[2], ecAvg[2];

  byte present = 0;
  byte type_s=0;
  byte data[9];
  float celsius[MAX_DEVS];
  
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

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  //float h = dht.readHumidity();
  float h = 0.0;
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);
  float f = 0.0;
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

   for (uint8_t j=0; j<dev; j++) {
    if (OneWire::crc8(addrx[j], 7) != addrx[j][7]) {
        Serial.println("CRC is not valid!");
    }

    ds.reset();
    ds.select(addrx[j]);
    ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
    delay(1000);     // maybe 750ms is enough, maybe not
    // we might do a ds.depower() here, but the reset will take care of it.
  
    present = ds.reset();
    ds.select(addrx[j]);    
    ds.write(0xBE);         // Read Scratchpad

    for ( i = 0; i < 9; i++) {           // we need 9 bytes
        data[i] = ds.read();
    } 
    
    OneWire::crc8(data, 8);
  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
    int16_t raw = (data[1] << 8) | data[0];
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  celsius[j] = (float)raw / 16.0;

   }
     
    Serial.print(eTime, 4); Serial.print("       ");
//    Serial.print(rMeasAvg[0],2);Serial.print("     "); 
    Serial.print(ecAvg[0],2);Serial.print("       ");
//    Serial.print(rMeasAvg[1],2);Serial.print("       ");
    Serial.print(ecAvg[1],2); Serial.print("      ");
    Serial.print(t, 2); Serial.print("     ");
    Serial.print(celsius[0], 2);Serial.print("     ");
    Serial.println(celsius[1],2);
    
}

/**************************************************************************************
*                     Other Functions 
**************************************************************************************/
//************Read EC probe functions****************
float readTop(int chan){
  float dVs, dVx, rout;
  uint16_t readA, readB, NdVx;
  analogReadResolution(12);
  pinMode(VaSensePin[chan], INPUT);
  pinMode(VbSensePin[chan], INPUT);
  digitalWrite(V1SourcePin, HIGH);
  readA = analogRead(VaSensePin[chan]);
  readB = analogRead(VbSensePin[chan]);
  dVs = (float) (analogRead(V1SensePin) - analogRead(V2SensePin));
  digitalWrite(V1SourcePin, LOW);
  pinMode(VaSensePin[chan], OUTPUT);
  pinMode(VbSensePin[chan], OUTPUT);
  digitalWrite(VaSensePin[chan], LOW);
  digitalWrite(VbSensePin[chan], LOW); 
  NdVx = readA - readB;
  dVx = (float) NdVx;
  rout = R1Tot[chan] * dVx / (dVs - dVx);
  delay(1);
  return rout;
}  

float  readBot(int chan){
  float dVs, dVx, rout;
  uint16_t readA, readB, NdVx;
  analogReadResolution(12);
  pinMode(VaSensePin[chan], INPUT);
  pinMode(VbSensePin[chan], INPUT);
  digitalWrite(V2SourcePin, HIGH);
  readB = analogRead(VbSensePin[chan]);
  readA = analogRead(VaSensePin[chan]);
  dVs = (float) (analogRead(V2SensePin) - analogRead(V1SensePin));
  digitalWrite(V2SourcePin, LOW);
  pinMode(VaSensePin[chan], OUTPUT);
  pinMode(VbSensePin[chan], OUTPUT);
  digitalWrite(VaSensePin[chan], LOW);
  digitalWrite(VbSensePin[chan], LOW); 
  NdVx = readB - readA;
  dVx = (float) NdVx;
  rout = R1Tot[chan] * dVx / (dVs - dVx);
  delay(1);
  return rout;
}  
