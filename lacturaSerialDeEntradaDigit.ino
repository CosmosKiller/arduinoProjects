int boton=2;
void setup()
{
pinMode(boton,INPUT);
Serial.begin(9600);
}
void loop()
{
int estado=digitalRead(boton);

if (estado==0) // Normal Cerrado
{
  Serial.println("Pulsado");
}
else
{
  Serial.println("NO Pulsado");
}
delay(100);
} 
