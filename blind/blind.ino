/*
    Description: This is a basic blind control through serial port for Arduino Uno.
    Author: Vochor
*/

    // CONSTANTS
const int Eo_p = 8; // Enabled out pin
const int UDo_p = 9; // Up/Down out pin
const int step_time = 500; // Time that the signal (Up or Down) is activated.

    // VARIABLES
int Eo_v = LOW; // Enable output pin value
int UDo_v = LOW; // Up/Down output pin value

int code; // Action code to Serial Port (0 = Down step blind, 1 = Up step blind)

void setup() {
    Serial.begin(9600); // Open serial porl with 9600bps
    Serial.println("Serial Port Ready !!!");

    // Set mode of output pins
    pinMode(Eo_p, OUTPUT);
    pinMode(UDo_p, OUTPUT);

    // Set value of output pins
    digitalWrite(Eo_p, Eo_v);
    digitalWrite(UDo_p, UDo_v);
}

void loop() {
    if (Serial.available() > 0) {
        code = Serial.read() - '0'; // Subtract code ASCII of char '0' to obtain the number
        // We can use atoi(), but above way allow to check easier a bad code reception.
        if (!(0 <= code && code <= 1)) {
            // Serial.println("[ERROR]. Bad request !!!. Code not recognized.");
        } else {
            // Serial.print("Code \'");Serial.print(code);Serial.println("\' received.");
            if (code == 1) { // Up step blind
                Eo_v = HIGH;
                UDo_v = HIGH;
                // Serial.println("Up step blind request");
            } else { // Down step blind
                Eo_v = HIGH;
                UDo_v = LOW;
                // Serial.println("Down step blind request");
            }
            digitalWrite(Eo_p, Eo_v);
            digitalWrite(UDo_p, UDo_v);
            // Disabled the outputs after delay
            delay(step_time);
            Eo_v = LOW;
            UDo_v = LOW;
            digitalWrite(Eo_p, Eo_v);
            digitalWrite(UDo_p, UDo_v);
            //Serial.println("Succesfull request !!!.");
        }
    }
}

/* NOTE:
    Disable all "Serial.println" beacuse it produces a big delay in the speed change of the signals
*/
