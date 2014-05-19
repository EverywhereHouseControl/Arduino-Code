const int inputPinMotion = A1;
unsigned long last_timeMotion;//last time sensor was activated in milliseconds

void setup_Motion(){
   pinMode(inputPinMotion, INPUT);
   last_timeMotion = 0;//first time is 0 ms   
}

void loop_Motion(int idDevice,int idService){
	int valueM = digitalRead(inputPinMotion);
   	if(((valueM == HIGH) && (last_timeMotion == 0 )) || ((valueM == HIGH) && (last_timeMotion+10000<millis()))){
      		Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-"); Serial.print(idService); Serial.print("-MOTION");
      		last_timeMotion = millis();
   	}
}
