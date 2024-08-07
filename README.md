# SmartMachine-Monitor
Electrical Machine Monitor is an IoT-based solution using ESP32 and BLYNK for real-time monitoring and protection of electrical machines. Track voltage, current, and temperature, and receive alerts for over-current, over-voltage, and over-temperature conditions. Control your machines remotely via the BLYNK app for enhanced safety and performance.

## Overview

This project provides a solution for remote operation and monitoring of electrical machines using the ESP32 microcontroller and the BLYNK IoT platform. It includes functionalities for measuring voltage, current, and temperature, and displays the data on an LCD as well as the BLYNK dashboard. The system also features alerts for over-current, over-voltage, and over-temperature conditions.

## Features

- Real-time monitoring of voltage, current, and temperature.
- Remote control of machines using BLYNK IoT.
- Alerts for over-current, over-voltage, and over-temperature conditions.

## Hardware Components

- ESP32 Microcontroller
- ACS712 Current Sensor
- LM35 Temperature Sensor
- Relay Module
- LCD Display (I2C)
- LEDs for status indication

## Software Components

- Arduino IDE
- BLYNK IoT Platform

## Circuit Diagram

![Circuit Diagram](images/circuit_diagram.png)

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/your-username/Electrical-Machine-Monitor.git
    cd Electrical-Machine-Monitor
    ```

2. **Open `code/main.ino` in Arduino IDE.**

3. **Install necessary libraries:**
    - Blynk
    - LiquidCrystal_I2C

4. **Configure BLYNK:**
   - Open the BLYNK app on your smartphone.
   - Create a new project and select the ESP32 device.
   - Copy the authentication token provided by BLYNK and replace the placeholder in the code (`auth` variable) with your token.
   - Set up the virtual pins (`V0`, `V2`, `V3`, `V5`) in the BLYNK app according to the sensors and controls in your project. The configuration of these virtual pins should match how they are used in the code.

5. **Upload the code to ESP32.**

## Usage

- Connect the ESP32 to Wi-Fi.
- Open the BLYNK app and connect using the provided authentication token.
- Monitor the electrical parameters on the BLYNK dashboard and LCD.
- Control the machine remotely using the BLYNK app.

