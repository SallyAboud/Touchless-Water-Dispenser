# Touchless Water Dispenser

This project presents the design and implementation of a touchless water dispenser using the ATmega32 microcontroller and an HC-SR04 ultrasonic sensor. It aims to promote hygiene by eliminating physical contact, making it ideal for public spaces such as schools, hospitals, and offices.

## How It Works
The system detects a hand within 10 cm using the ultrasonic sensor. When a hand is present, the ATmega32 activates a relay to power a 5V water pump, dispensing water automatically. A 16x2 LCD provides real-time feedback:  
- Displays the measured distance on the first row  
- Shows "Place Your Hand" or "Dispensing" on the second row based on the hand's presence  

## Components
- ATmega32 Microcontroller  
- HC-SR04 Ultrasonic Sensor  
- 16x2 LCD Display  
- Relay Module  
- 5V DC Water Pump  
- Power Bank (for portability)

## Development Tools
- *IDE*: Eclipse  
- *Compiler*: AVR-GCC  
- *Programmer*: eXtreme Burner-AVR (ETA32)

## Features
- Fully automated, contactless operation  
- Portable (runs on a power bank)  
- Real-time sensor-based control  
- Clear LCD user feedback

## Demo Video & Files
- [Project Video](https://drive.google.com/file/d/1f-oQlTHfTlLFaaCcN6udeOH1u7f5LBPS/view?usp=drive_link)  
- [Proteus Simulation](https://drive.google.com/file/d/1LE7eMXZo8yXTJAjkKe3Am5omCQIoqoHp/view?usp=drive_link)

## License
This project is for educational and non-commercial use.
