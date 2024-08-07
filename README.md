# SmartMachine-Monitor

**SmartMachine-Monitor** is an IoT-based solution for monitoring electrical machines. It provides real-time data on voltage, current, and temperature, which can be displayed either through a web page or via the Blynk IoT platform.

## Features

- **Real-Time Monitoring:** View voltage, current, and temperature data.
- **Web-Based Interface:** Access and control the system through a web page.
- **Blynk IoT Integration:** Use the Blynk app to monitor and control the device.
- **Threshold Alerts:** Monitor and respond to over-voltage, over-current, and temperature conditions from web interface or Blynk app.
- **Relay Control:** Toggle relay state from either the web interface or Blynk app.

## Components

- **ESP32:** Microcontroller for WiFi connectivity and control.
- **ZMPT101B Voltage Sensor:** Measures AC voltage.
- **ACS712 Current Sensor:** Measures AC current.
- **LCD Display (I2C):** Displays real-time data on the device.
- **Relay Module:** Controls electrical devices.
- **LEDs:** Indicators for various states.
- **LM35 Temperature Sensor:** Measures temperature.

## Code Overview

### Web-Based Version (`code.ino`)

- **Libraries and Setup:** Initializes necessary libraries and WiFi credentials.
- **Web Server Functions:** Defines handlers for web requests to serve HTML pages and read sensor data.
- **Setup and Loop:** Configures WiFi connection and starts the web server. Continuously reads sensor data and updates the display.

#### HTML Interface (`index.h`)

- **Real-Time Data Display:** HTML and JavaScript to update and display voltage, current, and temperature.
- **Relay Control:** A button to toggle the relay state on and off.

### Blynk IoT Version (`code_blynk.ino`)

- **Libraries and Setup:** Includes Blynk library for integration with the Blynk app.
- **Blynk Functions:** Defines virtual pins for data communication between ESP32 and Blynk app.
- **Setup and Loop:** Configures WiFi and Blynk connection. Continuously reads sensor data, sends it to Blynk, and updates the LCD display.

## Setup Instructions

### For Web-Based Version

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

### For Blynk IoT Version

1. **Set Up Blynk:**
   - Install the Blynk app on your mobile device.
   - Create a new project in the Blynk app and select ESP32 as the device.
   - Note the `Auth Token`, `Blynk Template ID`, and `Template name`.

2. **Configure Blynk Credentials:**
   - Edit `code_blynk.ino` and replace `<Blynk Template ID>`, `<Template name>`, and `<Auth token>` with the values from the Blynk app.
   - Update the `ssid` and `pass` variables with your WiFi credentials.

3. **Upload Code to ESP32:**
   - Open the Arduino IDE and upload `code_blynk.ino` to your ESP32.

4. **Using the Blynk App:**
   - Open the Blynk app and add widgets corresponding to virtual pins (V0, V2, V3, V5) used in the code.
   - Monitor and control the device through the Blynk app interface.

