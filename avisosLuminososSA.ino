int led13 = 13;
int led12 = 12;
int led8 = 8;
char opcion;

void setup()
{
  Serial.begin(9600);
  pinMode(led8,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  digitalWrite(led8, LOW);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);  
}

void loop() 
{
  opcion=Serial.read();
    
  if ((opcion=='a'|| opcion=='A')) 
  {
    digitalWrite(led8, HIGH);
    digitalWrite(led12, HIGH);
    digitalWrite(led13, HIGH);
  }

  else if((opcion=='b' || opcion=='B'))
  {
    while (opcion!='a' && opcion!='c')
    {
    digitalWrite(led8, HIGH);
    digitalWrite(led12, LOW);
    digitalWrite(led13, LOW);
    delay(1000);
    digitalWrite(led8, LOW);
    digitalWrite(led12, HIGH);
    delay(1000);
    digitalWrite(led12, LOW);
    digitalWrite(led13, HIGH);
    delay(1000);
    }
  }
  
  else if ((opcion=='c'|| opcion=='C'))
  {
    digitalWrite(led8, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led13, LOW);
  }
}



