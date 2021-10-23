/*
The source code used to manage all the I/O functionalities, reciving 
the commands from the ESP8266 via the serial pins (TX0/RX0)
It can also be used to return information such as temperature, humidity and
polution messurements
*/

#include <DHT.h>
#include "customDesk.h"

//Defining and initiating the DHT22 Sensor
#define DHTPIN 39
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

//Defining pins for the outlets
const int outletArray[] = {37, 35, 33, 31, 29, 27, 25, 23};
int oaSize = sizeof(outletArray) / sizeof(outletArray[0]);

//Initializing the outlet states
int outletStateArray[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int oasSize = sizeof(outletStateArray) / sizeof(outletStateArray[0]);

//Defining RGB Led pins 
const int rgbLed[] = {4, 3, 2};

//Variables
float humudity, temperature;
int incomingValue[4] = {0};
bool valueComplete = false;

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  dht.begin();

  for (int i = 0; i < oaSize; i++)
  {
    pinMode(outletArray[i], OUTPUT);
  }
  
  for (int i = 0; i < oaSize; i++)
  {
    digitalWrite(outletArray[i], HIGH);
  }

  analogWrite(rgbLed[0], 0);
  analogWrite(rgbLed[1], 0);
  analogWrite(rgbLed[2], 0);  
}

void loop()
{ 
  humudity = dht.readHumidity();
  temperature = dht.readTemperature();

  if (valueComplete)
  {
    if (incomingValue[0] < 10)
    {
      powerControll();
    }
    else if (incomingValue[0] < 20 && incomingValue[0] >= 10)
    {
      analogWrite(rgbLed[0], incomingValue[1]);
      analogWrite(rgbLed[1], incomingValue[2]);
      analogWrite(rgbLed[2], incomingValue[3]);
    }
    else
    {
      int returnValue = (int)temperature;
      Serial1.write(returnValue);
      Serial.println(returnValue);
    }
  }
  incomingValue[4] = {0};
  valueComplete = false;
}

void serialEvent1()
{ 
    int i = 0;
    while (i < 4)
    {
      if (Serial1.available())
      {
      incomingValue[i] = Serial1.read();
      Serial.print(i, DEC);
      Serial.println(incomingValue[i]);
      i++;
      }
    }
    valueComplete = true; 
}
