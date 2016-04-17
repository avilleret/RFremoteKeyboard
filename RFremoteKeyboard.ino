/*
  RF Remote Keyboard

  For the Arduino Leonardo and Micro.

  Sends keyboard stroke when button is pressed.
  In my case, button is a RF receiver.

  Inspired by :
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/
#include <Keyboard.h>

#define BTNA_PIN 3          // input pin for pushbutton
#define BTNB_PIN 4
#define BTNC_PIN 5
#define BTND_PIN 6
#define VT_PIN 2
#define DEBOUNCE_TIME 500 // time to wait before repeating / rescanning

void setup() {
  // make the pushButton pin an input:
  pinMode(BTNA_PIN, INPUT);
  pinMode(BTNB_PIN, INPUT);
  pinMode(BTNC_PIN, INPUT);
  pinMode(BTND_PIN, INPUT);
  pinMode(VT_PIN, OUTPUT);
  digitalWrite(VT_PIN, LOW);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read all buttons:
  int btnState = 0;

  if ( digitalRead(BTNA_PIN) ) btnState += 1;
  if ( digitalRead(BTNB_PIN) ) btnState += 2;
  if ( digitalRead(BTNC_PIN) ) btnState += 4;
  if ( digitalRead(BTND_PIN) ) btnState += 8;

  switch ( btnState ) {
    case 1:
      Keyboard.press(' ');
      Keyboard.releaseAll();
      delay(DEBOUNCE_TIME);
      break;
    case 2:
      Keyboard.press('#');
      Keyboard.releaseAll();
      delay(DEBOUNCE_TIME);
      break;
    case 4:
      Keyboard.press('[');
      Keyboard.releaseAll();
      delay(DEBOUNCE_TIME);
      break;
    case 8:
      Keyboard.press('D');
      Keyboard.releaseAll();
      delay(DEBOUNCE_TIME);
      break;
    default:
      // more than one key is pressed, don't do anything
      break;
  }
}

