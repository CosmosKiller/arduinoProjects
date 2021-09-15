int pulsador1 = 2; // Puerto digital 2 - Pulsador S1
int pulsador2 = 4; // Puerto digital 4 - Pulsador S2
int led = 13; // Puerto digital 3 - Led
void setup() 
{
 pinMode(pulsador1,INPUT); 
 pinMode(pulsador2,INPUT); 
 pinMode(led,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
int estado1=digitalRead(pulsador1);
int estado2=digitalRead(pulsador2);

if (estado1==LOW) // Normal Cerrado
{
  Serial.println("Gaseosa llena");
}

if (estado2==LOW) // Normal Cerrado
{
  Serial.println("Gaseosa tapada");
}
 
  if (digitalRead(pulsador1)==LOW && digitalRead(pulsador2)==LOW) // Si los pulsadores están presionados (Normal Cerrado)
  {
    digitalWrite(led,HIGH); // Led encendido
    Serial.println("Gaseosa bien empacada");
  }
  else
  {
    digitalWrite(led,LOW); // Caso contrario Led apagado
  }
delay(1000);
}
