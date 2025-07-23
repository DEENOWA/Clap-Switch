# ClapSwitch

## Project Overview
ClapSwitch is an Arduino-based project that uses a sound sensor to detect claps and control an LED. A single clap turns the LED on, and two claps within 500 milliseconds turn it off. The system includes debouncing to prevent false triggers and outputs status messages to the Serial Monitor.

## Components and Features
- **Components**:
  - Sound sensor (e.g., KY-038 or similar)
  - LED
  - Arduino Board (e.g., Uno)
  - Resistor (220–330 ohm for LED)
  - Jumper wires
  - Breadboard (optional)
- **Features**:
  - Detects claps using a sound sensor.
  - Turns LED on with one clap.
  - Turns LED off with two claps within 500 ms.
  - Includes debouncing to avoid false triggers.
  - Outputs clap count and LED status to the Serial Monitor.

## Hardware Requirements
- Arduino Uno (or compatible board)
- Sound sensor module (e.g., KY-038 with digital output)
- LED
- 220–330 ohm resistor
- Jumper wires
- Breadboard (optional)

## Setup Instructions
1. **Wiring**:
   - Connect the sound sensor:
     - VCC to Arduino 5V
     - GND to Arduino GND
     - OUT (digital output) to Pin 3
   - Connect the LED:
     - Anode (longer leg) to Pin 2 via a 220–330 ohm resistor
     - Cathode (shorter leg) to Arduino GND
2. **Software**:
   - Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).
   - Copy the `src/clapswitch.ino` code into the Arduino IDE.
   - No additional libraries are required.
3. **Upload**:
   - Connect your Arduino to your computer via USB.
   - Upload the code to your Arduino board.

## Usage Instructions
1. Open the Serial Monitor in the Arduino IDE (set to 9600 baud).
2. The system will:
   - Display “System ready. One clap to turn LED ON, two claps to turn OFF.” on startup.
   - Detect claps and print the clap count and LED status to the Serial Monitor.
   - Turn the LED on with one clap.
   - Turn the LED off with two claps within 500 ms.
   - Reset the clap count if the sequence is incomplete after 500 ms.
3. Clap near the sound sensor to test the LED control.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Suggestions for new features or bug fixes are welcome!
