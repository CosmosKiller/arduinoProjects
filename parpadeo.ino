int led13 = 13;
int led12 = 12;
int led8 = 8;

void setup()
{
  pinMode(led8,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
}

void loop() 
{
 digitalWrite(led8, HIGH);
 digitalWrite(led12, LOW);
 digitalWrite(led13, LOW);
 delay(2000);
 digitalWrite(led8, LOW);
 digitalWrite(led12, HIGH);
 delay(2000);
 digitalWrite(led12, LOW);
 digitalWrite(led13, HIGH);
 delay(2000);
}
