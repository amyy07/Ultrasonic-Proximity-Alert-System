# Ultrasonic Proximity Alert System

## Overview
This project is an Arduino-based ultrasonic proximity warning system that detects the distance of nearby objects through the utilization of an HC-SR04 ultrasonic sensor. The measured distance is displayed on a 16×2 I2C LCD, and simultaneously, a buzzer is integrated to deliver auditory warnings, with beeps that increase in frequency and pitch as the object draws closer, an aspect designed to emulate car parking sensors. The system also displays warning messages to indicate the level of proximity. 

## Features
- Measures distance using an HC-SR04 ultrasonic sensor.
- Displays the measured distance on a 16×2 I2C LCD.
- Provides audible alerts using a buzzer.
- Beeping frequency increases as the object gets closer.
- Beep pitch increases as the object gets closer.
- Displays visual warning messages:
    SAFE – Object is more than 100 cm away.
    WARNING – Object is between 51 cm and 100 cm.
    CLOSE – Object is between 21 cm and 50 cm.
    STOP! – Object is within 20 cm.

## Components
- Arduino Uno
- HC-SR04 ultrasonic sensor
- KY-012/5V active buzzer (see notes)
- 16×2 I²C LCD
- Breadboard
- Jumper wires
- USB cable

## The Deeper Deets: How It Works
1. The HC-SR04 emits an ultrasonic pulse.
2. The echo returned from the nearest object is measured.
3. The Arduino calculates the object's distance.
4. The distance is:
5. Displayed on the LCD.
6. Printed to the Serial Monitor.
7. If an object is detected within 100 cm:
8. The buzzer begins to beep.
9. The beep interval decreases as the object approaches.
10. The buzzer pitch increases as the object approaches.
11. The LCD displays a warning message based on the measured distance.


## Notes
- You can use either the KY-012 module or an active 5V buzzer, though the wiring will slightly differ. The wiring for the latter is shown in the circuit diagram. For the KY-012 module, the signal pin should be connected to the D8 Arduino pin, the middle pin to the 5V pin, and the last to GND. 
- The circuit diagram uses a piezo buzzer symbol because Tinkercad does not have a dedicated 5 V active buzzer component. 
- You have to install the LiquidCrystal_I2C library if you haven't previously used it. Go to Sketch → Include Library → Manage Libraries.
