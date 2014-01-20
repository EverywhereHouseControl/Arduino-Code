#include <IRremote.h>
#include <Base_IR.h>

void setup_IR(){ }  // no es necesario inicializar nada en este módulo

void loop_IR(char cadena[], int longitud) { 

  if(longitud <= 2){
       int i = atoi(cadena);
       IRsend irsend;
       irsend.sendNEC(datos1[i],32);
       Serial.println("Señal Enviada");
       Serial.print("input : ");
       Serial.print(cadena);
       Serial.print(" --> ");
       Serial.println(datos1[i], 16);
       
       delay(1000);
   }
   else {
       Serial.print("Entrada incorrecta");
       Serial.println(longitud);
  }
}  
  
  
  
