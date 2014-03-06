/*test sobre control IR completo*/
#include <IRremote.h>

int pinRead_IR = 2;
IRrecv recIR(pinRead_IR);
IRsend ir;
decode_results r;

void setup(){
  Serial.begin(9600);  
  recIR.enableIRIn();
}

void loop(){
  if(recIR.decode(&r)) {
    Serial.println(r.value, DEC);
    recIR.resume();
  }
     if(Serial.available()){
	delay(100);
	char c = Serial.read();
	switch(c){
		case '0': {
			Serial.println("Emision!");
			char datac[10];
			int i = 0;
			datac[0] = Serial.read();
			int protocol = atoi(datac);
			datac[0] = Serial.read();
			datac[1] = Serial.read();
			int nbits = atoi(datac);
			while(Serial.available()){
				datac[i] = Serial.read();
				i++;
			}
			unsigned long data = atol(datac);
			ir.sendIR(data,nbits,0,protocol);
                        recIR.enableIRIn();
			delay(500);
			Serial.println("fin");
			break;
		}
		case '1': {
			char buttons[2];
			int j = 0;
			while(Serial.available()){
				if(j < 2)
					buttons[j] = Serial.read();
				else
					Serial.read();    
				j++;
			}
		recIR.configIR(atoi(buttons));
		break;
		}
    }
  }
}


