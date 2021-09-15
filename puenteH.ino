int motor1 = 6; // Puerto PMW 6 - Motor DC giro Izquierdo
int motor2 = 5; // Puerto PMW 5 - Motor DC giro Derecho
char programa; // Variable para seleccionar programa de lavado

void setup ()
{
  Serial.begin(9600); // Se inicializa la consola
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
}

void loop()
{
   programa = Serial.read();
   {
    if ((programa=='d' || programa=='D'))
    {
      Serial.println("Programa D");
      digitalWrite(motor2,HIGH);
      delay(3000);
      digitalWrite(motor2,LOW);
      delay(1000);
    }
    else if ((programa=='i' || programa=='I'))
    {
      Serial.println("Programa I");
      digitalWrite(motor1,HIGH);
      delay(2000);
      digitalWrite(motor1,LOW);
      delay(1000);
    }
    else if ((programa=='a' || programa=='A'))
    {
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,LOW);
      Serial.println("Lavadora apagada");
    }
  }
}

