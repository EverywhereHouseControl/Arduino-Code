/*  this sketch simules a changeover switch behavior using one relay
    and an external input
    Returns:
      0  -->  There's no error
      1  -->  The input isn't a '0'
*/
String estado = "OFF";

int pinRelay1 = 4;
int pinSensor1 = 7;
int pinSensor2 = 8;

int stateRelay1;
int sensorState1 = LOW;
int sensorState2 = HIGH;

void setup_LightControl(){
                          //int pinExtInput){
  // pin setup
  //pinMode(pinExtInput, INPUT);
  pinMode(pinRelay1, OUTPUT);
 
  digitalWrite(pinRelay1, HIGH);
  stateRelay1 = HIGH;
}

void getLightsState(){
  Serial.println(estado);
}

void perform_LightControl(String action){
                          //int* stateExtInput, int* previousInputState, int pinExtInput, 
                          //long* time, long debounce){
    
  if(action.toInt() == 0){
  // toggle relay state
    if(stateRelay1 == HIGH){
      stateRelay1 = LOW;
    } else {
      stateRelay1 = HIGH; 
    }
    if(estado == "OFF")
      estado = "ON";
    else
      estado = "OFF";
    digitalWrite(pinRelay1, stateRelay1);
    //Serial.println("0");  // Respuesta OK
    delay(500);
  }
  else{   
    //Serial.println("1");  // Respuesta de error
  }      
}

void loop_LightControl(){

  
  //if(digitalRead(pinSensor2)  == HIGH)  Serial.println("Conduce");
//  Serial.println(analogRead(A0));
  int currentSensorState1 = digitalRead(pinSensor1);
  int currentSensorState2 = digitalRead(pinSensor2);

  if((currentSensorState1 == LOW) && sensorState1 == HIGH) || (currentSensorState1 == HIGH) && sensorState1 == LOW)){
    Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");
    Serial.print(service_lights); Serial.print("-");Serial.print(estado);
    
    if(estado == "OFF")
      estado = "ON";
    else
      estado = "OFF";
  }

  if((currentSensorState2 == LOW) && sensorState2 == HIGH) || (currentSensorState2 == HIGH) && sensorState2 == LOW)){
    Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");
    Serial.print(service_lights); Serial.print("-");Serial.print(estado);
    
    if(estado == "OFF")
      estado = "ON";
    else
      estado = "OFF";
  }


}
