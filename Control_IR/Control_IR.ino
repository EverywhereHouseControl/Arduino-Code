#include <IRremote.h>
#include <Base_IR.h>

//int contador = 0;          
//IRsend irsend;
//char cadena[1];//cadena a leer del puerto serie

void setup_IR(){
  //seconds = 0;
  //contador = 0;  
}

void loop_IR(char cadena[], int longitud, IRsend *irsend) { 
//  int i = 0;
/*   int contador = 0;
   while(Serial.available() && contador < 2){//lectura maxima de 2 caracteres -> maximo 99 botones.
       delay(5);
       cadena[contador] = Serial.read();
       contador++;
   }
   
  */ //if(contador > 0){
   if(longitud <= 2){
       int i = atoi(cadena);
       (*irsend).sendNEC(datos1[i],32);
       Serial.println("Señal Enviada");
/*       Serial.print("input : ");
       Serial.print(cadena);
       Serial.print(" --> ");
       Serial.println(datos1[i], 16);
       */
       delay(1000);
   }
   else {
       Serial.print("Entrada incorrecta");
       Serial.println(longitud);
  }
}  
  
  
  
