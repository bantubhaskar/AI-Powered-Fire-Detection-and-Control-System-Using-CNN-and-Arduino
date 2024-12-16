#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <MAX30105.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

MAX30105 particleSensor;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Initialize MAX30105 sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println(F("MAX30105 sensor not found. Please check wiring/power."));
    while (1);
  }

  particleSensor.setup(); // Configure sensor with default settings
}

void loop() {
  // Read the pulse oximeter and display the results on OLED
  sensors_event_t pulseOximeter;

  if (particleSensor.getEvent(&pulseOximeter)) {
    if (pulseOximeter.pulse_detected) {
      Serial.print(F("SpO2: "));
      Serial.print(pulseOximeter.getSpO2());
      Serial.print(F("%, BPM: "));
      Serial.println(pulseOximeter.getHeartRate());

      display.clearDisplay();
      display.setCursor(0, 0);
      display.print(F("SpO2: "));
      display.print(pulseOximeter.getSpO2());
      display.print(F("%"));

      display.setCursor(0, 10);
      display.print(F("BPM: "));
      display.print(pulseOximeter.getHeartRate());

      display.display();
    }
  }

  delay(1000); // You can adjust the delay based on your requirements
}
