void loraInit(){
  Serial2.begin(9600);
}

void loraDataSend(){
  Serial2.println(RPM);
  Serial2.println();
//  Serial2.flush();
}

//void lora
