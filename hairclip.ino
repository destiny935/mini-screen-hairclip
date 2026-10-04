#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

#define BUTTON_PIN 4

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

int currentScreen = 0;
const int totalScreens = 3;

void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (true);
  }

  display.clearDisplay();
  display.display();

  showScreen();
}

void loop() {

  // Button is pressed when the pin becomes LOW
  if (digitalRead(BUTTON_PIN) == LOW) {
    currentScreen++;
    if (currentScreen >= totalScreens) {
      currentScreen = 0;
    }

    showScreen();

    // Wait until button is released
    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10);
    }

    // Small debounce delay
    delay(50);
  }
}

void showScreen() {

  display.clearDisplay();

  if (currentScreen == 0) {
    drawHeart();
  }
  else if (currentScreen == 1) {
    drawStar();
  }
  else if (currentScreen == 2) {
    drawSmile();
  }
  display.display();
}
//cycles throgh different display options when button is pressed
