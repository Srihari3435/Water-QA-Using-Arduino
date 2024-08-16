# Water-QA-Using-Arduino
This repository contains the code and schematics for a water quality detection system based on an Arduino Nano. The project uses temperature, pH, and TDS sensors to measure and monitor the quality of water. The system provides real-time data, making it a valuable tool for environmental monitoring, aquariums, hydroponics, and more.


# Introduction
Maintaining water quality is critical for various applications, including drinking water, aquaculture, and agriculture. This project aims to provide an affordable and easy-to-use solution for monitoring water quality using an Arduino Nano. The system measures temperature, pH levels, and TDS, which are essential indicators of water quality.

# Features
Real-Time Monitoring: Continuously measures water temperature, pH levels, and TDS values.

Display: Outputs the readings on an LCD or serial monitor.

Calibration: Allows calibration of sensors for accurate measurements.

Compact Design: Utilizes the small and versatile Arduino Nano.

# Components Required
Arduino Nano

pH Sensor Module

TDS Sensor Module

Temperature Sensor (e.g., DS18B20 or LM35)

16x2 LCD Display (optional)

Breadboard and Jumper Wires

Power Supply (e.g., 9V battery or USB power)


# Usage
Once the circuit is connected and the code is uploaded:

Power the Arduino: You can power it via USB or an external power source.

Monitor the Readings: Readings will be displayed on the serial monitor or the connected LCD display.

Interpret the Results:

Temperature: Measured in degrees Celsius.

pH Level: A value typically between 0 and 14, where 7 is neutral, below 7 is acidic, and above 7 is basic.

TDS: Measured in ppm (parts per million), indicating the concentration of dissolved solids in the water.

# Code Explanation

setup(): Initializes the sensors and LCD display. Also sets up the serial communication.

loop(): Continuously reads the sensor values, calculates the corresponding water quality metrics, and displays the results.

Sensor Functions: Each sensor has a dedicated function for reading and converting raw data into meaningful values.


# Troubleshooting
Inaccurate Readings: Ensure sensors are calibrated correctly. Double-check all wiring connections.

LCD Display Issues: Verify the wiring and contrast adjustment on the LCD. Ensure the LCD library is installed and correctly referenced in the code.

No Serial Output: Make sure the correct COM port is selected in the Arduino IDE

# Contact
If you have any questions or suggestions, feel free to reach out:

Name: Srihari

Email: sriharijk2004@gmail.com

GitHub: https://github.com/Srihari3435
