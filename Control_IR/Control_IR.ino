/* Este modulo es un test de los modulos Control_IR y Light_Control
Devuelve
  0  -->  No hay error
  1  -->  La entrada no tiene el formato "0xXXXXXXXX" donde X es un digito hexadecimal
*/

#include <IRremote.h>
#include <Base_IR.h>

void setup_IR(){ }  // no es necesario inicializar nada en este módulo

void loop_IR(char cadena[], int longitud) { 

  if(longitud == 10){
       IRsend irsend;
       irsend.sendNEC(atoi(cadena), 32);
       
       /*
       int i = atoi(cadena);
       irsend.sendNEC(datos1[i],32);
       */
       Serial.println("0");    // Respuesta OK
       
       /*
       Serial.println("Señal Enviada");
       Serial.print("input : ");
       Serial.print(cadena);
       Serial.print(" --> ");
       Serial.println(datos1[i], 16);
       */
       delay(500);
   }
   else {
       Serial.println("1");    // Respuesta de error
  }
}  
  
  
  
