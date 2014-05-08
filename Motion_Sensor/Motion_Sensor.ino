const int ledPin= 13;
const int inputPin= 8;
unsigned long last_time;//last time sensor was activated in milliseconds

void setup(){
   pinMode(ledPin, OUTPUT);
   pinMode(inputPin, INPUT);
   Serial.begin(9600);
   last_time = 0;//first time is 0 ms
   
}

void loop(){

   int value= digitalRead(inputPin);
   
   if (((value==HIGH) && (last_time==0 )) || ((value==HIGH) && (last_time+10000<millis()))) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      Serial.println("ON");
      delay(100);
      last_time=millis();
   }
  //arduino sends "ON" to rasp when sensor is activated and has happened 10 seconds from last activation.

}
