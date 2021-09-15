int rele = 8 ; // Pin PWN 11 para led rojo


void setup() {
  Serial.begin(9600);
  //Se inicializan pines PWM como salida
  pinMode(rele, OUTPUT);
}

void loop() {
  //Colores Aleatorios
 digitalWrite(rele,HIGH);
  delay(5000);
  digitalWrite(rele,LOW);
  delay(5000);
  
}
