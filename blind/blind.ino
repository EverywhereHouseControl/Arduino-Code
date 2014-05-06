/*
    Description: This is a basic blind control through serial port for Arduino Uno.
    Author: Vochor
*/

    // CONSTANTS
/*const int Eo_p = 8; // Enabled out pin
const int UDo_p = 9; // Up/Down out pin
const int step_time = 500; // Time that the signal (Up or Down) is activated.*/

    // VARIABLES
/*int Eo_v = LOW; // Enable output pin value
int UDo_v = LOW; // Up/Down output pin value*/

int code; // Action code to Serial Port (0 = Down step blind, 1 = Up step blind)
String pos = "DOWN";
int step = 0;

void getBlindsState(){
  Serial.println(pos);
}

void setup_blinds() {

    // Set mode of output pins
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    // Set value of output pins
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
}

void action_blinds(String s) {
  switch(s.toInt()){             
      case 1:
            digitalWrite(8,HIGH);
            digitalWrite(9,HIGH);
            Serial.println(1);
            step++;
            break;
      case 0:
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            Serial.println(0);
            step--;
            break;
      default:
            Serial.println(1);
  }
   if(step == 5){//a falta de sensores...
     step = 0;
     switch(pos.charAt(0)){
       case 'D':
         pos = "MEDIUM";
         break;
       case 'M':
         pos = "UP";
         break;
       default:
         pos = "UP";
     }
   }
   if(step == -5){
     step = 0;
     switch(pos.charAt(0)){
       case 'U':
         pos = "MEDIUM";
         break;
       case 'M':
         pos = "DOWN";
         break;
       default:
         pos = "UP";
     }
   }
   delay(500);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
            
}
