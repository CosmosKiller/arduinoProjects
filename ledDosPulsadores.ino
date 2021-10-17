int pulsador1 = 2; // Puerto digital 2 - Pulsador S1
int pulsador2 = 4; // Puerto digital 4 - Pulsador S2
int led = 13; // Puerto digital 3 - Led
void setup() 
{
 pinMode(pulsador1,INPUT); 
 pinMode(pulsador2,INPUT); 
 pinMode(led,OUTPUT);
}

void loop()
{
  if (digitalRead(pulsador1)==LOW && digitalRead(pulsador2)==LOW) // Si los pulsadores están presionados (Normal Cerrado)
  {
    digitalWrite(led,HIGH); // Led encendido
  }
  else
  {
    digitalWrite(led,LOW); // Caso contrario Led apagado
  }
}
