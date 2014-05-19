const int tempPin = A0; 
const int tempPin2 = 6;
float temp;
int tempObjetivo = 0;
void setup_temp(){
    // Abre puerto serial y lo configura a 9600 bps
    //Serial.begin(9600);
    pinMode(tempPin2,OUTPUT);
}

void fijarTemperatura(String t){
  tempObjetivo = t.toInt();
  //Serial.println("Recibido temp");
}

void getTempState(){
  Serial.println(temp);
}

void loop_temp(){      
    temp = analogRead(tempPin); 
    temp = (5.0 * temp * 100)/1024.0;
    if(temp < tempObjetivo){
      digitalWrite(tempPin2,HIGH);
    }
    else{
      digitalWrite(tempPin2,LOW); 
    }
}
