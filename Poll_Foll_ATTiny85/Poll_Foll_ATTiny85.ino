/*

  Código para PollFoll
  by akirasan

  Para programar el ATTiny85
  - Arduno UNO con firmware cargado "ArduinoISP" (se encuentra en el IDE de Arduino como ejemplo)
  - Seleccionar la placa ATTiny85 (Procesador ATTiny85 / Internal 16MHz)
  - Programador "Arduino as ISP"

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            3
#define NUMPIXELS      4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pinMode(PIN, OUTPUT);
  pixels.begin();
  pixels.setBrightness(180);
  pixels.show();

  randomSeed(analogRead(0));

  nuevo_color_fin(0);
  nuevo_color_fin(1);
  nuevo_color_fin(2);
  nuevo_color_fin(3);

}

byte rojo[3] = {255, 0, 0};
byte amarillo[3] = {55, 55, 0};
byte naranja[3] = {55, 40, 30};
byte blanco[3] = {55, 55, 55};
byte apagado[3] = {0, 0, 0};

byte leds[4][3] = {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}};
byte leds_final[4][3] = {{255, 255, 0}, {210, 120, 50}, {255, 0, 0}, {255, 255, 255}};




void mostrar_leds() {
  for (byte i = 0; i < 4; i++) {
    pixels.setPixelColor(i, pixels.Color(leds[i][0], leds[i][1], leds[i][2]));
  }
  pixels.show();
}

void nuevo_color_fin(byte led) {

  byte randNumber = random(5);

  switch (randNumber) {
    case 0:
      leds_final[led][0] = amarillo[0];
      leds_final[led][1] = amarillo[1];
      leds_final[led][2] = amarillo[2];
      break;
    case 1:
      leds_final[led][0] = naranja[0];
      leds_final[led][1] = naranja[1];
      leds_final[led][2] = naranja[2];
      break;
    case 2:
      leds_final[led][0] = rojo[0];
      leds_final[led][1] = rojo[1];
      leds_final[led][2] = rojo[2];
      break;
    case 3:
      leds_final[led][0] = apagado[0];
      leds_final[led][1] = apagado[1];
      leds_final[led][2] = apagado[2];
      break;
    case 4:
      leds_final[led][0] = blanco[0];
      leds_final[led][1] = blanco[1];
      leds_final[led][2] = blanco[2];
      break;

    default:
      leds_final[led][0] = apagado[0];
      leds_final[led][1] = apagado[1];
      leds_final[led][2] = apagado[2];
      break;
  }

}

void ajustar_valor(byte led, byte color) {
  if (leds[led][color] > leds_final[led][color]) {
    leds[led][color]--;
  }
  else {
    leds[led][color]++;
  }
}

void avanzar() {

  for (byte led = 0; led < 4; led++) {
    boolean r = false, g = false, b = false;
    if (leds[led][0] != leds_final[led][0]) {
      ajustar_valor(led, 0);
    }
    else {
      r = true;
    }

    if (leds[led][1] != leds_final[led][1]) {
      ajustar_valor(led, 1);
    }
    else {
      g = true;
    }


    if (leds[led][2] != leds_final[led][2]) {
      ajustar_valor(led, 2);
    }
    else {
      b = true;
    }

    if (r & g & b) {
      nuevo_color_fin(led);
    }

  }

}


void all_off() {
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.show();
}


void test_all() {
  pixels.setPixelColor(0, pixels.Color(55, 0, 0));
  pixels.setPixelColor(1, pixels.Color(55, 0, 0));
  pixels.setPixelColor(2, pixels.Color(55, 55, 0));
  pixels.setPixelColor(3, pixels.Color(55, 55, 55));
  pixels.show();
delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.setPixelColor(3, pixels.Color(0, 255, 0));
  pixels.show();
delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.setPixelColor(1, pixels.Color(0, 0, 255));
  pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  pixels.setPixelColor(3, pixels.Color(0, 0, 255));
  pixels.show();
delay(500);

}



// Colores GRB
void loop() {
  avanzar();
  mostrar_leds();
  delay(5);
//test_all();

}
