# GPS-Module-Test-Development
A general GPS module test development firmware to test out any old/new modules via UART using arduino software (bare in mind some modules may not be compatible!)

<src img="https://github.com/user-attachments/assets/c0d800c0-cb5a-4a2b-9750-e9f42387217d" width="500">

## Overview

This project is a **GPS test development board** built around the **ESP32** microcontroller. It serves as a versatile tool for testing and evaluating any GPS module via UART. The development board communicates with the GPS module, reads the NMEA data, and displays the current latitude and longitude in real-time through a **web interface**.

This tool is designed to support **multiple GPS modules** and easily allow developers or hobbyists to verify the performance and functionality of GPS devices in different environments.

## Features

- **Universal GPS Module Testing:** Supports any GPS module that communicates via UART (e.g., u-blox, Quectel).
- **Real-Time GPS Data:** Displays live latitude and longitude data in a user-friendly web interface.
- **Customizable Settings:** Allows reconfiguration of UART pins and baud rate through the Serial Monitor.
- **Web Interface:** Access real-time GPS data through a browser by connecting to the ESP32’s local IP address.
- **Easy Setup:** Simple to use and set up, with minimal wiring and configuration required.

## Use Cases

- **Testing New GPS Modules:** Quickly test new or old GPS modules by connecting them to the ESP32 and viewing the data output via UART.
- **GPS Signal Validation:** Check real-time GPS data in different locations (indoors/outdoors) to verify module functionality.
- **GPS Development and Prototyping:** Use this tool to validate and troubleshoot GPS integration in custom embedded systems.

## Requirements

- **Hardware:**
  - ESP32 Development Board (e.g., ESP32 DevKit V1)
  - GPS Module (compatible with UART communication)
  - Jumper wires and a breadboard for prototyping
- **Software:**
  - Arduino IDE with ESP32 board support installed
  - Required libraries: `TinyGPS++`, `WiFi.h`

## Getting Started

1. **Clone the repository** or download the code.
2. **Install the necessary libraries** in the Arduino IDE.
3. **Configure your Wi-Fi settings** in the code (`ssid` and `password`).
4. **Upload the code** to the ESP32 and open the Serial Monitor to check the IP address.
5. **Access the web interface** by entering the ESP32’s IP address into your browser to view real-time GPS data.

## Value and Need

This project provides a **simple, scalable, and portable solution** for anyone needing to test and validate GPS modules. Whether you're working with new GPS hardware, troubleshooting existing systems, or developing embedded GPS-based applications, this tool gives you a quick and accessible way to monitor GPS data in real time. The web interface enhances the user experience, making it easy to view and log location data remotely.

## License

This project is open-source and available for modification and redistribution. You can freely contribute or enhance the functionality based on your needs.
