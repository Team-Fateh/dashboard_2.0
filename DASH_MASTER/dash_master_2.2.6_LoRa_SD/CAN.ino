

//CANSetup
void canSetup(int can_cs, int can_int, long can_freq, long clock_freq) {
  canSpi();
  CAN.setPins(can_cs, can_int);
  CAN.setClockFrequency(clock_freq);
  if (!CAN.begin(can_freq)) {
    Serial.println("Starting CAN failed!"); //can failed
   hmiCANRed();
  }
}

//CAN
void getCAN(unsigned long* rpm, float* temp, float* volt){
  canSpi();
  
  int rMSB=0,rLSB=0; //rpm bits
  int tMSB=0,tLSB=0;
  int vMSB=0,vLSB=0;
  
  int packetSize = CAN.parsePacket();
  long packId = CAN.packetId();
   if (packetSize) {
  
   if(packId==218099784){      //0CFFF048 for RPM,TPS,FUEL,Ignition
   
    int d = 0;
    while (CAN.available()) {
      if (d == 0) {
        d++;
        rLSB = (int)CAN.read();
      }
      if (d == 1) {
        d++;
        rMSB = (int)CAN.read();
      }
      CAN.read(); d++;
    }
    *rpm = (rMSB * 256) + rLSB;
    hmiCANGreen();
  }

   if(packId==218101064){    //0CFFF548 for battery volt air temp coolant temp

    int e=0;
    while (CAN.available()) {
      if (e==0){
        e++;
        vLSB=(int)CAN.read();
      }
      if (e==1){
        e++;
        vMSB=(int)CAN.read();
      }
      if (e==4){
          e++;
          tLSB=(int)CAN.read();
        }
        if (e==5){
          e++;
          tMSB=(int)CAN.read();
        }
          CAN.read(); e++;
      
      }
     *temp=((tMSB*256)+tLSB)*0.1;
     *volt=((vMSB*256)+vLSB)*0.01;
    hmiCANGreen();
    }

  }
  else{
   hmiCANRed();
  }
}




//CAN HMI
void hmiCANRed(){
   Serial3.print("r1.pco=");       //63488 Red colour
    Serial3.print("63488");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.print("r1.bco=");       //63488 Red colour
    Serial3.print("63488");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
void hmiCANGreen(){
  Serial3.print("r1.pco=");       //34800 green colour
    Serial3.print("1024");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.print("r1.bco=");       //34800 green colour
    Serial3.print("1024");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
void hmiCAN(){
    Serial3.print("t");
    Serial3.print("4");
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(RPM);          //
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    Serial3.print("t");
    Serial3.print("5");
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print((int)TEMP);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    Serial3.print("t");
    Serial3.print("10");
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(VOLT);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
  
}


void hmiTempRed(){
  if(TEMP>=95.00)
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
  if(TEMP<95.00)
  {
    Serial3.print("main");       //0 black colour
    Serial3.print(".");
    Serial3.print("bco");
    Serial3.print("=");
    Serial3.print("0");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    for(int i=0;i<=11;i++){
    Serial3.print("t");       //0 black colour
    Serial3.print(i);
    Serial3.print(".");
    Serial3.print("bco");
    Serial3.print("=");
    Serial3.print("0");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    }
  }
}
