void loraInit(){
  Serial2.begin(9600);
}

void loraSendData(){
  Serial2.println("Team Fateh");
}
