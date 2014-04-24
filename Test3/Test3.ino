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
  loop_IR();
  if(Serial.available()){
    delay(20);  //  necesary to wait the input to be ready
    char input[32]="";
    String service;
    String action;
    
    int i=0;
    while(Serial.available()){
      input[i] = Serial.read();
      i++;      
    }
    Serial.flush();    
    separateInput(i, input, &service, &action);
    //Serial.println(service);
    //Serial.println(action);
     //Serial.print(input); 
    switch(service.toInt()){
      case 192:    //lights        
        Serial.print("192-");
        perform_LightControl(action, pinRelay1, &stateRelay1);        
        break;   
      case 185:    //tv IR
        Serial.print("185-"); 
        IR(action);
        break;
/*      case 190:  //blinds to-do*/
      default:
        Serial.println("-1");
        break;
    }  
    Serial.flush();//while(Serial.available()){ Serial.read(); }
    //delay(500);
  }

}

void separateInput(int iLength, char input[],  String *service, String *action){
  /*
  input format: 
  where x is a digit  
  */
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
}
