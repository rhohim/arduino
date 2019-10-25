/*
  Keyboard

  Plays a pitch that changes based on a changing analog input

  circuit:
  - three force-sensing resistors from +5V to analog in 0 through 5
  - three 10 kilohm resistors from analog in 0 through 5 to ground
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone3
*/

#include "pitches.h"

//const int threshold = 10;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_C6, NOTE_A5,NOTE_0 ,
  NOTE_G5, NOTE_C6, NOTE_E6, NOTE_C6,NOTE_G6, NOTE_E6, NOTE_D6,NOTE_0 ,
  NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_C6, NOTE_A5,NOTE_0 ,
  NOTE_G5, NOTE_C6, NOTE_E6, NOTE_D6,NOTE_C6, NOTE_B5, NOTE_C6,NOTE_0 ,
  NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_D6, NOTE_E6, NOTE_F5,NOTE_G6,  NOTE_0 ,
  NOTE_A5, NOTE_G6, NOTE_F6, NOTE_E6,NOTE_G6, NOTE_E6, NOTE_D6,NOTE_0 ,
  NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_C6, NOTE_A5,NOTE_0 ,
  NOTE_G5, NOTE_C6, NOTE_E6, NOTE_D6,NOTE_C6, NOTE_B5, NOTE_C6, NOTE_0 
   
};
int durasi[] = {
  900, 300, 300, 300, 300, 300, 1200, 1000,200,
  900, 300, 300, 300, 300, 300, 2200,200,
  900, 300, 300, 300, 300, 300, 1200, 1000,200,
  900, 300, 300, 300, 300, 300, 2200,200,
  900, 300, 300, 300, 300, 300, 900, 300, 1000,200,
  900, 300, 300, 300, 300, 300, 2200,200,
  900, 300, 300, 300, 300, 300, 1200, 1000,200,
  900, 300, 300, 300, 300, 300, 2200,200
  
  
};

void setup() {
  for (int i=0; i < 69; i++){
    tone(8,notes[i],durasi[i]);
    delay(durasi[i]+120);
    noTone(8);
  }
}

void loop() {
  
}
