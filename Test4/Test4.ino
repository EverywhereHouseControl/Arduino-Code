/* This is a sketch wich tests IRControl, light control, blinds, temperature and Intercom
*  in the same Arduino
*/
#include <string.h>

//  Test global variables
//char input[16];

//  Light_Control global variables
int pinRelay1 = 4;
int stateRelay1;

// BlindSensors global variables
int stateBlindSensors = 0; // 0 = bottom; 1 = medium; 2 = up

//***idDevice***
const int idDevice = 46;

//***idServices***
const int service_lights = 200;
const int service_IR = 193;
const int service_blinds = 0;
const int service_temp = 2;
const int service_blindSensors = 999; //Need new code
const int service_lightSensor = 999; //Need new code


void setup(){
  Serial.begin(9600);  // init Serial port
  setup_LightControl(pinRelay1, &stateRelay1);
  setup_IR();
  setup_blinds();
  setup_temp(); 
  setup_blindSensors(&stateBlindSensors)
}

void loop(){
  loop_IR();
  loop_temp();
  loop_Intercom();
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
        if(command == "SEND")
          perform_LightControl(action, pinRelay1, &stateRelay1);
	Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");
        Serial.print(service_lights); Serial.print("-");
        getLightsState();
        break;   
      case service_IR:    //tv IR
        if(command == "SEND")
          IR(action);
        Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");      
        Serial.print(service_IR); Serial.print("-");
        getIRstate();
        break;
      case service_blinds: //Without sensors
        if(command == "SEND")
		action_blinds(action);
	Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");      
        Serial.print(service_blinds); Serial.print("-");
        getBlindsState();
        break;
      case service_blindSensors: //With sensors
        if(command == "SEND")
		action_blindSensors(action, &stateBlindSensors);
	Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");      
        Serial.print(service_blindSensor); Serial.print("-");
        getBlindSensorsState();
        break;
      case service_lightSensor:
        if(command == "SEND")
		action_lightSensor(action);
	Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");      
        Serial.print(service_blinds); Serial.print("-");
        getLightSensorState();
        break;
      case service_temp:
      	if(command == "SEND")
        	fijarTemperatura(action);
	Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");
        Serial.print(service_temp); Serial.print("-"); 
        getTempState();
        break;
      default:
        Serial.println("ERROR");
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
