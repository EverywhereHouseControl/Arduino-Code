/**
 * @description: This is a blind control program for Arduino Uno through serial port
 * @author: Vochor
 */

    // CONSTANTS
const int enable_p = 8; // Enabled out pin
const int upDown_p = 9; // Up/Down out pin

const int downSens_p = 10; // Sensor in bottom position pin
const int mediumSens_p = 11; // Sensor in bottom position pin
const int upSens_p = 12; // Sensor in bottom position pin

const int upButton_p = 6;
const int downButton_p = 7;

    // VARIABLES
int enable = LOW; // Enable output pin value
int upDown = LOW; // Up/Down output pin value

int sensor = LOW; //  variable to read sensor in up/medium/down position value
// int bounceCheck = LOW; // variable for debouncing // This variable is local to debounce(int pin)  function  now
int bounceDelay = 50; // debounce time; increase it if the output flickers

int upButton = LOW; // variable to read up signal of manual interface
int downButton = LOW;  // variable to read up signal of manual interface

int stateBlind = 0; // 0 = bottom; 1 = medium; 2 = up
int newStateBlind = 0; // Future stateBlind

// char *code; // Action code to Serial Port (0 = Down step blind, 1 = Up step blind)

// const int idDevice = 999; // Symbolic idDevice for testing
// const int service_blind = 209;

/**
 * This function checks if any button of manual interface has been pressed.
 */
void   manualControlCheck_blindSensors() {
    // upButton = digitalRead(upButton_p);
    upButton = debounce(upButton_p); // Ignore bouncing
    // downButton = digitalRead(downButton_p);
    downButton = debounce(downButton_p); // Ignore bouncing
    if (upButton == HIGH) {
        perform(1); // Up step
        Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_blinds); Serial.print("-"); getBlindSensorsState();
    } else if (downButton == HIGH) {
        perform(0); // Down step
        Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_blinds); Serial.print("-"); getBlindSensorsState();
    } else {
        // Do nothing
    }
}

/**
 * This function report for serial port the state of the blind. The state can be: "UP", "MEDIUM" and "DOWN".
 */
void getBlindSensorsState() {
    switch (stateBlind) {
        case 0: //BOTTOM
            Serial.println("DOWN");
            break;
        case 1: //MEDIUM
            Serial.println("MEDIUM");
            break;
        case 2:
            Serial.println("UP");
            break;
        default:
            Serial.println("1_State error"); //State Error
    }
}

/**
 * This function make the setup configuration for the blind program
 */
void setup_blindSensors() {
    // Set enable and upDown pins
    pinMode(enable_p, OUTPUT);
    pinMode(upDown_p, OUTPUT);

    // Set enable and upDown to initial value
    digitalWrite(enable_p, enable);
    digitalWrite(upDown_p, upDown);

    //Set sensors pins
    pinMode(upSens_p, INPUT);
    pinMode(mediumSens_p, INPUT);
    pinMode(downSens_p, INPUT);

    // Set manual interface pins
    pinMode(upButton, INPUT);
    pinMode(downButton, INPUT);

    // Set manual interface signals to initial value
    digitalWrite(upButton, enable);
    digitalWrite(downButton, upDown);

    // Go down stateBlind
    enable = HIGH;
    upDown = LOW;
    digitalWrite(enable_p, enable);
    digitalWrite(upDown_p, upDown);
    do {
        sensor = digitalRead(downSens_p); // read the input pin
    } while (!(sensor == HIGH));
    enable = LOW;
    upDown = LOW;
    digitalWrite(enable_p, enable);
    digitalWrite(upDown_p, upDown);
    Serial.print("UPDATE"); Serial.print("-"); Serial.print(idDevice); Serial.print("-"); Serial.print(service_blinds); Serial.print("-"); getBlindSensorsState();
}

