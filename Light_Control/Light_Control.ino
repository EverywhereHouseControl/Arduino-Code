/*  this sketch simules a changeover switch behavior using one relay
    and an external input
    Returns:
      0  -->  There's no error
      1  -->  The input isn't a '0'
*/
String estado = "OFF";

void setup_LightControl(int pinRelay1, int* stateRelay1){
                          //int pinExtInput){
  // pin setup
  //pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
 
  digitalWrite(pinRelay1, HIGH);
  *stateRelay1 = HIGH;
}

void getLightsState(){
  Serial.println(estado);
}

void perform_LightControl(String action, int pinRelay1, int *stateRelay1){
                          //int* stateExtInput, int* previousInputState, int pinExtInput, 
                          //long* time, long debounce){
    
  if(action.toInt() == 0){
  // toggle relay state
    if(*stateRelay1 == HIGH){
      *stateRelay1 = LOW;
    } else {
      *stateRelay1 = HIGH; 
    }
    if(estado == "OFF")
      estado = "ON";
    else
      estado = "OFF";
    digitalWrite(pinRelay1, *stateRelay1);
    //Serial.println("0");  // Respuesta OK
    delay(500);
  }
  else{   
    //Serial.println("1");  // Respuesta de error
  }      
}
