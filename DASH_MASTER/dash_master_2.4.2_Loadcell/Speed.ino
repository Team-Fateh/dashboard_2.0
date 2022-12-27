//void speedISR1(){
//  srev++;
//}

//void getSpeed1(){
//detachInterrupt(digitalPinToInterrupt(SPEED_PIN));           //detaches the interrupt while calculating
//tim=millis()-oldtime;        //finds the time 
//srpm=(srev/tim)*60000;         //calculates rpm
//oldtime=millis();             //saves the current time
//srev=0;
//attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR1,RISING);
//wheelSpeed=0.00046*(srpm/6);
//}

//
//void speedISR2(){
//  newStime=millis();
//  Stime=newStime-oldStime;
//  oldStime=newStime;
//}

void speedISR2(){
  newStime=millis();
  Stime=newStime-oldStime;
  wheelSpeed=0.076/(Stime/1000);
  wheelSpeed=wheelSpeed*3.6;
  oldStime=newStime;
}

//void getSpeed2(){
//  detachInterrupt(digitalPinToInterrupt(SPEED_PIN));
//  srpm=spokeangle/Stime*1000*60;
////  wheelSpeed=srpm*wheelRadius*(60/1000);
//wheelSpeed=0.00046*(srpm/6);
//  attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,FALLING);
//}

void hmiSpeed(){
    Serial3.print("t6.txt=");
    Serial3.print("\"");
    Serial3.print(wheelSpeed);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
