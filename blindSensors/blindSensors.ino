/*
    Description: This is a basic
    Author: Vochor
*/

    // CONSTANTS
const int Eo_p = 8; // Enabled out pin
const int UDo_p = 9; // Up/Down out pin
const int bottomSens_p = 10; // Sensor in bottom position pin
const int mediumSens_p = 11; // Sensor in bottom position pin
const int upSens_p = 12; // Sensor in bottom position pin

    // VARIABLES
int Eo_v = LOW; // Enable output pin value
int UDo_v = LOW; // Up/Down output pin value
int bottomSens = LOW; //  Sensor in down position value
int mediumSens = LOW; //  Sensor in medium position value
int upSens = LOW; //  Sensor in high position value

int state = 0; // 0 = bottom; 1 = medium; 2 = up
int newState = 0; // Future state

void getBlindSensorsState() {
    Serial.println(state);
}

void setup_blindSensors(int *st) {
    // Set output pins
    pinMode(Eo_p, OUTPUT);
    pinMode(UDo_p, OUTPUT);
    pinMode(bottomSens, INPUT);
    pinMode(mediumSens, OUTPUT);
    pinMode(upSens, OUTPUT);

    // Set output pins value
    digitalWrite(Eo_p, Eo_v);
    digitalWrite(UDo_p, UDo_v);

    // Set state
    state = *st;
}

void action_blindSensors(String s, int *st) {
    state = *st;
    switch (s.toInt()) {
        case 0: // Down step blind
            switch (state) {
                case 0: //BOTTOM
                    // Do nothing
                    break;
                case 1: //MEDIUM
                case 2:
                    Eo_v = HIGH;
                    UDo_v = LOW;
                    digitalWrite(Eo_p, Eo_v);
                    digitalWrite(UDo_p, UDo_v);
                    // Serial.println("Bajando");
                    // Serial.print("Enable = "); Serial.println(Eo_v);
                    // Serial.print("UpDown = "); Serial.println(UDo_v);
                    // delay(1000); // TESTING
                    if (state == 2) {
                        do {
                            mediumSens = digitalRead(mediumSens_p);   // read the input pin
                            // Serial.print("Read mediumSen = "); Serial.println(mediumSens);
                        } while (!(mediumSens == HIGH));
                    } else { // state == 1
                        do {
                            bottomSens = digitalRead(bottomSens_p);   // read the input pin
                            // Serial.print("Read bottomSen = "); Serial.println(bottomSens);
                        } while (!(bottomSens == HIGH));
                    }
                    newState = state - 1;
                    break;
                default:
                    Serial.println("1_State Error"); //State Error
            }
            break;
        case 1: // Up step blind
            switch (state) {
                case 0: //BOTTOM
                case 1: //MEDIUM
                    Eo_v = HIGH;
                    UDo_v = HIGH;
                    digitalWrite(Eo_p, Eo_v);
                    digitalWrite(UDo_p, UDo_v);
                    // Serial.println("Subiendo");
                    // Serial.print("Enable = "); Serial.println(Eo_v);
                    // Serial.print("UpDown = "); Serial.println(UDo_v);
                    // delay(1000); // TESTING
                    if (state == 0) {
                        do {
                            mediumSens = digitalRead(mediumSens_p);   // read the input pin
                            // Serial.print("Read mediumSen = "); Serial.println(mediumSens);
                        } while (!(mediumSens == HIGH));
                    } else { // state == 1
                        do {
                            upSens = digitalRead(upSens_p);   // read the input pin
                            // Serial.print("Read upSen = "); Serial.println(upSens);
                        } while (!(upSens == HIGH));
                    }
                        newState =  state + 1;
                    break;
                case 2:
                    // Do nothing
                    break;
                default:
                    Serial.println("1_State error"); //State Error
            }
            break;
        default:
            Serial.println("1_Code error"); // Bad recibed code
            // Gestionar error
    }
//            Serial.println("0"); // OK recibed code
    //Disable the outputs after delay
//            delay(1000);  Not necesary now
    Eo_v = LOW;
    UDo_v = LOW;
    digitalWrite(Eo_p, Eo_v);
    digitalWrite(UDo_p, UDo_v);
    state = newState;
    *st = state;
}
