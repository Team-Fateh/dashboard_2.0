void loraInit(){
  Serial2.begin(9600);
}

void loraDataSend(){
  Serial2.print("Team Fateh ");
  Serial2.println(acount);
  acount++;
  
}

//void lora
