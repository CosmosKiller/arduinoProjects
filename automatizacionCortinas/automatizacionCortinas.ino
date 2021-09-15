#include <Ds1302.h>
#include <LiquidCrystal_I2C.h>

DS1302 rtc(2,3,4);
LiquidCrystal_I2C lcd();
Time t;

int valorLDR = 0;
 
int pinLed1 = 12;
int pinLed2 = 11;
int pinLed3 = 10;
int pinLed4 = 9;
int pinLed5 = 8;

int pinLDR = A0;

void setup()
{
  Serial.begin(9600); //Inicia Com. Serial (Velocidad)
  lcd.begin(16,2);  // Inicializacion del LCD.
  
  // Desproteger contra escritura
  rtc.halt(false);
  rtc.writeProtect(false);

  //rtc.setDOW(SUNDAY);  // Configurar dia de la semana
  //rtc.setTime(12, 07, 00);  // Configurar hora en formato 24hs con min y seg
  //rtc.setDate(07, 01, 2018 );  // Configurar fecha en formato dia/mes/año
   
  pinMode (pinLed1,OUTPUT);
  pinMode (pinLed2,OUTPUT);
  pinMode (pinLed3,OUTPUT);
  pinMode (pinLed4,OUTPUT);
  pinMode (pinLed5,OUTPUT);

  analogReference(EXTERNAL);
}

void diaLdr()
{
  valorLDR = analogRead(pinLDR);
    
  if(valorLDR >= 1023)
  {
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 823) & (valorLDR < 1023))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 623) & (valorLDR < 823))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if((valorLDR >= 423) & (valorLDR < 623))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else  if((valorLDR >= 223) & (valorLDR < 423))
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, LOW);
  }
  else
  {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, HIGH);
  }
}

void tiempo ()
{
  // Obtencion de datos
  t = rtc.getTime();
  
  // Publicar en LCD
  // Se publicara el dia de la semana
  lcd.print("HOY:");  
  if (t.dow == 1) lcd.print("Lun");  // La variable t.dow (dia de la semana) tedra valor de 1 para dia lunes y 7 para domingo.
  if (t.dow == 2) lcd.print("Mar");
  if (t.dow == 3) lcd.print("Mie");
  if (t.dow == 4) lcd.print("Jue");
  if (t.dow == 5) lcd.print("Vie");
  if (t.dow == 6) lcd.print("Sab");
  if (t.dow == 7) lcd.print("Dom");
  
  // Se publicaran datos de fecha, en numeros.
  lcd.print(", DIA:");
  lcd.print(t.date, DEC);  // Dia del mes.
  lcd.setCursor(0,1);
  lcd.print("MES:");  // Mes.
  lcd.print(t.mon);
  lcd.print(", DE:");
  lcd.print(t.year, DEC);  // Año.
  delay(3000);  // Demora para presentar los datos en pantalla.
  lcd.clear();
  
  // Se publicara la hora
  lcd.print("HORA:");
  lcd.print(t.hour, DEC);  // Hora en formato 0-23.
  lcd.print(", MIN:");
  lcd.print(t.min, DEC);  // Minutos.
  lcd.setCursor(0,1);
  lcd.print("SEG:");
  lcd.print(t.sec, DEC);  // Segundos.
  delay(3000);  // Demora para presentar los datos en pantalla.
  lcd.clear();
}

void loop ()
{
  t = rtc.getTime();
  tiempo();
   if( t.hour>=16  &&  t.hour<17 )
   {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, HIGH);
   }
   else
   {
    diaLdr();
   }
  Serial.println(valorLDR);
  delay(1000);
}


