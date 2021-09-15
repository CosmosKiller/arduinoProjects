int pulsador = 2; // Puerto digital 2 - Pulsador
int motor = 3; // Puerto PWM 3 - Motor DC
boolean encendido = false; // Inicialmente motor apagado

void setup() 
{
 Serial.begin(9600); // Se inicia la consola
 pinMode(pulsador,INPUT); 
 pinMode(motor,OUTPUT);
}

void loop()
{
  if (digitalRead(pulsador)==LOW && encendido==false) // Si se oprime el pulsador y el motor está apagado...
  {
    digitalWrite(motor,HIGH); // Motor encendido
    encendido=true;
    Serial.println("Motor encendido"); 
    delay(1000);
  }
  else if (digitalRead(pulsador)==LOW && encendido==true) // Si se oprime el pulsador y el motor está encencido...
  {
    digitalWrite(motor,LOW); // Motor apagado
    encendido=false;
    Serial.println("Motor apagado");
    delay(1000);
  }
}

