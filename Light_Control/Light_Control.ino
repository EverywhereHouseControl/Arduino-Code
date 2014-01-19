/*  this sketch simules a changeover switch behavior using on relay
    and an external input
*/

void setup_LightControl(int pinExtInput, int pinRelay1, int* stateRelay1){
  // pin setup
  //pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
 
  digitalWrite(pinRelay1, HIGH);
  *stateRelay1 = HIGH;
  
  
  // init the serial port
  Serial.begin(9600);
}

void perform_LightControl(int* stateExtInput, int* previousInputState, int pinExtInput, 
                          int pinRelay1, int* stateRelay1,
                          long* time, long debounce){
  
  char input[2];
  
  // read from the serial port if it's possible
  if(Serial.available()){
    int i=0;
    while(Serial.available()>0 && i<2){
      input[i] = Serial.read();
      i++;
    }
    
    if((input[0] == '0') && (i == 1)){
    // toggle relay state
      if(*stateRelay1 == HIGH){
        *stateRelay1 = LOW;
      } else {
        *stateRelay1 = HIGH; 
      }
      digitalWrite(pinRelay1, *stateRelay1);
      Serial.println("fin de bucle");
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
    } else {
      *stateRelay1 = HIGH; 
    }
    *time = millis();
  }
  digitalWrite(pinRelay1, *stateRelay1);
  *previousInputState == *stateExtInput;
  */
      
}

