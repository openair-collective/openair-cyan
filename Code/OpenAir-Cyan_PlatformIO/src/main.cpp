/**
 * @file main.cpp
 * @brief Main file for OpenAir-Cyan
 * @author OpenAir Collective
 * @author David Wilson
 * @author ZanzyTHEbar
 * @date 4/18/22
 * @version 1
 */

#include <Arduino.h>

#define NAVGS 100

struct Pins
{
  int V1SensePin;
  int V1SourcePin;
  int VreadPin;
  int V2SourcePin;
  int V2SensePin;
  float cal; // Relates measured resistance R2 to EC in uS/cm. User needs to calibrate for each sensor.
  float R1;  // Make sure to update this and recompile if R1 is changed.
  float R2;  // Measured value of lumped resistance of fluid across probe
};

Pins pins;

/**
 * @brief Setup function (FreeRTOS task)
 *
 */
void setup(void)
{

  Serial.begin(115200);

  pins = {A5, A4, A2, A1, A0, 1384000.0f, 326.8f}; // Set the pins to the pins you are using.

  while (!Serial)
  {
    delay(100);
  }

  pinMode(pins.V1SensePin, INPUT);
  pinMode(pins.VreadPin, INPUT);
  pinMode(pins.V2SensePin, INPUT);

  pinMode(pins.V1SourcePin, OUTPUT);
  pinMode(pins.V2SourcePin, OUTPUT);

  digitalWrite(pins.V1SourcePin, LOW);
  digitalWrite(pins.V2SourcePin, LOW);
}

void loop(void)
{
  int i;
  float rMeasTop, rMeasBot, rMeasAvg;
  float ecTop, ecBot, ecAvg;
  rMeasTop = 0.0f;
  rMeasBot = 0.0f;

  for (i = 0; i < NAVGS; i++)
  {
    rMeasTop += readTop();
    delay(10);
    rMeasBot += readBot();
    delay(10);
  }
  rMeasTop /= NAVGS;
  rMeasBot /= NAVGS;
  rMeasAvg = (rMeasTop + rMeasBot) / 2.0;

  ecTop = pins.cal / rMeasTop;
  ecBot = pins.cal / rMeasBot;
  ecAvg = pins.cal / rMeasAvg;

  char buffer[100];
  char buff[100];

  snprintf(buffer, sizeof(buffer), "Top: %.2f uS/cm, Bot: %.2f uS/cm, Avg: %.2f uS/cm\n", ecTop, ecBot, ecAvg);
  snprintf(buff, sizeof(buff), "R2: %.2f, EC: %.2f\n", rMeasAvg, ecAvg);

  Serial.print(buffer);
  Serial.print(buff);
}

/**************************************************************************************
 *                     Other Functions
 **************************************************************************************/

/**
 * @brief Read EC probe functions
 *
 * @return float
 */
float readTop()
{
  int i, v1, v2, vout;
  float rout;
  digitalWrite(pins.V1SourcePin, HIGH);
  // Throw away first reading
  analogRead(pins.V1SensePin);
  analogRead(pins.V2SensePin);
  analogRead(pins.VreadPin);
  v1 = analogRead(pins.V1SensePin);
  v2 = analogRead(pins.V2SensePin);
  vout = analogRead(pins.VreadPin);
  digitalWrite(pins.V1SourcePin, LOW);
  rout = pins.R1 * (float)(vout - v2) / (v1 - vout);
  return rout;
}

/**
 * @brief Read
 *
 * @return float
 */
float readBot()
{
  int i, v1, v2, vout;
  float rout;
  digitalWrite(pins.V2SourcePin, HIGH);
  // Throw away first reading
  analogRead(pins.V1SensePin);
  analogRead(pins.V2SensePin);
  analogRead(pins.VreadPin);
  v1 = analogRead(pins.V1SensePin);
  v2 = analogRead(pins.V2SensePin);
  vout = analogRead(pins.VreadPin);
  digitalWrite(pins.V2SourcePin, LOW);
  rout = pins.R1 * (float)(v2 - vout) / (vout - v1);
  return rout;
  ;
}
