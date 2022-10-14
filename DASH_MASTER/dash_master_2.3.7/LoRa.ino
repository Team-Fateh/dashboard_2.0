void loraInit(){
  Serial2.begin(9600);
}

void loraDataSend(){
  Serial2.println("Team Fateh");
}

void loraCheck(){
  if(Serial2.available()){
   comm = Serial2.read();
    if(comm=='c'){
      crank();
      comm='a';
    }
    if(comm=='k'){
      kill();
      comm='a';
    }
    if(comm=='d'){
      loraDataSend();
    }
    else{
    comm='a';
    }
   }
}
