
int contador = 0;          
char cadena[2];//cadena a leer del puerto serie (16B como maximo)

void setup(){
  Serial.begin(9600);  // configurar el puerto serie
  setup_IR(); 
}

void loop() { 
  if(Serial.available()){
    delay(5);
    while(Serial.available()){//lectura maxima de 2 caracteres -> maximo 99 botones.
       cadena[contador] = Serial.read();
       contador++;
     }
     contador = contador-2;  // solo para Arduino UNO
   
     loop_IR(cadena, contador);
     contador = 0;
     while(Serial.available())  Serial.read();
  }
 }
  
  
