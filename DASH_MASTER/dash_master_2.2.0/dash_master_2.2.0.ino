#include<CAN.h>
#include<SD.h>
#include<SPI.h>

#define can_cs 10
#define can_int 2

int rMSB=0,rLSB=0; //rpm bits
unsigned long rpm;


void setup(){
  //Serial Comm
    Serial.begin(9600);
  //CAN
    CAN.setPins(can_cs,can_int);
    CAN.setClockFrequency(8E6);
    if (!CAN.begin(500E3)) {
      Serial.println("Starting CAN failed!"); //can failed
    }
}
    
void loop(){

//CAN
  //RPM
    int packetSize = CAN.parsePacket();
    if (packetSize) {
//      Serial.println("Received ");//tells if received
//      Serial.print("packet with id 0x");
//      Serial.print(CAN.packetId(), HEX);
//      Serial.print(" and length ");
//      Serial.println(packetSize);
          int d=0;
             while (CAN.available()) {
        
//               Serial.print((int)CAN.read());
//               Serial.print(" ");
        
               if (d==0){
                    d++;
                    rLSB=(int)CAN.read();
//                  Serial.print("LSB");
//                  Serial.print((int)CAN.read()); 
//                  Serial.print(" ");
               }
               if (d==1){
                    d++;
                    rMSB=(int)CAN.read();
//                  Serial.print("MSB");
//                  Serial.print((int)CAN.read());
//                  Serial.print(" ");
               }
               CAN.read(); d++;
             }
    }

      rpm=((rMSB*255)+rLSB)*0.125;
      rpm=(rMSB*255)+rLSB;
//      Serial.println(RPM);
//      Serial.print("    MSB:");
//      Serial.print(rMSB);
//      Serial.print("    LSB:");
//      Serial.print(rLSB);




}
