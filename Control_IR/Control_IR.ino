#include <IRremote.h>
#include <Base_IR.h>

int i;
int contador;          
IRsend irsend;
char cadena[1];//cadena a leer del puerto serie

void setup(){
  Serial.begin(9600);//configurar el puerto serie
  seconds = 0;
  contador = 0;  
}

void loop() { 
  i = 0;
   while(Serial.available() && contador < 2){//lectura maxima de 2 caracteres -> maximo 99 botones.
       delay(5);
       cadena[contador] = Serial.read();
       contador++;
   }
   if(contador > 0){
       i = atoi(cadena);
       irsend.sendNEC(datos1[i],32);
       delay(1000);
       contador = 0; cadena[1] = '\0';
       Serial.println("Señal Enviada");
   }
  }