/**
 * This function perform the action which is indicated by the parameter (String type)
 * @param "act" is a input parameter that indicate the action to perform. It can be: '1' to up blind; '0' to down blind; This parameter is a String.
 */
void action_blindSensors(String act) {
    perform(act.toInt());
}

/**
 * This function perform the action which is indicated by the parameter
 * @param "action" is a input parameter that indicate the action to perform. It can be: '1' to up blind; '0' to down blind;
 */
void perform(int action) {
    //Serial.println(action);
    // Serial.print("Ultimo estado = "); Serial.println(stateBlind);
    switch (action) {
        case 1: // Up step blind
            switch (stateBlind) {
                case 0: //BOTTOM
                case 1: //MEDIUM
                    enable = HIGH;
                    upDown = HIGH;
                    digitalWrite(enable_p, enable);
                    digitalWrite(upDown_p, upDown);
                    // Serial.println("Subiendo");
                    // Serial.print("Enable = "); Serial.println(enable);
                    // Serial.print("UpDown = "); Serial.println(upDown);
                    // delay(1000); // TESTING
                    if (stateBlind == 0) {
                        do {
                            // sensor = digitalRead(mediumSens_p); // read the input pin
                            sensor = debounce(mediumSens_p); // Ignore bouncing
                        } while (!(sensor == HIGH));
                    } else { // stateBlind == 1
                        do {
                            // sensor = digitalRead(upSens_p); // read the input pin
                            sensor = debounce(upSens_p); // Ignore bouncing
                        } while (!(sensor == HIGH));
                    }
                        newStateBlind =  stateBlind + 1;
                    break;
                case 2:
                    // Do nothing
                    break;
                default:
                    Serial.println("1_State error"); //State Error
            }
            break;
        case 0: // Down step blind
            switch (stateBlind) {
                case 0: //BOTTOM
                    // Do nothing
                    break;
                case 1: //MEDIUM
                case 2:
                    enable = HIGH;
                    upDown = LOW;
                    digitalWrite(enable_p, enable);
                    digitalWrite(upDown_p, upDown);
                    // Serial.println("Bajando");
                    // Serial.print("Enable = "); Serial.println(enable);
                    // Serial.print("UpDown = "); Serial.println(upDown);
                    // delay(1000); // TESTING
                    if (stateBlind == 2) {
                        do {
                            // sensor = digitalRead(mediumSens_p); // read the input pin
                            sensor = debounce(mediumSens_p); // Ignore bouncing
                        } while (!(sensor == HIGH));
                    } else { // stateBlind == 1
                        do {
                            // sensor = digitalRead(downSens_p); // read the input pin
                            sensor = debounce(downSens_p); // Ignore bouncing
                        } while (!(sensor == HIGH));
                    }
                    newStateBlind = stateBlind - 1;
                    break;
                default:
                    Serial.println("1_State Error"); //State Error
            }
            break;
        default:
            Serial.println("1_Code error"); // Bad recibed code
            // Gestionar error
    }
    // Serial.println("0"); // OK recibed code
    // Disable the outputs after delay
    //  delay(1000);  Not necesary now
    enable = LOW;
    upDown = LOW;
    digitalWrite(enable_p, enable);
    digitalWrite(upDown_p, upDown);
    // Serial.print("Enable = "); Serial.println(enable);
    // Serial.print("UpDown = "); Serial.println(upDown);
    stateBlind = newStateBlind;
    // Serial.print("Estado actual = "); Serial.println(stateBlind);
}

/**
 * This function ignores the bounces of a input signal
 * @param "pin" is a input paramenter that indicate the pin associated to the input signal
*/
int debounce(int pin) {
    int signal;
    int bounceCheck;
    int timeDelay = bounceDelay;
    signal = digitalRead(pin); // read the input pin
    delay(timeDelay);
    bounceCheck = digitalRead(pin); // read the input pin after a delay
    if (signal = bounceCheck)
        return HIGH;
    else
        return LOW;
}
