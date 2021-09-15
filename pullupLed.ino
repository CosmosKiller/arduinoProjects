const int led1 = 13;
const int btn1 = 12; 

void setup() 
{
  pinMode(btn1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  if(digitalRead(btn1) == LOW)
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);
}
