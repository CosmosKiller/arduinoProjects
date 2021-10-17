/*
The source code used to recibe all of the orders given by the user via Wi-Fi, using Alexa Skills or Google Home Routines.
It then send the order to the MEGA2560 through the Serial Pins (TX/RX)
*/

#include "thingProperties.h"

const uint8_t outletPin1 = 16;
const uint8_t outletPin2 = 5;
const uint8_t outletPin3 = 4;
const uint8_t outletPin4 = 0;
const uint8_t outletPin5 = 2;
/*
  const uint8_t outletPin6 = 14;
  const uint8_t outletPin7 = 12;
  const uint8_t outletPin8 = 13;
*/

void outletControll(int outletPin, bool outletBool)
{
  if (outletBool)
  {
    digitalWrite(outletPin, LOW);
  }
  else
  {
    digitalWrite(outletPin, HIGH);
  }
}

void setup()
{
  // Initialize serial and wait for port to open:
  Serial.begin(19200);
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
  
  pinMode(outlet1, OUTPUT);
  pinMode(outlet2, OUTPUT);
  pinMode(outlet3, OUTPUT);
  pinMode(outlet4, OUTPUT);
  pinMode(outlet5, OUTPUT);
  
  digitalWrite(outlet1, HIGH);
  digitalWrite(outlet2, HIGH);
  digitalWrite(outlet3, HIGH);
  digitalWrite(outlet4, HIGH);
  digitalWrite(outlet5, HIGH);
}

void loop()
{
  ArduinoCloud.update();
}

void onOutlet1Change()
{
  outletControll(outletPin1, outlet1);
}

void onOutlet2Change()
{
  outletControll(outletPin2, outlet2);
}

void onOutlet3Change()
{
  outletControll(outletPin3, outlet3);
}

void onOutlet4Change()
{
  outletControll(outletPin4, outlet4);
}

void onOutlet5Change()
{
  outletControll(outletPin5, outlet5);
}