int valorLDR = 0;
 
int pinLed1 = 12;
int pinLed2 = 11;
int pinLed3 = 10;
int pinLed4 = 9;
int pinLed5 = 8;

int pinLDR = A0;

void setup()
{
  pinMode (pinLed1,OUTPUT);
  pinMode (pinLed2,OUTPUT);
  pinMode (pinLed3,OUTPUT);
  pinMode (pinLed4,OUTPUT);
  pinMode (pinLed5,OUTPUT);

  analogReference(EXTERNAL);
}

void díaLdr()
{
  valorLDR = analogRead(pinLDR);
    
  if(valorLDR >= 1023)
  {
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 823) & (valorLDR < 1023))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 623) & (valorLDR < 823))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 423) & (valorLDR < 623))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else  if((valorLDR >= 223) & (valorLDR < 423))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, LOW);
  }
  else
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, HIGH);
  }
}

void tiempo

 


