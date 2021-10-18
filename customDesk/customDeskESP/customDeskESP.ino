/*
The source code used to recibe all of the orders given by the user via Wi-Fi, using Alexa Skills or Google Home Routines.
It then send the order to the MEGA2560 through the Serial Pins (TX/RX)
*/

#include "thingProperties.h"

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
}

void onAlexaPushValueChange()
{
  float alexaFloatValue;
  alexaFloatValue = alexaPushValue.getBrightness();
  
  int alexaIntValue;
  alexaIntValue = (int)alexaFloatValue;
  
  char j = alexaIntValue + '0';
  Serial.println(j);
}
