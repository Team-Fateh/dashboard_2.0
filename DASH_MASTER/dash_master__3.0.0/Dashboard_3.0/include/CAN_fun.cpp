#include <CAN_fun.h>

void canCheck(){
   if (can_available == 0){
      if (millis()-last_can_check_time>=can_check_time){
          canSetup(canFreq);
      }
   }
 }