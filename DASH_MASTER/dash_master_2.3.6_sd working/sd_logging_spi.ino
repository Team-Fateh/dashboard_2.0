void sdSpi(){
  digitalWrite(cs,HIGH);
  digitalWrite(cs_sd,LOW);
}
void canSpi(){
  digitalWrite(cs,LOW);
  digitalWrite(cs_sd,HIGH);
}

void sdInit(){
 sdSpi();

 if (SD.begin(cs_sd))
 {
   Serial.println("SD card is ready to use.");
 } else
 {
   Serial.println("SD card initialization failed");
   hmiSdRed();
   
 }

 
 sdcard_file = SD.open("data.txt", FILE_WRITE);


 if (sdcard_file) { 
   sdcard_file.println("TestDATA");
  //  sdcard_file.println("Time in (ms),RPM,TEMP,Brake");   
   sdcard_file.println("Time in (ms),RPM,TEMP");   
   sdcard_file.close(); // close the file
 }
 // if the file didn't open, print an error:
 else {
   Serial.println("error opening test.txt");
   hmiSdRedGreen();
 }
 canSpi();
}

void sdData(){
 sdSpi();
    sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) { 
   sdcard_file.print(millis());
   sdcard_file.print(",");   
   sdcard_file.print(RPM);
   sdcard_file.print(",");
   sdcard_file.print(TEMP);
  //  sdcard_file.print(",");
  //  sdcard_file.print(brakePress);  
   sdcard_file.println();  
   sdcard_file.close(); // close the file
 }
 // if the file didn't open, print an error:
 else {
   Serial.println("error opening test.txt");
   hmiSdRedGreen();
 }
 canSpi();
}

void hmiSdRedGreen(){
  Serial3.print("r2.pco=");       //63488 Red colour
   Serial3.print("63488");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.print("r2.bco=");       //1024 Green colour
   Serial3.print("1024");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
}
void hmiSdRed(){
  Serial3.print("r2.pco=");       //63488 Red colour
   Serial3.print("63488");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.print("r2.bco=");       //63488 Red colour
   Serial3.print("63488");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
}

void hmiSdGreen(){
 Serial3.print("r2.pco=");       //1024Green colour
   Serial3.print("1024");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.print("r2.bco=");       //1024 green colour
   Serial3.print("1024");
   Serial3.write(0xff);
   Serial3.write(0xff);
   Serial3.write(0xff);
}
