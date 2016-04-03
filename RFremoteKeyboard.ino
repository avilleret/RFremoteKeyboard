/* 
 RF Remote Keyboard
 
 For the Arduino Leonardo and Micro.
 
 Sends keyboard stroke button is pressed.
 In my case, button is a RF receiver.

 Inspired by :
 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

#define BTNA_PIN 2          // input pin for pushbutton
#define BTNB_PIN 3
#define BTNC_PIN 4
#define BTND_PIN 5
#define DEBOUNCE_TIME 1000 // time to wait before repeating / rescanning

void setup() {
  // make the pushButton pin an input:
  pinMode(BTNA_PIN, INPUT);
  pinMode(BTNB_PIN, INPUT);
  pinMode(BTNC_PIN, INPUT);
  pinMode(BTND_PIN, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read all buttons:
  int btnState = 0;
  
  if ( digitalRead(BTNA_PIN) ) btnState += 1;
  if ( digitalRead(BTNB_PIN) ) btnState += 2;
  if ( digitalRead(BTNC_PIN) ) btnState += 4;
  //if ( digitalRead(BTND_PIN) ) btnState += 8;
  
  switch ( btnState ) {
    case 1:
      Keyboard.print('A');
      delay(DEBOUNCE_TIME);
      break;
    case 2:
      Keyboard.print('B');
      delay(DEBOUNCE_TIME);
      break;
    case 4:
      Keyboard.print('C');
      delay(DEBOUNCE_TIME);
      break;
    case 8:
      Keyboard.print('D');
      delay(DEBOUNCE_TIME);
      break;
     default:
       // more than one key is pressed, don't do anything
       break;
  }
}

