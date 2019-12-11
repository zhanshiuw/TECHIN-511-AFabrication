// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// On Trinket or Gemma, suggest changing this to 1

int inPin = 7;     //set up pinin;
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 2 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(inPin, INPUT);

}

void loop() {
  digitalWrite(inPin, HIGH);                  //set the inPin to high
  if (digitalRead(inPin) == LOW) {            //read the inPin is connected to Ground or not, if it is then select the first mode, otherwise select the second mode
    modelNormalGreen();
    }
  else {
    modelNormalRed();
    }
}

void modelNormalRed() {
  pixels.clear();       //clear
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright red color:
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
  // Send the updated pixel colors to the hardware.
  }
  pixels.show();  //Show color on neopixels.
}

void modelNormalGreen() {
  pixels.clear();       //clear
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
  // Send the updated pixel colors to the hardware.
  }
  pixels.show(); //Show color on neopixels.
}

void modelBlink() {
  pixels.clear(); // Set all pixel colors to 'off'  
  pixels.show();  //show initianlize successfully. 
  delay(500);    
  
  
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    digitalWrite(inPin, HIGH);
    if (digitalRead(inPin) == HIGH) {
      break;
    }
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(500);
     // Pause before next pass through loop
  }
  
}
