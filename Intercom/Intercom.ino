
int pinDoor = 12;
int pinSignal = 2;
int readDoor = LOW;
void setup_Intercom(){
  pinMode(pinDoor,OUTPUT);
  digitalWrite(pinDoor,LOW);
  //attachInterrupt(0,intercom,FALLING);
}

void openDoor_Intercom(){
  digitalWrite(pinDoor,HIGH);
  delay(3000);
  digitalWrite(pinDoor,LOW);  
}

void loop_Intercom(int idDevice, int idService){
    readDoor = digitalRead(pinSignal);
    if(readDoor == HIGH){
      Serial.print("UPDATE-"); Serial.print(idDevice); Serial.print("-"); Serial.print(idService); Serial.println("-INTERCOM");
      readDoor = LOW;
      delay(1000);
    }
}
