/*
  Combat Ready Light Show
  by Jason Morris
*/

#include "lightnumbersWMultiplex.h"
#include "FunctionsWMultiplex.h"


void setup() {

//  bulletsGround[0] = 25;  //changed
  bulletsGround[16] = -1;
  for (int i = 0; i < 16; i++){
    bulletsGround[i] = (i*2)+22;
  }
  
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
  while (digitalRead(button) == LOW) {}//wait until button is pushed before starting light show

  Play_Music();//start music
  Serial.println('1'); //send signal to mp3 arduino to play the music
  wait(5358);

  //stage flash 8 times
  for (int i = 0; i < 8; i++) {
    SingleFlash(stage);
    wait(21.5);
  }

  //flash stage and duel lights
  DoubleFlash(stage, duel, 2);
  wait(21.5);

  for (int i = 0; i < 7; i++) {
    SingleFlash(stage);
    wait(21.5);
  }

  DoubleFlash(stage, duel, 2);
  wait(21.5);

  DoubleFlash(stage, duel, 2);
  wait(21.5);

  DoubleFlash(stage, duel, 1);
  wait(22);

  DoubleFlash(stage, duel, 1);
  wait(22);

  DoubleFlashFinal(stage, duel);
  wait(22);

  wait(1950);

  bulletshot2(bulletsPower, bulletsGround);

  Serial.println('2');  //send signal to other arduino to do the steam lights
  DoubleSpeedFlash(stage, duel);
  wait(2790);

  DoubleSpeedFlash(stage, duel);
  wait(65);

  preBullets2(bulletsPower);

  wait(1170);
  bulletshot2(bulletsPower, bulletsGround);

  chorus(green, yellow, purple);
  chorus(green, purple, orange);
  chorus(green, yellow, purple);
  chorus(green, purple, orange);

  wait(10800);
  intimidate2(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(740);
  intimidate_rev2(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(700);
  intimidate_half2(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(3046);
  FlashBuild(stage, duel);
  bulletshot2(bulletsPower, bulletsGround);
  chorus(green, yellow, purple);
  chorus(green, purple, orange);
  chorus(green, yellow, purple);
  chorus(green, purple, orange);
  wait(35);
  intimidate_half_sd(stage, duel);
  wait(740);
  intimidate_half_sdb2(bulletsPower, stage, duel);
  wait(740);
  intimidate_half2(bulletsPower, green, yellow, purple, orange, stage, duel);
  wait(740);
  INTIMIDATE_FINAL2(bulletsPower, green, yellow, purple, orange, stage, duel);

}
