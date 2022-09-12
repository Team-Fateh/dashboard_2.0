




/*
 * LoRa E32-TTL-100
 * Start device or reset to send a message
 * https://www.mischianti.org
 *
 * E32-TTL-100----- Arduino UNO
 * M0         ----- GND
 * M1         ----- GND
 * RX         ----- PIN 2 (PullUP &amp; Voltage divider)
 * TX         ----- PIN 3 (PullUP)
 * AUX        ----- Not connected
 * VCC        ----- 3.3v/5v
 * GND        ----- GND
 *
 */
#include "Arduino.h"

//#include <SoftwareSerial.h>
int count=0;

//SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  delay(500);

  Serial.println("Hi, I'm going to send message!");

  Serial1.begin(9600);
  Serial1.println("Hello, World?");

  //mySerial.begin(9600);
  //mySerial.println("Hello, world?");
}

void loop() {
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

       Serial1.print(count);
       Serial1.write  ("  ");
       Serial.print(count);
       Serial.println();
       delay(200);
       count++; 
}
