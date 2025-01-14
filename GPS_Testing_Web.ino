#include <TinyGPS++.h>
#include <WiFi.h>

// Replace with your network credentials
const char *ssid = "YourSSID";
const char *password = "YourPassword";

// Create an instance of the GPS and WiFi
TinyGPSPlus gps;
WiFiServer server(80); // Port 80 for HTTP

// GPS module pins
int gpsRxPin = 16;
int gpsTxPin = 17;
int gpsBaudRate = 9600; // Baud rate for GPS

void setup() {
  Serial.begin(115200); // Serial monitor for debugging
  Serial.println("GPS Test Development Firmware with Web GUI");

  // Initialize GPS module UART
  Serial.println("Initializing GPS...");
  HardwareSerial gpsSerial(1);
  gpsSerial.begin(gpsBaudRate, SERIAL_8N1, gpsRxPin, gpsTxPin);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the web server
  server.begin();
}

void loop() {
  // Handle GPS data
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c);

    if (gps.location.isUpdated()) {
      // If GPS data is updated, log it to Serial and update the web page
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();

      // Serve the web page with current coordinates
      WiFiClient client = server.available();
      if (client) {
        String currentLatitude = String(latitude, 6);
        String currentLongitude = String(longitude, 6);

        String html = "<html><body>";
        html += "<h1>GPS Coordinates</h1>";
        html += "<p>Latitude: " + currentLatitude + "</p>";
        html += "<p>Longitude: " + currentLongitude + "</p>";
        html += "</body></html>";

        // Send the HTTP response
        client.print("HTTP/1.1 200 OK\r\n");
        client.print("Content-Type: text/html\r\n");
        client.print("Connection: close\r\n\r\n");
        client.print(html);
        
        delay(100); // small delay to ensure proper communication
      }
    }
  }
}
