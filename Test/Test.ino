/* This is a sketch wich tests IRControl and light control
*  in the same Arduino
*/

//  Test global variables
//char input[16];

//  Light_Control global variables
int pinRelay1 = 4;
int stateRelay1;

//  IR_Control global variables


void setup(){
  Serial.begin(9600);  // init Serial port
  setup_LightControl(pinRelay1, &stateRelay1);
  setup_IR(); 
}

void loop(){
  if(Serial.available()){
    delay(20);  //  necesary to wait the input to be ready
    char input[16];
    int i=0;
    while(Serial.available()){
      input[i] = Serial.read();
      i++;
      
    }    
    i=i-1;  //  because one character is used to difference functionalities
    
    char function = input[i];
    input[i] = '\0';
    switch(function){
      case '0':    
        perform_LightControl(input, i, pinRelay1, &stateRelay1); 
        break;
      case '1':    
        loop_IR(input, i); 
        break;
      default:
        Serial.println("-1");
        break;
    }  
    while(Serial.available()){ Serial.read(); }
  }

}
