#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        8 //define pin for neopixels
#define NUMPIXELS 4 // number of neopixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels


int switchPin; //use to read the input from the switch
int buttonPin; //use to read the input from button

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //initialize serial communication
  pinMode(2, INPUT); //switch signal, wire from switch to breakout board from pin 2
  pinMode(4, INPUT); //button signal, wire from button to breadboard from pin 4
  pinMode(7, OUTPUT); //led breakout board, wire from LED to pin 7
  pinMode(8, OUTPUT); //neopixels, wire from neopixels to pin 8

  //neopixel setup
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
   // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  // put your main code here, to run repeatedly:
  switchPin = digitalRead(2); //reading signal from pin 2
  Serial.println(switchPin); //check serial monitor
  buttonPin = digitalRead(4); //reading signal from pin 4
  Serial.println(buttonPin); //check serial monitor


  if(switchPin == HIGH && buttonPin ==HIGH){
    pixels.clear(); // Set all pixel colors to 'off'
    pixels.setPixelColor(0, pixels.Color(150, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 150));
    pixels.setPixelColor(3, pixels.Color(150, 150, 150));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
  else{

    //based on only switch signal
    if(switchPin == HIGH){
      digitalWrite(7, HIGH); //turn LED on
    }
    else{
      digitalWrite(7, LOW); //turn LED off
    }
  
    //based on only button signal
    if(buttonPin == HIGH){
       pixels.clear(); // Set all pixel colors to 'off'
  
      // The first NeoPixel in a strand is #0, second is 1, all the way up
      // to the count of pixels minus one.
      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    
        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    
        pixels.show();   // Send the updated pixel colors to the hardware.
    
        delay(DELAYVAL); // Pause before next pass through loop
      }
    }
    else{
      pixels.clear();
    }
  }
}

//switch pins will be
//middle pin has a pull down resistor(10k) and a wire to the switchPin(2 in this example)
//one of the sides to power
