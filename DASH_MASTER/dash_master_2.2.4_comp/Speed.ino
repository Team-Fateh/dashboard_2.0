////void speedISR1(){
////  srev++;
////}
//
////void getSpeed1(){
////detachInterrupt(digitalPinToInterrupt(SPEED_PIN));           //detaches the interrupt while calculating
////tim=millis()-oldtime;        //finds the time 
////srpm=(srev/tim)*60000;         //calculates rpm
////oldtime=millis();             //saves the current time
////srev=0;
////attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR1,RISING);
////wheelSpeed=(srpm/6)*wheelRadius;
////}
//void speedISR2(){
//  newStime=millis();
//  Stime=newStime-oldStime;
//  oldStime=newStime;
//}
//void getSpeed2(){
//  detachInterrupt(digitalPinToInterrupt(SPEED_PIN));
//  srpm=spokeangle/Stime*1000*60;
//  wheelSpeed=srpm*wheelRadius*(60/1000);
//  attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);
//}
//void getSpeed3(){
//  if (duration>500){
//  AngularSpeed= (0.8377*1000000)/duration;
//  speedms=(AngularSpeed*WheelRadius);
//  speedkmh=(speedms*3.6);}
//  else
//  speedkmh=0;
//}
//void hmiSpeed(){
//    Serial3.print("t6.txt=");
//    Serial3.print("\"");
//    Serial3.print(wheelSpeed);
//    Serial3.print("\"");
//    Serial3.write(0xff);
//    Serial3.write(0xff);
//    Serial3.write(0xff);
//}
//void hmiSpeed3(){
//    Serial3.print("t6.txt=");
//    Serial3.print("\"");
//    Serial3.print((int)speedkmh);
//    Serial3.print("\"");
//    Serial3.write(0xff);
//    Serial3.write(0xff);
//    Serial3.write(0xff);
//}
