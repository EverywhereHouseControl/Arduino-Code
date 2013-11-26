int pinExtInput = 8;
int pinRelay1 = 2;
int pinRelay2 = 3;
int stateRelay1;
int stateRelay2;
int stateExtInput;
int previousInputState = LOW;
long time = 0;
long debounce = 500;
boolean firstTime = true;

void setup() {
  setup_LightControl(pinExtInput, pinRelay1, pinRelay2);
}

void loop() {
  
  if(firstTime){
    preparation_LightControl(pinRelay1, pinRelay2, stateRelay1, stateRelay2);
    firstTime = false;
  }
  perform_LightControl(stateExtInput, previousInputState, pinExtInput, pinRelay1,
                          pinRelay2, stateRelay1, stateRelay2, time, debounce);
                          
}


