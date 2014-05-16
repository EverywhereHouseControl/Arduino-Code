const int inputPin= 8;
unsigned long last_time;//last time sensor was activated in milliseconds

void setup_Motion(){
   pinMode(inputPin, INPUT);
   last_time = 0;//first time is 0 ms
   
}

void loop_Motion(int idDevice,idService){
	int value= digitalRead(inputPin);
   	if (((value==HIGH) && (last_time==0 )) || ((value==HIGH) && (last_time+10000<millis()))) {
      		Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-"); Serial.print(idService); Serial.print("-Movimiento");
      		last_time=millis();
   }
}
