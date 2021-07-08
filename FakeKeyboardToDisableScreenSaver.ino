/*
 * Notes:
 * 
 * 1. You need to download a ZIP of the GitHub
 *    https://github.com/NicoHood/HID
 *    Install it a library in Arduino
 *
 * 2. You have to use a special Arduino, such as an Arduino Leonardo or compatible
 *    I bought on ebay something like "Atmega32U4 Beetle DM BadUSB Development Board"
 */

#include "HID-Project.h"

void setup() {
  // initialize control over the keyboard:
  Keyboard.begin();
}

#define SECOND ((uint16_t)1000)
#define MINUTE (((uint16_t)60) * SECOND)
#define DELAY_BETWEEN_PRESSES_IN_MINUTES 10
#define PRESS_TIME 15

#define KEY_KEYPAD_NUMLOCK 0x53

/*
 * Because this is a 16bit integer CPU, we can't use unsigned integer
 * values of more than 65535, which is just about 60,000 = 60 seconds.
 * So let's wait in minutes.
 */
void delay_minutes(uint16_t const seconds)
{
  for(int i=0; i<seconds; ++i)
  {
    delay(MINUTE);
  }
}

void loop() {
  delay_minutes(DELAY_BETWEEN_PRESSES_IN_MINUTES);
  Keyboard.press(HID_KEYPAD_NUM_LOCK_AND_CLEAR);
  delay(PRESS_TIME);
  Keyboard.release(HID_KEYPAD_NUM_LOCK_AND_CLEAR);
  delay(PRESS_TIME);
  Keyboard.press(HID_KEYPAD_NUM_LOCK_AND_CLEAR);
  delay(PRESS_TIME);
  Keyboard.release(HID_KEYPAD_NUM_LOCK_AND_CLEAR);
  
}
