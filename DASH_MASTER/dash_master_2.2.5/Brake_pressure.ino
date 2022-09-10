void getBrake(){
  brakeValue = analogRead(brake_pin);
    brakeVolt = brakeValue* (5.0/1023.0);
    if (brakeVolt >= 4.5){
      brakeVolt = 4.5;
      }
    brakePress = brakeVolt*100/4-12.45;
}

void hmiBrake(){
  
    Serial3.print("j");
    Serial3.print("1");
    Serial3.print(".");
    Serial3.print("val=");
    Serial3.print("\"");
    Serial3.print(brakePress);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    if(brakePress>=60){
    Serial3.print("j");
    Serial3.print("1");
    Serial3.print(".");
    Serial3.print("pco=");
    Serial3.print("\"");
    Serial3.print("63488");   //Red
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    }
     if(brakePress<60){
    Serial3.print("j");
    Serial3.print("1");
    Serial3.print(".");
    Serial3.print("pco=");
    Serial3.print("\"");
    Serial3.print("1024");    //Green
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    }
}
