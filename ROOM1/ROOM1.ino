//ROOM1

#include <string.h>

//***idDevice***
const int idDevice = 50;

//***idServices***
const int service_IR = 204;
const int service_lights = 218;
const int service_blinds = 209;


void setup(){
	Serial.begin(9600);
	setup_IR();
	setup_LightControl();
	setup_blindSensors();
}

void loop(){
	loop_IR(idDevice,service_IR);
	//loop_LightControl(idDevice,service_lights);
	//loop_blinds(idDevice,service_blinds);
        manualControlCheck_blindSensors();
	if(Serial.available()){
		delay(50);
    		char input[32]="";
    		String command;
		String device;
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
		int index3 = inputS.indexOf('-',index2+1);
    		command = inputS.substring(0,index);
    		device = inputS.substring(index+1,index2);
    		service = inputS.substring(index2+1,index3);
		action = inputS.substring(index3+1);
		if(device.toInt() == idDevice){
    			switch(service.toInt()){
				case service_IR:    //IR
        				if(command == "SEND")
          					IR(action);
					Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_IR); Serial.print("-");
        				getIRstate();
        				break;
				case service_lights:    //lights
        				if(command == "SEND")
          					perform_LightControl(action);
					Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_lights); Serial.print("-");
        				getLightsState();
        				break;
				case service_blinds: //blinds
        				if(command == "SEND")
						action_blindSensors(action);
					Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_blinds); Serial.print("-");
        				getBlindSensorsState();
        				break;
				default:
					Serial.print("ERROR"); Serial.print("-"); Serial.print(idDevice); Serial.print("-");
        				Serial.print(service); Serial.print("-"); Serial.println(action);
        				break;
			}
		}
		Serial.flush();
	}
}
