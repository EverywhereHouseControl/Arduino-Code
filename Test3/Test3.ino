/* This is a sketch wich tests IRControl, light control and blinds
*  in the same Arduino
*/
#include <string.h>

//  Test global variables
//char input[16];

//  Light_Control global variables
int pinRelay1 = 4;
int stateRelay1;

//***idServices***
const int service_lights = 200;
const int service_IR = 193;
const int service_blinds = 0;

//  IR_Control global variables


void setup(){
  Serial.begin(9600);  // init Serial port
  setup_LightControl(pinRelay1, &stateRelay1);
  setup_IR();
  setup_blinds();
  setup_temp(); 
}

void loop(){
  loop_IR();
  loop_temp();
  if(Serial.available()){
    delay(20);  //  necesary to wait the input to be ready
    char input[32]="";
    String command;
    String service;
    String action;
    
    int i=0;
    while(Serial.available()){
      input[i] = Serial.read();
      i++;      
    }
    Serial.flush();
    String inputS = input;
    int index = inputS.indexOf('-');
    int index2 = inputS.indexOf('-', index+1);
    command = inputS.substring(0,index);
    service = inputS.substring(index+1,index2);
    action = inputS.substring(index2+1);
    //separateInput(i, input, &service, &action);
    switch(service.toInt()){
      case service_lights:    //lights
        Serial.print(command); Serial.print("-");      
        Serial.print("LIGHTS"); Serial.print("-");
        if(command == "SEND")
          perform_LightControl(action, pinRelay1, &stateRelay1);
        else
          getLightsState();
        break;   
      case service_IR:    //tv IR
        Serial.print(command); Serial.print("-");      
        Serial.print("TV"); Serial.print("-");
        if(command == "SEND")
          IR(action);
        else
          getIRstate();
        break;
      case service_blinds:
          Serial.print(command); Serial.print("-");      
          Serial.print("BLINDS"); Serial.print("-");
          if(command == "SEND")
            action_blinds(action);
          else
            getBlindsState();
          break;
      case 2:
          Serial.print(command); Serial.print("-");
          Serial.print(service_blinds); Serial.print("-");
          if(command == "SEND")
            fijarTemperatura(action);
          else
            getTempState();
          break;
      default:
        Serial.println("-1");
        break;
    }  
    Serial.flush();//while(Serial.available()){ Serial.read(); }
    //delay(500);
  }

}

/*void separateInput(int iLength, char input[],  String *service, String *action){
  boolean found = false;
  int dashPos = 0;
  char serviceAux[16];
  char actionAux[32];
  
  
  for(int j=0; j<iLength; j++){
    if(input[j] == '-') {
      found = true;
      dashPos = j;
    }
    else{
      if (found){
        int pos = j-dashPos-1;
        actionAux[pos] = input[j];
      }
      else{
        serviceAux[j] = input[j];
      }
    }
  }
  
  serviceAux[dashPos] = '\0';
  actionAux[iLength-dashPos-1] = '\0';
  
  *service = serviceAux;
  *action = actionAux;  
}*/
