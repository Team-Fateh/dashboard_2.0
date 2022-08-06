#include <CAN.h>

int MSB=0,LSB=0;
int tMSB=0,tLSB=0;
unsigned long RPM;
float temp;
void setup() {
  CAN.setPins(10,2);
  CAN.setClockFrequency(8E6);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print("Received ");
    Serial.print("packet with id ");
    long packId = CAN.packetId();
    Serial.println(packId);
    //RPM
    if(packId==218099784){      //0CFFF048 for RPM,TPS,FUEL,Ignition
    
   

      // only print packet data for non-RTR packets
      int d=0;
      while (CAN.available()) {
        
        if (d==0){
          d++;
          LSB=(int)CAN.read();
        }
        if (d==1){
          d++;
          MSB=(int)CAN.read();
        }
          CAN.read(); d++;
      }
      RPM=((MSB*255)+LSB)*0.125;
      Serial.println(RPM);
      Serial.println();
      Serial.print(MSB);
      Serial.print("    ");
      Serial.print(LSB);
    
    }//if packId
    //RPM
    //Coolant Temp
    if(packId==218101064){    //0CFFF548 for battery volt air temp coolant temp
    
      // only print packet data for non-RTR packets
      int e=0;
      while (CAN.available()) {
        
        
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

      temp=((tMSB*255)+tLSB)*0.1;
      Serial.print(temp);
      Serial.println();
      Serial.print(tMSB);
      Serial.print("    ");
      Serial.print(tLSB);
    
    }//if packId Coolant temp
    Serial.println();
  }//if packSize
  
}
