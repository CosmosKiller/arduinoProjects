/*
The source code used to manage all the I/O functionalities, reciving the commands from the ESP8266 via the serial pins (TX0/RX0)
*/

#include <stdio.h>
#include <DHT.h>

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

int outletControll(int outlet, int outletState)
{
  if (outletState == HIGH)
  {
    digitalWrite(outlet, LOW);
    outletState = LOW;
  }
  else
  {
    digitalWrite(outlet, HIGH);
    outletState = HIGH;
  }

  return outletState;
}

void setup()
{
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

  int incomingInt;
  if (Serial.available() > 0)
  {
    incomingInt = Serial.read();
    delay(500);
  }

  if (incomingInt >= 'A')
  {
    switch (incomingInt)
    {
    case 'w':
      analogWrite(rgbLed[0], 255);
      analogWrite(rgbLed[1], 255);
      analogWrite(rgbLed[2], 255);
      break;  

    case 'r':
      analogWrite(rgbLed[0], 255);
      analogWrite(rgbLed[1], 0);
      analogWrite(rgbLed[2], 0);
      break;

    case 'g':
      analogWrite(rgbLed[0], 0);
      analogWrite(rgbLed[1], 255);
      analogWrite(rgbLed[2], 0);
      break;

    case 'b':
      analogWrite(rgbLed[0], 0);
      analogWrite(rgbLed[1], 0);
      analogWrite(rgbLed[2], 255);
      break;

    case 's':
      analogWrite(rgbLed[0], 0);
      analogWrite(rgbLed[1], 0);
      analogWrite(rgbLed[2], 0);
      break;      
    
    case 't':
      Serial.print("La temperatura es de ");
      Serial.print(temperature, 2);
      Serial.println(" °C");
      Serial.print("La humedad relativa es del ");
      Serial.print(humudity, 2);
      Serial.println("%");
      break;

    default:
      break;
    }
  }
  else
  {
    switch (incomingInt)
    {
    case '1':
      outletStateArray[0] = outletControll(outletArray[0], outletStateArray[0]);
      break;
    
    case '2':
      outletStateArray[1] = outletControll(outletArray[1], outletStateArray[1]);
      break;

    case '3':
      outletStateArray[2] = outletControll(outletArray[2], outletStateArray[2]);
      break;

    case '4':
      outletStateArray[3] = outletControll(outletArray[3], outletStateArray[3]);
      break;

    case '5':
      outletStateArray[4] = outletControll(outletArray[4], outletStateArray[4]);
      break;

    case '6':
      outletStateArray[5] = outletControll(outletArray[5], outletStateArray[5]);
      break;

    case '7':
      outletStateArray[6] = outletControll(outletArray[6], outletStateArray[6]);
      break;

    case '8':
      outletStateArray[7] = outletControll(outletArray[7], outletStateArray[7]);
      break;

    case '9':
      for (int i = 0; i < oasSize; i++)
      {
        outletStateArray[i] = HIGH;
      }
      
      for (int i = 0; i < oasSize; i++)
      {
        outletStateArray[i] = outletControll(outletArray[i], outletStateArray[i]);
      }

    default:
      break;
    }
  }
}
