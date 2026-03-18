#include <Arduino.h>
// HacKitsune 2026

// Turn your Hackitsune Wardriver module into a dedicated GPS bridge 
// for the Flipper Zero — streaming live position data directly into 
// the Flipper’s GPIO GPS app, while also exposing NMEA output over USB 
// for PC use.

// L86 GPS on UART1
static const int GPS_RX_PIN = 21;  // ESP receives from L86 TXD1
static const int GPS_TX_PIN = 9;   // ESP transmits to L86 RXD1

// Flipper on UART0
// ESP32-S3 default UART0 pins:
static const int FLIPPER_TX_PIN = 43; // ESP -> Flipper RX (pin 14)
static const int FLIPPER_RX_PIN = 44; // ESP <- Flipper TX (pin 13)

HardwareSerial GPS(1);
HardwareSerial FlipperUart(0); // UART0 on GPIO43/44

static const uint32_t USB_BAUD = 115200;
static const uint32_t GPS_BAUD = 9600;
static const uint32_t FLIPPER_BAUD = 9600;

void setup() {
  // Native USB debug
  Serial.begin(USB_BAUD);

  unsigned long start = millis();
  while (!Serial && (millis() - start < 5000)) {
    delay(10);
  }

  Serial.println();
  Serial.println("=== ESP32-S3 GPS -> Flipper bridge ===");
  Serial.println("GPS UART1: RX=21 TX=9 @ 9600");
  Serial.println("Flipper UART0: TX=43 RX=44 @ 9600");
  Serial.println("Connect ESP GPIO43 -> Flipper pin 14 (RX)");
  Serial.println("Connect ESP GPIO44 <- Flipper pin 13 (TX)");
  Serial.println("Common ground required.");
  Serial.println();

  GPS.begin(GPS_BAUD, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  FlipperUart.begin(FLIPPER_BAUD, SERIAL_8N1, FLIPPER_RX_PIN, FLIPPER_TX_PIN);

  delay(200);
}

void loop() {
  // GPS -> Flipper + USB debug
  while (GPS.available()) {
    int c = GPS.read();
    FlipperUart.write(c);
    Serial.write(c);
  }

  // Optional: Flipper -> GPS passthrough
  while (FlipperUart.available()) {
    int c = FlipperUart.read();
    GPS.write(c);
    Serial.write(c);
  }

  delay(1);
}
