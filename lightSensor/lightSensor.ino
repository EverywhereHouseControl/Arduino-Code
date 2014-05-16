/*
    Description: This is a light sensor program for Arduino Uno through serial port
    Author: Vochor
*/

    // CONSTANTS
const int Si_p = 2; // Sensor in pin //WARNING: It is the ANALOG pin 2
const int Sep1 = 600;
const int Sep2 = 900;

    // VARIABLES
int Si_v; // Sensor input pin value (Range: 0 - 1023)

void getLightSensorState() {
    if (Si_v >= 0 && Si_v < Sep1)
        Serial.println("Low");
    else if (Si_v >= Sep1 && Si_v < Sep2)
        Serial.println("Medium");
    else if (Si_v >= Sep2 && Si_v < 1024)
        Serial.println("High");
    else
        Serial.println("Error");
}

void setup_lightSensor() {
    //Serial.begin(9600); // Open serial porl with 9600bps
    //Serial.println("Serial Port Ready!!");
}

void action_lightSensor(String s) {
    Si_v = analogRead(Si_p);
//    Serial.println(Si_v);
//    delay(5000); //Este delay no puede estar presente en el sistema completo (con todas las funcionalidades)
}
