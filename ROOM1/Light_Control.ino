/*   this sketch simules a changeover switch behavior using one relay
      and an external input
      Returns:
         0   -->   There's no error
         1   -->   The input isn't a '0'
*/

const int pinRelay1 = 4;

int stateRelay1;

String stateLight = "OFF";

void setup_LightControl() {
   //int pinExtInput){
   // pin setup
   //pinMode(pinExtInput, INPUT);
   pinMode(pinRelay1, OUTPUT);
   digitalWrite(pinRelay1, HIGH);
   stateRelay1 = HIGH;
}

void getLightsState(){
   Serial.println(stateLight);
}

void perform_LightControl(String action) {
   //int* stateExtInput, int* previousInputState, int pinExtInput,
   //long* time, long debounce){

   if(action.toInt() == 0){
        // toggle relay state
        if(stateRelay1 == HIGH){
         stateRelay1 = LOW;
        } else {
         stateRelay1 = HIGH;
        }
        if(stateLight == "OFF")
         stateLight = "ON";
        else
         stateLight = "OFF";
        digitalWrite(pinRelay1, stateRelay1);
        //Serial.println("0");   // Respuesta OK
        // delay(500);
    }
   else{
      //Serial.println("1");   // Respuesta de error
   }
}
