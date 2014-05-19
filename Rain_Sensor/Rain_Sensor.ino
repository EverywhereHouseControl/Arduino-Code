const int inputPinRain= 7;
unsigned long last_timeRain;//last time sensor was activated in milliseconds

void setup_Rain(){
	pinMode(inputPinRain,INPUT);
	last_timeRain = 0;
}

void loop_Rain(int idDevice,int idService){
	int valueR = digitalRead(inputPinRain);
   	if(((valueR == HIGH) && (last_timeRain == 0 )) || ((valueR == HIGH) && (last_timeRain+600000<millis()))){
      		Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-"); Serial.print(idService); Serial.print("-LLuvia");
      		last_timeRain = millis();
   	}
}

