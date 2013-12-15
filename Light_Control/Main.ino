long time = 0;
long debounce = 500;

int pinExtInput = 8;
int pinRelay1 = 5;
int pinRelay2 = 3;
int stateRelay1;
int stateRelay2;
int stateExtInput;
int previousInputState = LOW;

void setup() {
  setup_LightControl(pinExtInput, pinRelay1, pinRelay2, &stateRelay1, &stateRelay2);
}

void loop() {  
  perform_LightControl(&stateExtInput, &previousInputState, pinExtInput, pinRelay1,
                          pinRelay2, &stateRelay1, &stateRelay2, &time, debounce);             
}


