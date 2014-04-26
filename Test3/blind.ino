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
            break;
      case 0:
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            Serial.println(0);
            break;
      default:
            Serial.println(1);
  }
   delay(500);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
            
}
