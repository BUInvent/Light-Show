#include "FunctionsWMultiplex.h"
//#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

//wait function instead of delay so that the entire show can easily be
//slowed down or sped up. ex: change to delay(timenum*2) to go twice as slow
void wait(int timenum) {
  delay(timenum);
}




void AnWriteLights(int lights[], int brightness) {
  for (int i = 0; lights[i] != -1; i++) {
    analogWrite(lights[i], brightness);
  }
}


void DigiHigh(int lights[]) {
  for (int i = 0; lights[i] != -1; i++) {
    digitalWrite(lights[i], HIGH);
  }
}

void DigiLow(int lights[]) {
  for (int i = 0; lights[i] != -1; i++) {
    digitalWrite(lights[i], LOW);
  }
}


void initializePinModes(int lights[], char type[]) {
  for (int i = 0; lights[i] != -1; i++) {
    pinMode(lights[i], OUTPUT);
  }
  if (type == "digital") {
    DigiLow(lights);
  }
  else
  AnWriteLights(lights, 0);
}




//single flash one light
void SingleFlash(int Light[]) {
  int brightness = 0;
  int fadeAmount = 5;

  do {
    // set the brightness of the light
    AnWriteLights(Light, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
    // wait for 13 milliseconds to see the dimming effect
    wait(13);
  } while (brightness != 0);
  AnWriteLights(Light, 0);
}



//flash 2 lights
void DoubleFlash(int LightOne[], int LightTwo[], int Speed) {
  int brightness = 0;
  int fadeAmount = 5;
  int fadeCount = 0;

  AnWriteLights(LightTwo, 255);

  do {
    // set the brightness of pin 9:
    AnWriteLights(LightOne, brightness);

    if (fadeCount == 1) {
      AnWriteLights(LightTwo, brightness);
    }

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 255) {
      fadeAmount = -fadeAmount ;
      fadeCount = 1;
    }
    // wait for 30 milliseconds to see the dimming effect
    wait(Speed * 6.5);
  } while (brightness != 0);

  AnWriteLights(LightOne, 0);
  AnWriteLights(LightTwo, 0);
}



//flash 2 leds final time
void DoubleFlashFinal(int LightOne[], int LightTwo[]) {
  int brightness = 0;
  int fadeAmount = 5;

  AnWriteLights(LightTwo, 255);

  do {
    // set the brightness of Light
    AnWriteLights(LightOne, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
    // wait for 13 milliseconds to see the dimming effect
    wait(13);
  } while (brightness != 0);

  AnWriteLights(LightOne, 0);
  AnWriteLights(LightTwo, 0);
}



//bulletshot multiplex function
void bulletshot2(int bulletsPower[4], int bulletsGround[16]) {

  //set all bulletsground pins low
  DigiLow(bulletsGround);

  for (int i = 0; i < 4; i++) {
    digitalWrite(bulletsPower[i], HIGH);
    for (int j = 0; j < 16; j++) {
      digitalWrite(bulletsGround[j], HIGH);
      wait(7);
      digitalWrite(bulletsGround[j], LOW);
    }
    digitalWrite(bulletsPower[i], LOW);
    wait(44);
  }

  //set all bulletsground pins high
  DigiHigh(bulletsGround);
}




//fade 2 leds from bright to off
void DoubleSpeedFlash(int LightOne[], int LightTwo[]) {
  int brightness = 255;
  int fadeAmount = -1;

  while (brightness != -1) {
    AnWriteLights(LightOne, brightness);
    AnWriteLights(LightTwo, brightness);
    brightness = brightness + fadeAmount;
    wait(31);
  }
  AnWriteLights(LightOne, 0);
  AnWriteLights(LightTwo, 0);
}





//slowly flash 2 leds from dim to bright
void FlashBuild(int LightOne[], int LightTwo[]) {
  int brightness = 0;
  int fadeAmount = 5;

  do {
    // set the brightness of Light
    AnWriteLights(LightOne, brightness);
    AnWriteLights(LightTwo, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    wait(46);
  } while (brightness < 255);

  AnWriteLights(LightOne, 0);
  AnWriteLights(LightTwo, 0);
}





//preBullets My idea
void preBullets2(int bulletsPower[4]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(bulletsPower[i], HIGH);
    wait(162);
  }
  wait(162);
  digitalWrite(bulletsPower[3], HIGH);
  wait(162);
  DigiLow(bulletsPower);
}





//chorus part (for rygb lights)
void chorus(int Light1[], int Light2[], int Light3[]) {
  DigiHigh(Light1);
  wait(2603);
  DigiLow(Light1);
  DigiHigh(Light2);
  wait(1053);
  DigiLow(Light2);
  DigiHigh(Light3);
  wait(1653);
  DigiLow(Light3);

}






//intimidate my idea
void intimidate2(int bulletsPower[4], int green[], int yellow[], int purple[], int orange[], int stage[], int duel[]) {

  digitalWrite(bulletsPower[0], HIGH);

  DigiHigh(green);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);

  digitalWrite(bulletsPower[0], LOW);
  digitalWrite(bulletsPower[1], HIGH);

  DigiLow(green);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(270);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);

  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[2], HIGH);

  DigiLow(yellow);
  DigiHigh(purple);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(125);
  digitalWrite(bulletsPower[2], LOW);

  DigiLow(purple);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(325);
  digitalWrite(bulletsPower[1], HIGH);

  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[2], HIGH);

  DigiLow(yellow);
  DigiHigh(purple);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(270);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[2], LOW);
  digitalWrite(bulletsPower[3], HIGH);

  DigiLow(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(450);
  digitalWrite(bulletsPower[3], LOW);

  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
}





