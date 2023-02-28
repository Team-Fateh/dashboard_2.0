#include <CAN_fun.h>

void canCheck(){
   if (can_available == 0){
      if (millis()-last_can_check_time>=can_check_time){
          canSetup(canFreq);
      }
   }
 }


 
void getCAN(unsigned long* rpm, float* temp, float* volt){
  
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