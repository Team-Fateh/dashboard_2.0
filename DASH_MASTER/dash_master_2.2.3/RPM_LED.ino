void showLightCont(){                                 //Continuous Green to Red
  light=map(RPM, 0,11000, 0,19);
  FastLED.clear();
  for (int i=0; i<=light; i++){
  
  leds[i]=CRGB(13.42*light,255-(13.42*light),0);
  }
FastLED.show();
}



void showLightDis(){                                //Discrete Blue to Green to Red
  int red, blue, green;
  light=map(RPM, 0,11000, 0,19);
  FastLED.clear();
  if(RPM>=0&&RPM<=3500){
    blue=(light,0,6,0,255);
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(0,blue,255);
     }
  }
  if(RPM>3500&&RPM<=7000){
    green=(light,7,12,0,255);
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(green,255,0);
     }
  }
  if(RPM>7000&&RPM<=11000){
    red=(light,13,19,0,255);
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(255,0,0);
     }
   }
  if(RPM>11000){
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(255,100,100);
     }
  }
  
FastLED.show();
}
