const int ledPin= 13;
const int inputPin= 8;
int state;

void setup(){
   pinMode(ledPin, OUTPUT);
   pinMode(inputPin, INPUT);
   Serial.begin(9600);
   state = LOW;
}

void loop(){

   int value= digitalRead(inputPin);
   
   if (value == HIGH && state == LOW){
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      Serial.println("100");
      delay(100);
	  state = HIGH;
   }
   else{
      state = LOW;
   }

}

