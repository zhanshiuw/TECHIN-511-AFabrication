# TECHIN-511-AFabrication

Title: Light-up Painting

Overview: The Light-up painting comprises a custom easel made from reclaimed red wine barrel staves and Fir framing boards taken from a house in West Seattle, a picture frame made from stained plywood, and art hand painted over a rastered acrylic sheet. The frame includes built in electronics and LEDs that light the painting from behind, accentuating its features. The easel’s base includes a 3D printed port which connects to an inverse port housed in the base of the frame. A successful connection between the two ports brings the painting to colorful life.

Overall design structure:
The design is about two part: 
1. First part is controlled by a Feather 328p. 
2. The second part is built by three circuit playground express, and the board in second part is controlled seperatelly.
3. The software design and method in the three circuit playground express board and feather 328p board is similar. We setup the input and output pin at the beginning once circuit runs. Then, the microcontroller is in a loop forever. At the beginning of the loop, we reset all signals in input into high. Then, we read the input if the signal is low. If it is high, it means our painting did not connect to the holder, so we setup our microcontroller to first mode. If it is low, it means our microcontroller is able to read the ground from the other part, so the painting is connected to the holder. We set up our microcontroller into mode B.


Feather 328p:
The base part is about the feather 328p. This part is compiled by arduino. You could upload the code by arduino. Also, you can find the code bellow.


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


Circuit playground express:
The canvas part is drived by three circuit playground express boards. You can find the specific boad with the file name. The programming language is about javascript. You can simply put the file into the board，or you can find the code bellow.


Three circuit playground express(Javascript):
Sun part:

forever(function () {
    pins.A7.digitalWrite(true)                            //set up the input pin into high
    if (pins.A7.digitalRead()) {                          //If the input pin is low run first mode
        light.setBrightness(15)                          
        light.setAll(0x999999)
    } else {                                                       //if the input pin is high run second mode
        light.setBrightness(255)
        light.setPixelColor(1, 0xffff00)
        light.setPixelColor(2, 0xffff00)
        light.setPixelColor(3, 0xffff00)
        light.setPixelColor(0, 0xffff00)
        light.setPixelColor(4, 0xffff00)
        light.setPixelColor(6, light.rgb(0, 255, 255))
        light.setPixelColor(8, light.rgb(0, 255, 255))
        light.setPixelColor(5, 0xffff00)
        light.setPixelColor(7, 0xff00ff)
        light.setPixelColor(9, 0xff00ff)
    }
})


Cloud:
forever(function () {                                        
    pins.A7.digitalWrite(true)                          //set up the input pin into high
    if (pins.A7.digitalRead()) {                         //If the input pin is low run first mode  
        light.setBrightness(15)
        light.setAll(0x999999)
    } else {                                                       //if the input pin is high run second mode
        light.setBrightness(206)
        light.setPixelColor(0, light.rgb(0, 255, 255))
        light.setPixelColor(2, light.rgb(0, 255, 255))
        light.setPixelColor(4, light.rgb(0, 255, 255))
        light.setPixelColor(6, light.rgb(0, 255, 255))
        light.setPixelColor(8, light.rgb(0, 255, 255))
        light.setPixelColor(1, 0xff00ff)
        light.setPixelColor(3, 0xff00ff)
        light.setPixelColor(5, 0xff00ff)
        light.setPixelColor(7, 0xff00ff)
        light.setPixelColor(9, 0xff00ff)
    }
})

River part:
forever(function () {
    pins.A7.digitalWrite(true)              //set up the input pin into high
    if (pins.A7.digitalRead()) {           //If the input pin is low run first mode  
        light.setBrightness(15)
        light.setAll(0x999999)
    } else {                                        //if the input pin is high run second mode
        light.setBrightness(103)
        light.setAll(light.rgb(31, 84, 171))
    }
})