//reverse intimidate my idea
void intimidate_rev2(int bulletsPower[4], int green[], int yellow[], int purple[], int orange[], int stage[], int duel[]) {

  digitalWrite(bulletsPower[3], HIGH);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], HIGH);

  DigiLow(orange);
  DigiHigh(purple);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(270);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[2], LOW);
  digitalWrite(bulletsPower[1], HIGH);

  DigiLow(purple);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(125);
  digitalWrite(bulletsPower[1], LOW);

  DigiLow(yellow);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(325);
  digitalWrite(bulletsPower[2], HIGH);

  DigiHigh(purple);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[2], LOW);
  digitalWrite(bulletsPower[1], HIGH);

  DigiLow(purple);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(270);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], HIGH);

  DigiLow(yellow);
  DigiHigh(green);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(450);
  digitalWrite(bulletsPower[0], LOW);

  DigiLow(green);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
}



//half intimidate function my idea
void intimidate_half2(int bulletsPower[4], int green[], int yellow[], int purple[], int orange[], int stage[], int duel[]) {
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);

  DigiHigh(green);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  wait(95);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  DigiLow(green);
  DigiLow(yellow);
  AnWriteLights(stage, 0);
  wait(80);
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);
  DigiHigh(green);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  wait(270);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  DigiLow(green);
  DigiLow(yellow);
  AnWriteLights(stage, 0);
  wait(80);
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);
  DigiHigh(green);
  DigiHigh(yellow);
  AnWriteLights(stage, 255);
  wait(125);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  DigiLow(green);
  DigiLow(yellow);
  AnWriteLights(stage, 0);
  wait(325);
  digitalWrite(bulletsPower[2], HIGH);
  digitalWrite(bulletsPower[3], HIGH);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(duel, 255);
  wait(95);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[2], HIGH);
  digitalWrite(bulletsPower[3], HIGH);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(duel, 255);
  wait(270);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[3], HIGH);
  digitalWrite(bulletsPower[2], HIGH);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(duel, 255);
  wait(450);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(duel, 0);
}





