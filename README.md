# Fire Fighting Robot

## Overview

This Fire Fighting Robot is designed to detect and extinguish small fires automatically. It uses infrared (IR) sensors to locate the fire and a water pump system to put it out. The robot moves toward the fire, determines its exact location, and sprays water to extinguish it.

## Features

- Automatic fire detection using IR sensors
- Directional movement based on sensor readings
- Water spraying system controlled via a servo motor
- Simple and efficient fire extinguishing mechanism

## Components Used

- **Microcontroller**: Arduino/ESP8266
- **Sensors**: 3x IR sensors (Front, Left, Right)
- **Motors**: DC motors for movement, Servo motor for water spray control
- **Pump**: Small water pump
- **Power Supply**: 12V Battery (or as required)

## How It Works

1. **Fire Detection**:

   - If any sensor detects fire (IR reading < 700), the robot moves toward the fire.
   - If the fire is very close (IR reading < 30), the robot stops and activates the pump.

2. **Direction Control**:

   - If the front sensor detects fire, the robot moves forward.
   - If the left sensor detects fire, the robot turns right until the front sensor aligns with the fire.
   - If the right sensor detects fire, the robot turns left until the front sensor aligns with the fire.

3. **Fire Extinguishing**:

   - The robot stops in front of the fire.
   - The servo motor oscillates to spray water evenly.
   - Once the fire is extinguished, the robot resumes its scanning mode.

## Limitations

- Uses basic IR sensors, which may not detect high-temperature flames accurately.
- Limited water capacity in the onboard tank.
- Designed for small fire extinguishing demonstrations only.

## Usage

1. Upload the provided Arduino code to the microcontroller.
2. Connect the sensors, motors, pump, and power supply as per the circuit diagram.
3. Power on the robot and let it scan for fire sources.
4. Observe its movement and extinguishing mechanism in action.

## Files Included

- `README.md` (This documentation file)
- `LICENSE` (License information, optional)
- `fire_fighting_robot.ino` (Arduino source code)

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Author

Md Shaifulla Zibon

📧 Email: mdshaifullazibon11\@gmail.com

## Disclaimer

This robot is a prototype and should not be used for real-life fire emergencies. It is meant for educational and research purposes only.

