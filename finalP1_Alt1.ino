int rled = 11; // Pin PWN 11 para led rojo
int bled = 9; // Pin PWM 10 para led azul
int gled = 8; // Pin PWM 9  para led verde
int p1;
int p2;
int p3;

void setup() {
  Serial.begin(9600);
  //Se inicializan pines PWM como salida
  pinMode(rled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
  analogWrite(rled, 0);
  analogWrite(bled, 0);
  analogWrite(gled, 0);
}

void loop() {
  //Colores Aleatorios
  p1=analogRead(A0);
  p2=analogRead(A1);
  p3=analogRead(A2);
  
  p1 = map(p1,0,1023,0,255);
  p2 = map(p2,0,1023,0,255);
  p3 = map(p3,0,1023,0,255);
  
  
  analogWrite(rled, p1);
  analogWrite(bled, p2);
  analogWrite(gled, p3);
  
}
