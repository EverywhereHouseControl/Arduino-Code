/*test sobre control IR completo*/
#include <IRremote.h>

int pinRead_IR = 2;
IRrecv recIR(pinRead_IR);
IRsend ir;
decode_results r;
String dataA = "0";

void setup_IR(){
  //Serial.begin(9600);
  pinMode(12,INPUT);  
  recIR.enableIRIn();
}

void loop_IR(){
  if(recIR.decode(&r)) {
    dataA = "0";
    dataA = dataA + r.decode_type;
    dataA = dataA + r.bits;
    dataA = dataA + r.value;
    //Serial.println(data);
    recIR.resume();
  }
}

void getIRstate(){
  Serial.println(dataA);
}

void IR(String s){
        dataA = s;
        int l = s.length()+1;
        //Serial.println(s);
        char input[l];
        s.toCharArray(input,l);
        int i = 0;
	char c = input[i]; i++;
	switch(c){
		case '0': {
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
                        //Serial.println(data);
			ir.sendIR(data,nbits,0,protocol);
                        recIR.enableIRIn();
			//Serial.println("0");
                        //delay(500);
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
		//recIR.configIR(atoi(buttons));
                int nButtons = atoi(buttons);
                int pulsador = LOW;
	        String data[nButtons];
	        decode_results results;
	        Serial.println("Bienvenido a la configuracion de su mando EHC");
                Serial.println(nButtons);
	        for(int i = 0; i < nButtons;i++){
                  data[i] = "0";
		  Serial.println("Pulsa siguiente Boton...");
                    while(!recIR.decode(&results) && pulsador == LOW)
                      pulsador = digitalRead(12);
                  delay(1000);
                  if(pulsador == HIGH){
                    data[i] = "NULL";
                    pulsador = LOW;
                  }
                  else{
		    //ltoa(results.decode_type,data[i],10);
                    data[i] = data[i] + results.decode_type;
                    //ltoa(results.bits,data[i],10);
                    data[i] = data[i] + results.bits;
                    //ltoa(results.value,data[i],10);
                    data[i] = data[i] + results.value;
		    Serial.println("Recibido");
		    recIR.resume();
		    delay(1000);
                  }		
	        }
	        Serial.println("Todos los datos Recibidos!");
		
	        for(int i = 0; i < nButtons;i++){
		//Serial.print("Boton "+i+": ");
		  Serial.println(data[i]);		
	        }
	        Serial.println("Configuracion finalizada");
	        recIR.resume();
		break;
		}
                default:
                Serial.println("1");
    }
}


