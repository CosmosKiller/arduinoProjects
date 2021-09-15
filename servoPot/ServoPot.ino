#include <Servo.h>

Servo servo;

const int srv1 = 3;
const int pot1 = A0; 


int potValue = 0;
int angl = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(srv1);
}

void loop()
{
    potValue = analogRead(pot1);
    angl = map(potValue,0,1023,0,180);
    servo.write(angl);
  
    Serial.print("Lectura del potenciometro: ");
    Serial.print(potValue);
    Serial.print(" / El valor del angulo es: ");
    Serial.println(angl);
    delay(1000);
}
