/*  this sketch simules a changeover switch behavior using two relays 
    and an external input
*/

void setup_LightControl(int pinExtInput, int pinRelay1, int pinRelay2){
  pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
}

void preparation_LightControl(int pinRelay1, int pinRelay2, int stateRelay1, int stateRelay2){
  digitalWrite(pinRelay1, HIGH);
  stateRelay1 = HIGH;
  digitalWrite(pinRelay2, LOW);
  stateRelay2 = LOW;
}

void perform_LightControl(int stateExtInput, int previousInputState, int pinExtInput, 
                          int pinRelay1, int pinRelay2, int stateRelay1, int stateRelay2,
                          long time, long debounce){
                            
  stateExtInput = digitalRead(pinExtInput);  
  if(stateExtInput == HIGH && previousInputState == LOW && millis() - time > debounce) {
    if(stateRelay1 == HIGH){
      stateRelay1 = LOW;
      stateRelay2 = HIGH;
    } else {
       stateRelay1 = HIGH; 
       stateRelay2 = LOW; 
    }
    time = millis();
  }
  digitalWrite(pinRelay1, stateRelay1);
  delay(100);
  digitalWrite(pinRelay2, stateRelay2);
  previousInputState == stateExtInput;
}

