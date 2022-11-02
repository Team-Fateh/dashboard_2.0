void xbeeInit(){
  Serial2.begin(230400);          //xbee
}

void xbeeDataSend(){
  // Serial2.println("Team Fateh");
  Serial2.print(millis());
  Serial2.print(",");
  Serial2.print(RPM);
  Serial2.print(",");
  Serial2.print(TEMP);
  Serial2.println();
  Serial.println("data sent");
  
}

void xbeeCheck(){
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
      xbeeDataSend();
    }
    else{
    comm='a';
    }
   }
}
