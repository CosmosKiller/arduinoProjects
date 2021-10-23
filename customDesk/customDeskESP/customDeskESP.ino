/*
The source code used to recibe all of the orders given by the user via Wi-Fi, using Alexa Skills or Google Home Routines.
It then send the order to the MEGA2560 through the Serial Pins (TX/RX)
*/

#include "thingProperties.h"

int tempValue = 0;

void setup()
{
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  ArduinoCloud.update();
  onAlexaDHTValuechange();
}

void onAlexaDHTValuechange()
{
  int sendValue[] = {20, 0, 0, 0}; 

  for (int i = 0; i < 4; i++)
  {
    Serial.write(sendValue[i]);
  }
  if (Serial.available())
  {
    tempValue = Serial.read();
  }

  alexaDHTValue = (float)tempValue;
  delay(200);
}

void onAlexaPushValueChange()
{
  //Read the incoming value sended by Alexa
  float alexaFloatValue = alexaPushValue.getBrightness();
  
  //Converting float into int
  int sendValue[] = {(int)alexaFloatValue, 0, 0, 0};
    
  for (int i = 0; i < 4; i++)
  {
    Serial.write(sendValue[i]);
  } 
}

void onAlexaRGBValueChange()
{
  if (alexaRGBValue.getSwitch())
  {
    //Read brightness value from Alexa
    float rgbBrightness = alexaRGBValue.getBrightness();

    //Read RGB valuves from Alexa
    uint8_t r, g, b ;
    alexaRGBValue.getValue().getRGB(r, g, b);

    //Convert values to int
    int sendValue[] = {10, (int)r, (int)g, (int)b}; 

    for (int i = 0; i < 4; i++)
    {
      Serial.write(sendValue[i]);
    } 
  }
  else
  {
    int sendValue[] = {10, 0, 0, 0}; 

    for (int i = 0; i < 4; i++)
    {
      Serial.write(sendValue[i]);
    } 
  }
}