//half intimidate with just stage and duel lights
void intimidate_half_sd(int stage[], int duel[]) {
  AnWriteLights(stage, 255);
  wait(95);
  AnWriteLights(stage, 0);
  wait(80);
  AnWriteLights(stage, 255);
  wait(270);
  AnWriteLights(stage, 0);
  wait(80);
  AnWriteLights(stage, 255);
  wait(125);
  AnWriteLights(stage, 0);
  wait(325);
  AnWriteLights(duel, 255);
  wait(95);
  AnWriteLights(duel, 0);
  wait(80);
  AnWriteLights(duel, 255);
  wait(270);
  AnWriteLights(duel, 0);
  wait(80);
  AnWriteLights(duel, 255);
  wait(450);
  AnWriteLights(duel, 0);
}





//intimidate half with stage, duel, and bullet lights my idea
void intimidate_half_sdb2(int bulletsPower[4], int stage[], int duel[]) {
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);
  AnWriteLights(stage, 255);
  wait(95);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  AnWriteLights(stage, 0);
  wait(80);
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);
  AnWriteLights(stage, 255);
  wait(270);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  AnWriteLights(stage, 0);
  wait(80);
  digitalWrite(bulletsPower[1], HIGH);
  digitalWrite(bulletsPower[0], HIGH);
  AnWriteLights(stage, 255);
  wait(125);
  digitalWrite(bulletsPower[1], LOW);
  digitalWrite(bulletsPower[0], LOW);
  AnWriteLights(stage, 0);
  wait(325);
  digitalWrite(bulletsPower[2], HIGH);
  digitalWrite(bulletsPower[3], HIGH);
  AnWriteLights(duel, 255);
  wait(95);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[3], HIGH);
  digitalWrite(bulletsPower[2], HIGH);
  AnWriteLights(duel, 255);
  wait(270);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  AnWriteLights(duel, 0);
  wait(80);
  digitalWrite(bulletsPower[2], HIGH);
  digitalWrite(bulletsPower[3], HIGH);
  AnWriteLights(duel, 255);
  wait(450);
  digitalWrite(bulletsPower[3], LOW);
  digitalWrite(bulletsPower[2], LOW);
  AnWriteLights(duel, 0);
}





//final intimidate on all leds
void INTIMIDATE_FINAL2(int bulletsPower[4], int green[], int yellow[], int purple[], int orange[], int stage[], int duel[]) {
  
  DigiHigh(bulletsPower);
  DigiHigh(green);
  DigiHigh(yellow);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  
  DigiLow(bulletsPower);
  DigiLow(green);
  DigiLow(yellow);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  
  DigiHigh(bulletsPower);
  DigiHigh(green);
  DigiHigh(yellow);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(270);
  
  DigiLow(bulletsPower);
  DigiLow(green);
  DigiLow(yellow);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  
  DigiHigh(bulletsPower);
  DigiHigh(green);
  DigiHigh(yellow);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(125);
  
  DigiLow(bulletsPower);
  DigiLow(green);
  DigiLow(yellow);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(325);
  
  DigiHigh(bulletsPower);
  DigiHigh(green);
  DigiHigh(yellow);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(95);
  
  DigiLow(bulletsPower);
  DigiLow(green);
  DigiLow(yellow);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
  
  DigiHigh(bulletsPower);
  DigiHigh(green);
  DigiHigh(yellow);
  DigiHigh(purple);
  DigiHigh(orange);
  AnWriteLights(stage, 255);
  AnWriteLights(duel, 255);
  wait(850);
  
  DigiLow(bulletsPower);
  DigiLow(green);
  DigiLow(yellow);
  DigiLow(purple);
  DigiLow(orange);
  AnWriteLights(stage, 0);
  AnWriteLights(duel, 0);
  wait(80);
}


static void Play_Music( void )
{
  static const uint8_t Music_Message[] = { 0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x01, 0xEF };
  Serial.write( Music_Message, sizeof(Music_Message) );
}

static void Stop_Music( void )
{
  static const uint8_t Music_Message[] = { 0x7E, 0xFF, 0x06, 0x0C, 0x00, 0x00, 0x01, 0xEF };
  Serial.write( Music_Message, sizeof(Music_Message) );
}



