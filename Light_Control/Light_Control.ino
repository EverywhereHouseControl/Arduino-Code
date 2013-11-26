/*  this sketch simules a changeover switch behavior 
    using two relays and sn external input
*/

int pinExtInput = 8;
int pinRelay1 = 2;
int pinRelay2 = 3;
int stateRelay1;
int stateRelay2;
int stateExtInput;
int previousInputStateInputState = LOW;
long time = 0;
long debounce = 500;
boolean firstTime = true;

void setup() {
  setup_LightControl(pinExtInput, pinRelay1, pinRelay2);
}

void loop() {
  //  Set up one relay to high and the other to low in the first iteration
  if(firsTime){
    preparation_LightControl(pinRelay1, pinRelay2, stateRelay1, stateRelay2);
    firsTime = false;
  }
  perform_LightControl(stateExtInput, previousInputState, pinExtInput, pinRelay1,
                          pinRelay2, stateRelay1, stateRelay2, time, debounce);
}




void setup_LightControl(int pinExtInput, int pinRelay1, int pinRelay2){
  pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
}

void preparation_LightControl(int pinRelay1, int pinRelay2, int stateRelay1, int stateRelay2){
  digitalWrite(intRelay1, HIGH);
  stateRelay1 = HIGH;
  digitalWrite(intRelay2, LOW);
  stateRelay2 = LOW;
}

void perform_LightControl(int stateExtInput, int previousInputState, int pinExtInput, 
                          int pinRelay1, int pinRelay2, int stateRelay1, int stateRelay2,
                          long time, long debounce){
                            
  stateExtInput = digitalRead(pinExtInput);  
  if(stateExtInput == HIGH && previousInputStateInputState == LOW && millis() - time > debounce) {
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

