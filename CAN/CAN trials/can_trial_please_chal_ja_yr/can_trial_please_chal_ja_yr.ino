// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h>

int MSB=0,LSB=0;
unsigned long RPM;
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

    if (CAN.packetExtended()) {
      Serial.print("extended ");
    }

    if (CAN.packetRtr()) {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }

    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);

    if (CAN.packetRtr()) {
      Serial.print(" and requested length ");
      Serial.println(CAN.packetDlc());
    } else {
      Serial.print(" and length ");
      Serial.println(packetSize);

      // only print packet data for non-RTR packets
      int d=0;
      while (CAN.available()) {
          CAN.read(); d++;
//        Serial.print((int)CAN.read());
//        Serial.print(" ");
        
        if (d==3){
          d++;
          LSB=(int)CAN.read();
//          Serial.print("LSB");
//        Serial.print((int)CAN.read()); 
//        Serial.print(" ");
        }
        if (d==4){
          d++;
          MSB=(int)CAN.read();
//          Serial.print("MSB");
//        Serial.print((int)CAN.read());
//        Serial.print(" ");
        }
      }
//      RPM=((MSB*255)+LSB)*0.125;
      RPM=(MSB*31.875);
      Serial.print(RPM);
      Serial.println();
      Serial.print(MSB);
      Serial.print("    ");
      Serial.print(LSB);
    }

    Serial.println();
  }
  
}
