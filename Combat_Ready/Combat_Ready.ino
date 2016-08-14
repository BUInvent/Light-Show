/*
  Combat Ready Light Show
  by Jason Morris
*/

#include "light_numbers.h"
#include "Functions.h"


void setup() {

  //number the bulletsGround pins
  bulletsGround[16] = -1;
  for (int i = 0; i < 16; i++) {
    bulletsGround[i] = (i * 2) + 22;
  }

  //initialize all pin modes
  pinMode(button, INPUT);
  initializePinModes(stage, "analog");
  initializePinModes(duel, "analog");
  initializePinModes(green, "digital");
  initializePinModes(yellow, "digital");
  initializePinModes(purple, "digital");
  initializePinModes(orange, "digital");
  initializePinModes(bulletsPower, "digital");
  initializePinModes(bulletsGround, "digital");

  Serial.begin(9600);
}



void loop() {
  Stop_Music();  //reset mp3 player
  while (digitalRead(button) == LOW) {}//wait until button is pushed before starting light show

  Play_Music();//start music
  wait(5300);

  //stage flash 8 times
  for (int i = 0; i < 8; i++) {
    SingleFlash(stage);
    wait(3);
  }

  //flash stage and duel lights
  DoubleFlash(stage, duel, 2);
  wait(3);

  //stage flash 7 times
  for (int i = 0; i < 7; i++) {
    SingleFlash(stage);
    wait(3);
  }

  //double flash at slower speed twice
  DoubleFlash(stage, duel, 2);
  wait(3);
  DoubleFlash(stage, duel, 2);
  wait(3);

  //double flash at faster speed twice
  DoubleFlash(stage, duel, 1);
  wait(3);
  DoubleFlash(stage, duel, 1);
  wait(3);

  //final flash before show gets crazy
  DoubleFlashFinal(stage, duel);
  wait(3);

  //the suspense
  wait(1990);
  bulletshot(bulletsPower, bulletsGround); //bullets!

  Serial.println('2');  //send signal to other arduino to do the steam lights
  DoubleSpeedFlash(stage, duel);
  wait(2700);

  DoubleSpeedFlash(stage, duel);

  preBullets(bulletsPower);

  wait(1185);
  bulletshot(bulletsPower, bulletsGround);

  //chorus
  chorus(green, yellow, purple);
  chorus(green, purple, orange);
  chorus(green, yellow, purple);
  chorus(green, purple, orange);

  //intimidate audience
  wait(10640);
  intimidate(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(700);
  intimidate_rev(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(755);
  intimidate_half(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(2960);

  FlashBuild(stage, duel); //add suspense before bulletshot
  bulletshot(bulletsPower, bulletsGround);
  wait(20);

  //chorus
  chorus(green, yellow, purple);
  chorus(green, purple, orange);
  chorus(green, yellow, purple);
  chorus(green, purple, orange);

  //  finish the song
  intimidate_half_sd(stage, duel);
  wait(690);
  intimidate_half_sdb(bulletsPower, stage, duel);
  wait(740);
  intimidate_half(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(740);
  INTIMIDATE_FINAL(bulletsPower, green, yellow, purple, orange, stage, duel);

}
