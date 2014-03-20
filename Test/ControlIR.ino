/*test sobre control IR completo*/
#include <IRremote.h>

int pinRead_IR = 2;
IRrecv recIR(pinRead_IR);
IRsend ir;
decode_results r;

void setup_IR(){
  //Serial.begin(9600);  
  recIR.enableIRIn();
}

void loop_IR(){
  if(recIR.decode(&r)) {
    Serial.println(r.value, DEC);
    recIR.resume();
  }
}
void IR(char input[],int l){
        int i = 0;
	char c = input[i]; i++;
	switch(c){
		case '0': {
			Serial.println("Emision!");
			char datac[10];
			datac[0] = input[i]; i++;
			int protocol = atoi(datac);
			datac[0] = input[i]; i++;
			datac[1] = input[i]; i++;
			int nbits = atoi(datac);
                        int j = 0;
			while(i < l){
				datac[j] = input[i];
				i++; j++;
			}
			unsigned long data = atol(datac);
			ir.sendIR(data,nbits,0,protocol);
                        recIR.enableIRIn();
			Serial.println("fin");
                        delay(500);
			break;
		}
		case '1': {
			char buttons[2];
			int j = 0;
			while(i < l){
				if(j < 2){    
					buttons[j] = input[i]; j++; i++;
                                }
				else
					j++;    
			}
		recIR.configIR(atoi(buttons));
		break;
		}
    }
}


