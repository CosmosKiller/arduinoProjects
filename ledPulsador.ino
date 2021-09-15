int pulsador = 2; // Puerto digital 2 - Pulsador
int led = 13; // Puerto digital 3 - Led
void setup() 
{
 pinMode(pulsador,INPUT); 
 pinMode(led,OUTPUT);
}

void loop()
{
  if (digitalRead(pulsador)==LOW) // Si el está presionado (Normal Cerrado)
  {
    digitalWrite(led,HIGH); // Led encendido
  }
  else
  {
    digitalWrite(led,LOW); // Caso contrario Led apagado
  }
}

