# Arduino Ultrasonic Sensor Distance Display

## Overview

This Arduino project utilizes an ultrasonic sensor (HC-SR04 or similar) to measure distance and provides visual and auditory feedback based on the measured distance. The distance is displayed on an OLED display (SSD1306) along with controlling LEDs and a buzzer.

## Components Used

- Arduino board (e.g., Arduino Uno)
- OLED display (e.g., SSD1306)
- Ultrasonic sensor (e.g., HC-SR04)
- LEDs (Green, Yellow, Red)
- Buzzer
- Resistors (if necessary)
- Breadboard and jumper wires

## Installation

1. Install the required libraries:
   - Adafruit_SSD1306 for OLED display.
   - NewPing for ultrasonic sensor.
2. Upload the provided Arduino sketch (`Parking_Assistance.ino`) to your Arduino board.

## Usage

1. Power up your Arduino board.
2. The ultrasonic sensor will continuously measure the distance.
3. The distance will be displayed on the OLED display in centimeters.
4. LEDs will light up based on the distance:
   - Green LED: Distance between 10 and 20 cm.
   - Yellow LED: Distance between 5 and 10 cm.
   - Red LED: Distance less than or equal to 5 cm.
5. The buzzer will produce sound based on the distance:
   - Soft sound for distances between 10 and 20 cm.
   - Medium sound for distances between 5 and 10 cm.
   - Loud sound for distances less than or equal to 5 cm.

## Customization

You can customize the code according to your preferences:
- Adjust the pin numbers for the components if necessary.
- Modify the distance thresholds for LED and buzzer control.
- Customize OLED display settings such as text size and color.

## Author

Midy Voong 
Date of upload: February 04 2024
