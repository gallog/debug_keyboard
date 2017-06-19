#include "Keyboard.h"

#define PINF6 A0
#define PINF5 A2
#define ONOFF 6

#define MINDELAYMS 300
#define BPRESSED LOW
 
unsigned long lastReadMs;
unsigned long currentPressTimeMs;
int F5;
int F6;
boolean isOn;

void setup()  {
  Keyboard.begin();
  lastReadMs = millis();
  F5 = !BPRESSED;
  F6 = !BPRESSED;
  pinMode(PINF6,INPUT); 
  pinMode(PINF5,INPUT); 
  pinMode(ONOFF,INPUT); 
}


void loop()  {
    currentPressTimeMs = millis();
    F5 = digitalRead(PINF5);
    F6 = digitalRead(PINF6);
    isOn = digitalRead(ONOFF) == BPRESSED;
    
    if (isOn && currentPressTimeMs - lastReadMs > MINDELAYMS) {

      if (F6 == BPRESSED) {
          Keyboard.write(KEY_F6);
          lastReadMs = currentPressTimeMs;       
      }
      else if (F5 == BPRESSED) {
          Keyboard.write(KEY_F5);
          lastReadMs = currentPressTimeMs;
      }
      
    }    
    delay(5);  
}
