#include <DS1302.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// Inicializacion del modulo.
DS1302 rtc(2, 3, 4);
Time t;

void setup() 
{
  // LCD led de fondo
  pinMode(13,OUTPUT);  // LED conectado al pin D13
  analogWrite(13, 255);  // Encendido del LED de luz de fondo.
  lcd.begin(16,2);  // Inicializacion del LCD.

 // Desproteger contra escritura
  rtc.halt(false);
  rtc.writeProtect(false);

  rtc.setDOW(SUNDAY);  // Configurar dia de la semana
  rtc.setTime(16, 16, 00);  // Configurar hora en formato 24hs con min y seg
  rtc.setDate(29, 10, 2017);  // Configurar fecha en formato dia/mes/año
}

void loop() {
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
