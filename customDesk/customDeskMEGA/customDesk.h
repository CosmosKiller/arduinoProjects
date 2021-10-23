/*
Custom library for the samrt desk project
*/

int outletControll(int outlet, int outletState)
{
  if (outletState == HIGH)
  {
    digitalWrite(outlet, LOW);
    outletState = LOW;
    Serial.println("ON");
  }
  else
  {
    digitalWrite(outlet, HIGH);
    outletState = HIGH;
    Serial.println("OFF");
  }

  return outletState;
}

void powerControll()
{
  switch (incomingValue[0])
  {
  case 1:
    outletStateArray[0] = outletControll(outletArray[0], outletStateArray[0]);
    break;
  
  case 2:
    outletStateArray[1] = outletControll(outletArray[1], outletStateArray[1]);
    break;

  case 3:
    outletStateArray[2] = outletControll(outletArray[2], outletStateArray[2]);
    break;

  case 4:
    outletStateArray[3] = outletControll(outletArray[3], outletStateArray[3]);
    break;

  case 5:
    outletStateArray[4] = outletControll(outletArray[4], outletStateArray[4]);
    break;

  case 6:
    outletStateArray[5] = outletControll(outletArray[5], outletStateArray[5]);
    break;

  case 7:
    outletStateArray[6] = outletControll(outletArray[6], outletStateArray[6]);
    break;

  case 8:
    outletStateArray[7] = outletControll(outletArray[7], outletStateArray[7]);
    break;

  case 9:
    for (int i = 0; i < oasSize; i++) 
    {
      outletStateArray[i] = HIGH;
      outletStateArray[i] = outletControll(outletArray[i], outletStateArray[i]);
    }
    break;

  case 0:
    for (int i = 0; i < oasSize; i++)
    {
      outletStateArray[i] = LOW;
      outletStateArray[i] = outletControll(outletArray[i], outletStateArray[i]);
    }
    break;
    
  default:
    break;
  }
}