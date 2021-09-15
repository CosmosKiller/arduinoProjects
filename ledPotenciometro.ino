#define LED 13
int valor_led;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop()
{
  int valor_pot = analogRead(A0);
  valor_led=map(valor_pot,0,1023,0,255);
  analogWrite(LED, valor_led);
  Serial.println(valor_led);
  delay(100);
}
