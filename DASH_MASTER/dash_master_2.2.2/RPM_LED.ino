void showLight(){
  light=map(RPM, 0,11000, 0,19);
  FastLED.clear();
  for (int i=0; i<=light; i++){
  
  leds[i]=CRGB(13.42*light,255-(13.42*light),0);
  }
FastLED.show();
}
