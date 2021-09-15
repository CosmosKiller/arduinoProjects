int led = 13; // // Puerto digital 13 - Led
int pulsador1 = 2; // Puerto digital 2 - Pulsador S1
int pulsador2 = 4; // Puerto digital 4 - Pulsador S2
int contador = 0; // Contador inicializado en 0
boolean encendido = false; //Led no está listo para encenderse
boolean programado= false; //Rutina desprogramada 

void setup() 
{
 Serial.begin(9600);
 pinMode(pulsador1,INPUT); 
 pinMode(pulsador2,INPUT); 
 pinMode(led,OUTPUT);
}

void loop() 
{
  if (programado==false && digitalRead(pulsador1)==LOW) // Rutina desprogramada y pulsador S1 oprimido (NC)
  {
    while(digitalRead(pulsador1)==LOW)
    {
    contador += 20; // Contador incremente de 20 en 20
    Serial.println(contador);
    delay(1000);
    }
    programado = true; //Rutina programada 
    encendido = true; //Led está listo para encenderse
    Serial.println("Rutina programada");
    
  }
  
  else if (programado==true && digitalRead(pulsador2)==LOW) // Rutina programada y pulsador S2 oprimido (NC)
  {
    Serial.println("Rutina iniciada");
    while (digitalRead(pulsador2)==LOW)
    {
    digitalWrite(led,HIGH); // Led encendido
    delay(contador);
    digitalWrite(led,LOW); // Led apagado
    delay(contador);
    Serial.println(contador);
    }
    Serial.println("Rutina finalizada");
  }
  
  else if ((digitalRead(pulsador1)==LOW && digitalRead(pulsador2)==LOW) && (encendido==true && programado==true))// Rutina programada,Led listo y pulsador S1/S2 oprimidos (NC)
  {
    while ((digitalRead(pulsador1)==LOW && digitalRead(pulsador2)==LOW))
    { 
    contador=0;
    encendido = false;
    programado= false;
    digitalWrite(led,LOW);
    }
    Serial.println("Contador reiniciado");
    delay(1000);
  }
}
