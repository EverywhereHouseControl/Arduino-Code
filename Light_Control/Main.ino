long time = 0;
long debounce = 500;

int pinExtInput = 8;
int pinRelay1 = 4;
int pinRelay2 = 2;
int stateRelay1;
int stateRelay2;
int stateExtInput;
int previousInputState = LOW;

void setup() {
  setup_LightControl(pinExtInput, pinRelay1, &stateRelay1);
}

void loop() {  
  perform_LightControl(&stateExtInput, &previousInputState, pinExtInput, pinRelay1,
                          &stateRelay1, &time, debounce);             
}


