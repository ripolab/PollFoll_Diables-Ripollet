/*

  #NOMASSEMAFOROS
  Código para demo badged de NoMasSemaforos
  by akirasan

  Para programar el ATTiny85:
  - Arduno UNO con firmware cargado "ArduinoISP" (se encuentra en el IDE de Arduino como ejemplo)
  - Seleccionar la placa ATTiny85 (Procesador ATTiny85 / Internal 16MHz)
  - Programador "Arduino as ISP"

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            3
#define PIN_BOTON      2
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


byte click_boton = 0;
unsigned int estado_boton;


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pinMode(PIN, OUTPUT);
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show();

}


// Colores GRB
void loop() {


  estado_boton = analogRead(PIN_BOTON);

  // click boton
  if (estado_boton == 1023 ) {
    click_boton++;
    delay(500);
  }


  switch (click_boton) {
    case 1:
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(180, 180, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.show();
      delay(250);
      break;
    case 2:
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.setPixelColor(1, pixels.Color(255, 0, 0));
      pixels.setPixelColor(2, pixels.Color(255, 0, 0));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(180, 180, 0));
      pixels.setPixelColor(1, pixels.Color(180, 180, 0));
      pixels.setPixelColor(2, pixels.Color(180, 180, 0));
      pixels.show();
      delay(250);

      break;
    case 3:
      pixels.setPixelColor(0, pixels.Color(255, 255, 255));
      pixels.setPixelColor(1, pixels.Color(255, 255, 255));
      pixels.setPixelColor(2, pixels.Color(255, 255, 255));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(155, 155, 155));
      pixels.setPixelColor(1, pixels.Color(155, 155, 155));
      pixels.setPixelColor(2, pixels.Color(155, 155, 155));
      pixels.show();
      delay(500);
      pixels.setPixelColor(0, pixels.Color(55, 55, 55));
      pixels.setPixelColor(1, pixels.Color(55, 55, 55));
      pixels.setPixelColor(2, pixels.Color(55, 55, 55));
      pixels.show();
      delay(500);

      break;
    
    
    default:
      click_boton = 1;
      break;
  }

}
