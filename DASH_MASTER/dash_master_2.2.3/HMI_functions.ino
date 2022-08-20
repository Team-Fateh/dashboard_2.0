void hmiTempRed(){
  if(TEMP>=100.00)
  {
    Serial3.print("main");       //63488 Red colour
    Serial3.print(".");
    Serial3.print("bco");
    Serial3.print("=");
    Serial3.print("63488");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    for(int i=0;i<=11;i++){
    Serial3.print("t");       //63488 Red colour
    Serial3.print(i);
    Serial3.print(".");
    Serial3.print("bco");
    Serial3.print("=");
    Serial3.print("63488");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    }


    
  }
}
