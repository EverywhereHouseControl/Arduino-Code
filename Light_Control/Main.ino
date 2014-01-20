//long time = 0;
//long debounce = 500;

//int pinExtInput = 8;
//int pinRelay2 = 2;
//int stateRelay2;
//int stateExtInput;
//int previousInputState = LOW;

int pinRelay1 = 4;
int stateRelay1;
char input[16];

void setup() {
  // init the serial port
  Serial.begin(9600);
  setup_LightControl(pinRelay1, &stateRelay1);
                      //pinExtInput);
}

void loop() {  
  // read from the serial port if it's possible
  if(Serial.available()){
    delay(20);  //  necesary to wait the input to be ready
    int i=0;
    while(Serial.available()){
      input[i] = Serial.read();
      i++;
    }
    i=i-2;  //  solo para arduino UNO
    
    perform_LightControl(input, i, pinRelay1, &stateRelay1); 
                         //&stateExtInput, &previousInputState, 
                         //pinExtInput, &time, debounce);             
      
      while(Serial.available()){ Serial.read(); }
    }
}



