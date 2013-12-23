/*  this sketch simules a changeover switch behavior using two relays 
    and an external input
*/

void setup_LightControl(int pinExtInput, int pinRelay1, int pinRelay2, int* stateRelay1, int* stateRelay2){
  // pin setup
  pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
  
  // is necessary to ensure that the relays have different states
  digitalWrite(pinRelay1, HIGH);
  *stateRelay1 = HIGH;
  digitalWrite(pinRelay2, LOW);
  *stateRelay2 = LOW;
  
  // init the serial port
  Serial.begin(9600);
}

void perform_LightControl(int* stateExtInput, int* previousInputState, int pinExtInput, 
                          int pinRelay1, int pinRelay2, int* stateRelay1, int* stateRelay2,
                          long* time, long debounce){
  
  char* input;
  
  // read from the serial port if it's possible
  if(Serial.available()){
    *input = Serial.read();
    
    if(*input == '0'){
    // toggle relay states
      if(*stateRelay1 == HIGH){
        *stateRelay1 = LOW;
        *stateRelay2 = HIGH;
        Serial.println("cambio 1");
        //Serial.println(*input);
      } else {
        *stateRelay1 = HIGH; 
        *stateRelay2 = LOW; 
        Serial.println("cambio 2");
        //Serial.println(*input);
      }
      digitalWrite(pinRelay1, *stateRelay1);
      delay(10);
      digitalWrite(pinRelay2, *stateRelay2);
      delay(1000);
    } 
    Serial.flush();
  }
  
  /*            
  *stateExtInput = digitalRead(pinExtInput);  
  // only serve requests with a lag to avoid rebound
  if(*stateExtInput == HIGH && *previousInputState == LOW && (millis() - *time > debounce)) {
    if(*stateRelay1 == HIGH){
      *stateRelay1 = LOW;
      *stateRelay2 = HIGH;
    } else {
      *stateRelay1 = HIGH; 
      *stateRelay2 = LOW; 
    }
    *time = millis();
  }
  digitalWrite(pinRelay1, *stateRelay1);
  digitalWrite(pinRelay2, *stateRelay2);
  *previousInputState == *stateExtInput;
  */
}

