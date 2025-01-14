#include <TinyGPS++.h>
#include <HardwareSerial.h>

// GPS instance
TinyGPSPlus gps;

// Create a UART instance for GPS communication
HardwareSerial gpsSerial(1);

// Default UART configuration
int gpsRxPin = 16;  // RX pin
int gpsTxPin = 17;  // TX pin
int gpsBaudRate = 9600; // Baud rate

void setup() {
  Serial.begin(115200); // Debug Serial
  Serial.println("GPS Test Development Firmware");
  
  // Initialize GPS UART
  gpsSerial.begin(gpsBaudRate, SERIAL_8N1, gpsRxPin, gpsTxPin);
  Serial.println("GPS UART Initialized");
}

void loop() {
  // Handle GPS data
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    Serial.write(c); // Echo raw NMEA data to Serial Monitor
    gps.encode(c);

    if (gps.location.isUpdated()) {
      // Print parsed GPS data
      Serial.println("\n--- GPS Data ---");
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("Altitude: ");
      Serial.println(gps.altitude.meters());
      Serial.print("Satellites: ");
      Serial.println(gps.satellites.value());
      Serial.print("HDOP: ");
      Serial.println(gps.hdop.value());
      Serial.println("----------------");
    }
  }

  // Interactive Serial Menu
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    handleSerialCommand(cmd);
  }
}

// Handle commands for UART configuration
void handleSerialCommand(char cmd) {
  switch (cmd) {
    case 'r': // Change RX pin
      Serial.println("Enter new RX pin:");
      while (!Serial.available());
      gpsRxPin = Serial.parseInt();
      reinitializeGPS();
      break;

    case 't': // Change TX pin
      Serial.println("Enter new TX pin:");
      while (!Serial.available());
      gpsTxPin = Serial.parseInt();
      reinitializeGPS();
      break;

    case 'b': // Change baud rate
      Serial.println("Enter new baud rate:");
      while (!Serial.available());
      gpsBaudRate = Serial.parseInt();
      reinitializeGPS();
      break;

    default:
      Serial.println("Commands:");
      Serial.println("  r - Change RX pin");
      Serial.println("  t - Change TX pin");
      Serial.println("  b - Change baud rate");
      break;
  }
}

// Reinitialize GPS UART with new settings
void reinitializeGPS() {
  gpsSerial.end();
  gpsSerial.begin(gpsBaudRate, SERIAL_8N1, gpsRxPin, gpsTxPin);
  Serial.println("GPS UART Reconfigured");
}
