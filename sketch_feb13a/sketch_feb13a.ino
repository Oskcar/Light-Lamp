#include Adafruit_NeoPixel.h
#ifdef __AVR__
#include avrpower.h
#endif
#define PIN            5
#define NUMPIXELS      8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}
int x;
void loop() {


  for (int x = 0; x  256; x++) {
    for (int i = 0; i  NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(255-x, 255+x, 0));
      pixels.show();
      delay(10);
      pixels.setPixelColor(i, pixels.Color(255+x, 255+x, 0));
      pixels.show();
      delay(5);
    }
    delay(5);
    pixels.show();
  }
}
