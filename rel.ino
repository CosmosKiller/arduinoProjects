int rele = 8 ; // Pin Relé
int Status = LOW ;
int val = 1;

void setup() {
  Serial.begin(9600);
  //Se inicializan pines PWM como salida
  pinMode(rele, OUTPUT);
 
}

void loop() {
  //
   while (Serial.available() == 0);

  val= Serial.read()-48;

 if (val == 1 && Status==LOW ) // Caso 1
 {
    Status=HIGH;
    Serial.println("Se encendió la luz");
 }
 
  else if (val == 1  && Status == HIGH) // Caso 2
 {
     Serial.println("La luz ya está encendida");
 }
 
 else if (val == 0 && Status == HIGH) // Caso 3
 {
    Status = LOW ;
    Serial.println("Se apagó la luz");
 }
 
  else if (val == 0  && Status == LOW) //
 {
     Serial.println("La luz ya está apagada");
 }

 else
 {
  Serial.println("No se reconoce comando");
 }

 if (Status == HIGH)
 {
  digitalWrite(rele, HIGH);
  digitalWrite(13, HIGH);
 }
 else
 {
  digitalWrite(rele, LOW);
  digitalWrite(13, LOW);
 }

}
