int A = 8; // Pulsador 1
int B = 9; // Pulsador 2
int C = 10; // Pulsador 3
int X = 13; // Puerto digital 3 - Led

void setup()
{
  pinMode(X, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);  
}

void loop()
{
  if (digitalRead(A)==HIGH) // A sin pulsar (Normal Cerrado)
  {
    digitalWrite(X,LOW); // Caso 1
  }
  else // A pulsado
  {
    if (digitalRead(B)==LOW) // B pulsado
    {
      digitalWrite(X,HIGH); // Caso 2
    }
    else // B sin pulsar
    {
      if (digitalRead(C)==LOW) // C pulsado
      { 
        digitalWrite(X,LOW); // Caso 3
      }
      else // C sin pulsar
      {
        digitalWrite(X,LOW); // Caso 4
      }
    }
  }
}
