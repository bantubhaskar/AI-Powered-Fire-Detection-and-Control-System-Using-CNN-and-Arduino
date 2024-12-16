#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <U8g2lib.h>

#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);

  // Initialize the PulseOximeter
  if (!pox.begin()) {
    Serial.println("Could not find MAX30100. Please check wiring/power.");
    while (1);
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA); // Set the LED current to 7.6mA (adjust as needed)

  // Initialize the display
  u8g2.begin();
}

void loop() {
  static uint32_t lastReportTime = 0;

  // Make sure to call update on each loop
  pox.update();

  if (millis() - lastReportTime > REPORTING_PERIOD_MS) {
    lastReportTime = millis();

    // Print heart rate and SpO2 to the serial monitor
    Serial.print("Heart rate: ");
    Serial.print(pox.getHeartRate());
    Serial.print(" bpm / SpO2: ");
    Serial.print(pox.getSpO2());
    Serial.println("%");

    // Display heart rate and SpO2 on OLED screen
    displayData(pox.getHeartRate(), pox.getSpO2());
  }
}

void displayData(float heartRate, float spo2) {
  // Clear the display
  u8g2.clearBuffer();

  // Set font and position for displaying data
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(10, 30);

  // Display heart rate and SpO2
  u8g2.print("Heart Rate: ");
  u8g2.print(heartRate);
  u8g2.print(" bpm");

  u8g2.setCursor(10, 50);
  u8g2.print("SpO2: ");
  u8g2.print(spo2);
  u8g2.print("%");

  // Send the buffer to the display
  u8g2.sendBuffer();
}
