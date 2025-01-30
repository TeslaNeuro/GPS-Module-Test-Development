#include <TinyGPSPlus.h>

// Define GPS UART pins (adjust as needed)
static const int RXPin = 16;  // GPIO16 (RX)
static const int TXPin = 17;  // GPIO17 (TX)
static const uint32_t GPSBaud = 9600;
unsigned int totalBytes = 0;  // Total bytes per second
unsigned int sentenceSize = 0;  // Size of current sentence
unsigned long lastTime = 0;

// The TinyGPSPlus object
TinyGPSPlus gps;

// Use Hardware Serial (Serial2) instead of SoftwareSerial
HardwareSerial gpsSerial(2); // UART2

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin); // Set baud rate and pins

  Serial.println(F("ESP32 GPS Raw Data Logger"));
  Serial.println(F("Listening to GPS module..."));
}

void loop() {
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    totalBytes++;  
    sentenceSize++;
    Serial.write(c);  // Print raw data

    // NMEA sentences end with '\n' (newline)
    if (c == '\n') {  
      Serial.print("\nSentence size: ");
      Serial.println(sentenceSize);
      sentenceSize = 0;  // Reset for next sentence
    }
  }

  // Print total bytes received every second
  if (millis() - lastTime >= 1000) {
    Serial.print("\nTotal bytes received in last second: ");
    Serial.println(totalBytes);
    totalBytes = 0;  // Reset counter
    lastTime = millis();
  }
}