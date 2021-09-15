
// DS1302:  RST pin    -> Arduino Digital 2
//          DATA pin   -> Arduino Digital 3
#include <Ds1302.h>

// Inicializacion del modulo
DS1302 rtc(2, 3, 4);
Time t;

void setup()
{
  // Desproteger contra escritura
  rtc.halt(false);
  rtc.writeProtect(false);

  rtc.setDOW(SUNDAY);  // Configurar dia de la semana: MARTES.
  rtc.setTime(16, 16, 00);  // Configurar hora en formato 24hs con min y seg: 17:00:00 HORAS.
  rtc.setDate(29, 10, 2017);  // Configurar fecha en formato dia/mes/año: 4/3/2014.
}

void loop(){
  digitalWrite(13,HIGH);  // El led integrado confirmara la finalizacion.
}
