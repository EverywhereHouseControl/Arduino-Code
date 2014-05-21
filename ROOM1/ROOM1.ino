/* This is a sketch wich tests IRControl, light control, blinds, temperature and Intercom
*  in the same Arduino
*/
#include <string.h>

//  Test global variables
//char input[16];

//***idDevice***
const int idDevice = 50;

//***idServices***
const int service_lights = 218;
const int service_IR = 204;
const int service_blind = 209;


void setup() {
    Serial.begin(9600);  // init Serial port
    setup_LightControl();
    setup_IR();
    setup_blindSensors();
}

void loop() {
    check_IR();
    manualControlCheck_blindSensors();
    if (Serial.available()) {
        delay(21);  //  necesary to wait the input to be ready
        char input[32] = "";
        String command;
        String service;
        String action;

        int i = 0;
        while(Serial.available()) {
            input[i] = Serial.read();
            i++;
        }
        Serial.flush();
        String inputS = input;
        int index = inputS.indexOf('-');
        int index2 = inputS.indexOf('-', index+1);
        command = inputS.substring(0, index);
        service = inputS.substring(index+1, index2);
        action = inputS.substring(index2+1);
        //separateInput(i, input, &service, &action);
            Serial.print("input = "); Serial.println(input);
        switch(service.toInt()) {
            case service_lights:    //lights
                if (command == "SEND")
                    perform_LightControl(action);
                Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-");Serial.print(service_lights); Serial.print("-"); getLightsState();
                break;
            case service_IR:    //tv IR
                if (command == "SEND")
                   IR(action);
                Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-");Serial.print(service_IR); Serial.print("-"); getIRstate();
                break;
            case service_blind: //Blind
                if (command == "SEND")
                    action_blindSensors(action);
                Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_blind); Serial.print("-"); getBlindSensorsState();
                break;
            default:
                Serial.println("ERROR");
                break;
        }
        Serial.flush();
    }

}
