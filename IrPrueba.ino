#include <IRremote.h>

#define OK 0x20DF22DD
#define VOL_DOWN 0x20DFC03F
#define VOL_UP 0x20DF40BF
#define PROG_UP 0x20DF00FF
#define PROG_DOWN 0x20DF807F
#define CERO 0x20DF08F7
#define UNO 0x20DF8877
#define DOS 0x20DF48B7
#define TRES 0x20DFC837
#define CUATRO 0x20DF28D7
#define CINCO 0x20DFA857
#define SEIS 0x20DF6897
#define SIETE 0x20DFE817
#define OCHO 0x20DF18E7
#define NUEVE 0x20DF9867
#define ON 0x20DF10EF
int i;


IRsend irsend(3);//pin usado


void setup()
{
  Serial.begin(9600);//configurar el puerto serie
  i = -1;
}

void loop() {
  if (Serial.available()) {
    i = Serial.read() - '0';//problema al leer int negativos
    Serial.println(i);
    switch(i){
      case -2 :
        irsend.sendNEC(OK,32);
        break;
      case -3 :
        irsend.sendNEC(VOL_DOWN,32);
        break;
      case -4 :
        irsend.sendNEC(VOL_UP,32);
        break;
      case -5:
        irsend.sendNEC(PROG_UP,32);
        break;
      case -6 :
        irsend.sendNEC(PROG_DOWN,32);
        break;
      case 0 :
        irsend.sendNEC(CERO,32);
        //delay(1000);
        break;
      case 1 :
        irsend.sendNEC(UNO,32);
        //delay(1000);
        break;
      case 2 :
        irsend.sendNEC(DOS,32);
        //delay(1000);
        break;
      case 3 :
        irsend.sendNEC(TRES,32);
        //delay(1000);
        break;
      case 4 :
        irsend.sendNEC(CUATRO,32);
        //delay(1000);
        break;
      case 5 :
        irsend.sendNEC(CINCO,32);
        //delay(1000);
        break;
      case 6 :
        irsend.sendNEC(SEIS,32);
        //delay(1000);
        break;
      case 7 :
        irsend.sendNEC(SIETE,32);
        //delay(1000);
        break;
      case 8 :
        irsend.sendNEC(OCHO,32);
        //delay(1000);
        break;
      case 9:
        irsend.sendNEC(NUEVE,32);
        //delay(1000);
        break;
      case -10 :
        irsend.sendNEC(ON,32);
        break;
      default:
        irsend.sendNEC(ON,32);
        break;       
    }
  }
}
