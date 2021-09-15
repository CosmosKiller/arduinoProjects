int valor_num;

void setup() 
{
  Serial.begin(9600); 
}

void loop()
{
  int valor_pot = analogRead(A0);
  valor_num=map(valor_pot,1023,0,10,0)
  Serial.println(valor_num);
  delay(100);
}
