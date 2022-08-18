

//CANSetup
void canSetup(int can_cs, int can_int, long can_freq, long clock_freq) {
  CAN.setPins(can_cs, can_int);
  CAN.setClockFrequency(clock_freq);
  if (!CAN.begin(can_freq)) {
    Serial.println("Starting CAN failed!"); //can failed
  }
}

//CAN
void getCAN(unsigned long* rpm, float* temp, float* volt){
  
  int rMSB=0,rLSB=0; //rpm bits
  int tMSB=0,tLSB=0;
  int bMSB=0,bLSB=0;
  
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
  }

   if(packId==218101064){    //0CFFF548 for battery volt air temp coolant temp

    int e=0;
    while (CAN.available()) {
      if (e==0){
        e++;
        bLSB=(int)CAN.read();
      }
      if (e==1){
        e++;
        bMSB=(int)CAN.read();
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
     *volt=((bMSB*256)+bLSB)*0.01;
    }

  }
}
