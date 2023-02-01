#include <FastLED.h>

//First I define the pin number where the LED is connected, then the number of LEDs that the LED strip contains or I want to use, then the brightness,
//the type of the leds, then the order of the leds: R,G,B, the update time and last is so that the leds turn on.
#define LED_PIN 5 
#define NUM_LEDS 300
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define WAIT_TIME 10000
CRGB leds[NUM_LEDS];

// Here I indicate that the button is connected to pin 3 in the arduino.
const int buttonPin = 3;

// This indicates that there are 100 updates per second in the code
#define UPDATES_PER_SECOND 100

//These are the initial values ​​of these variables. The first ensures that the previous state of the code is saved,
// the second ensures that the led strips are initially off and the third ensures that the value defaults to 0.
int previousButtonStateOn = 1;
int buttonState = 1;//
int colorState = 0; //

//This is a function and is used when starting arduino.
void setup() {  
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  pinMode (buttonPin, INPUT_PULLUP); 
  delay( 3000 ); 
}

//First the current situation is read, when the button is pressed the if is executed, the current button situation is compared with the previous one,
//and it checks if the code has been pressed and increases the value by 1. This causes a new color to appear each time it is pressed.
// I have used a case twice with each color so that when pressing and releasing the color is not different, but 1 color comes.
void loop() {
  int buttonState = digitalRead(buttonPin);
  if(buttonState != previousButtonStateOn){
    previousButtonStateOn = buttonState;
    
    if(previousButtonStateOn == 1){
       colorState++;
       colorState %= 8;
       switch (colorState) {
        case 0: 
        case 1:
          for (int Led=0; Led<NUM_LEDS; Led++) {
            leds[Led] = CRGB::Red;
          }
          break; 
        case 2:
        case 3:
          for (int Led=0; Led<NUM_LEDS; Led++) {
            leds[Led] = CRGB::Green;
          }
          break;
        case 4:
        case 5:
          for (int Led=0; Led<NUM_LEDS; Led++) {
            leds[Led] = CRGB::Blue;
          } 
          break;
        case 6:
        case 7:
          for (int Led=0; Led<NUM_LEDS; Led++) {
            leds[Led] = CRGB::Violet;
          } 
          break;
      }  
      FastLED.show();
    }
    
  }
}
