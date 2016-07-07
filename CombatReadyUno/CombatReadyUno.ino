/*
  Combat Ready Light Show
  On the Arduino Uno
  by Jason Morris
*/

int fire[6];
#include "FunctionsUno.h"

void setup() {

//set the fire pins to output and turn them off
  for (int i = 0; i < 6; i++) {
    fire[i] = (i + 2);
    pinMode(fire[i], OUTPUT);
    digitalWrite(fire[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {

//Once the serial command has been received, start the program
  if (Serial.available() > 0) {

    char letter = Serial.read();
    if (letter == '2') {
      
      wait(2650);
      steam(fire, 1);
      wait(3855);
      steam(fire, 1);
      wait(3860);
      steam(fire, 1);

      wait(5200);
      steam(fire, .75);

      wait(1210);
      musicnotes(fire, 424);
      musicnotes(fire, 424);
      musicnotes(fire, 424);
      musicnotes(fire, 444);

      intimidate(fire);
      wait(3330);
      intimidate(fire);
      wait(3330);
      intimidate(fire);
      wait(740);
      
      intimidate_rev(fire);
      wait(700);
      
      intimidate_half(fire);
      wait(6220);

      musicnotes(fire, 424);
      musicnotes(fire, 424);
      musicnotes(fire, 424);
      musicnotes(fire, 200);

      wait(35);
      intimidate_half(fire);
      wait(740);
      intimidate_half(fire);
      wait(740);
      intimidate_half(fire);
      wait(740);
      INTIMIDATE_FINAL(fire);
    }
  }
}
