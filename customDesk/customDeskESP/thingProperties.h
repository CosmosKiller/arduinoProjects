#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "secret.h"


const char THING_ID[] = "4a996f7f-7d03-42b1-bbaa-6501ad71d567";
const char DEVICE_LOGIN_NAME[] = "2087b08f-8bb0-4800-aee6-55a351bc3058";

const char SSID[] = SECRET_SSID;    // Network SSID (name)
const char PASS[] = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[] = SECRET_DEVICE_KEY;    // Secret device password

void onAlexaPushValueChange();

//int alexaPushValue;
CloudDimmedLight alexaPushValue;

void initProperties()
{
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(alexaPushValue, READWRITE, ON_CHANGE, onAlexaPushValueChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
