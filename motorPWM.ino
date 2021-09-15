int motor = 3; // Puerto PWM 3 - Motor DC
int valor_motor;

void setup() 
{
  Serial.begin(9600),
  pinMode(motor,OUTPUT);
}

void loop()
{
  int valor_pot = analogRead(A0);
  valor_motor=map(valor_pot,0,1023,0,255);
  analogWrite(motor, valor_motor);
  Serial.println(valor_motor);
  delay(100);
}
