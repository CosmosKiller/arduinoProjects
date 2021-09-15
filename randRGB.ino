int rled = 3; // Pin PWN 3 para led rojo
int bled = 5; // Pin PWM 5 para led azul
int gled = 6; // Pin PWM 6  para led verde

int potPin = A0;
int potValue = 0;

int randColor1 = 0;
int randColor2 = 0;
int randColor3 = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  randColor1 = random(0,256);
  randColor2 = random(0,256); // Valores aleatorios de 0 a 255
  randColor3 = random(0,256);
 
  potValue = analogRead(potPin);
  
  analogWrite(rled, randColor1);
  analogWrite(bled, randColor2);
  analogWrite(gled, randColor3);
  
  delay(potValue); 
}
