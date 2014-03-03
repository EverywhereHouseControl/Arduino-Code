/*  this sketch simules a changeover switch behavior using one relay
    and an external input
    Returns:
      0  -->  There's no error
      1  -->  The input isn't a '0'
*/

void setup_LightControl(int pinRelay1, int* stateRelay1){
                          //int pinExtInput){
  // pin setup
  //pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
 
  digitalWrite(pinRelay1, HIGH);
  *stateRelay1 = HIGH;
}

void perform_LightControl(char input[], int longitud, int pinRelay1, int *stateRelay1){
                          //int* stateExtInput, int* previousInputState, int pinExtInput, 
                          //long* time, long debounce){
    
  if((input[0] == '0') && (longitud == 1)){
  // toggle relay state
    if(*stateRelay1 == HIGH){
      *stateRelay1 = LOW;
    } else {
      *stateRelay1 = HIGH; 
    }
    digitalWrite(pinRelay1, *stateRelay1);
    Serial.println("0");  // Respuesta OK
    delay(500);
  }
  else{   
    Serial.println("1");  // Respuesta de error
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

