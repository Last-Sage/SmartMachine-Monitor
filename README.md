# SmartMachine-Monitor

**SmartMachine-Monitor** is an IoT-based solution for monitoring electrical machines. It uses an ESP32 to read and display parameters such as voltage, current, and temperature. The data is accessible via a web page, which you can view and interact with through any internet-connected device.

## Features

- **Real-Time Monitoring:** View voltage, current, and temperature in real-time.
- **Web-Based Interface:** Access and control the system through a web page.
- **Threshold Alerts:** Monitor and respond to over-voltage, over-current, and temperature conditions.
- **Relay Control:** Toggle relay state from the web interface.

## Components

- **ESP32:** Microcontroller for WiFi connectivity and control.
- **ZMPT101B Voltage Sensor:** Measures AC voltage.
- **ACS712 Current Sensor:** Measures AC current.
- **LCD Display (I2C):** Displays real-time data on the device.
- **Relay Module:** Controls electrical devices.
- **LEDs:** Indicators for various states.

## Code Overview

The main code (`code.ino`) includes:

- **Libraries and Setup:** Initializes necessary libraries and WiFi credentials.
- **Web Server Functions:** Defines handlers for web requests to serve HTML pages and read sensor data.
- **Setup and Loop:** Configures WiFi connection and starts the web server. Continuously reads sensor data and updates the display.

The web interface is defined in `index.h`, providing:

- **Real-Time Data Display:** HTML and JavaScript to update and display voltage, current, and temperature.
- **Relay Control:** A button to toggle the relay state on and off.

## Setup Instructions

1. **Configure WiFi Credentials:**
   - Edit `code.ino` and replace `YOUR_NETWORK` and `YOUR_PASSWORD` with your WiFi network’s SSID and password.

2. **Upload Code to ESP32:**
   - Open the Arduino IDE and upload `code.ino` to your ESP32.

3. **Access the Web Interface:**
   - Ensure your device is connected to the same WiFi network as the ESP32.
   - Open a web browser and enter the IP address displayed in the Serial Monitor.

4. **Using the Web Interface:**
   - **View Data:** Voltage, current, and temperature are updated every second.
   - **Control Relay:** Toggle the relay by clicking the ON/OFF button.



