# Voice-Controlled Vehicle Using Arduino Uno 🚗🔊

This project demonstrates a **voice-controlled vehicle** using an **Arduino Uno**, an **HC-05 Bluetooth module**, motor drivers, and an **ultrasonic sensor** for obstacle detection. The vehicle responds to **voice commands** sent via a **Bluetooth-enabled smartphone** and stops automatically if an obstacle is detected.

## Features ✨
✔ **Voice-Controlled Movement**: Supports "forward", "back", "left", and "right" commands.  
✔ **Obstacle Detection**: Automatically stops when an obstacle is within **20 cm**.  
✔ **Bluetooth Communication**: Uses an **HC-05/HC-06** module for **wireless control**.  
✔ **Motor Control**: Uses **L298N** or **H-Bridge** to control **two DC motors**.  
✔ **Real-Time Distance Measurement**: **HC-SR04** ultrasonic sensor detects obstacles.  

## Components Required 🔩
| Component                   | Quantity |
|-----------------------------|----------|
| Arduino Uno                 | 1        |
| HC-05 Bluetooth Module      | 1        |
| L298N Motor Driver          | 1        |
| DC Motors                   | 2        |
| Ultrasonic Sensor (HC-SR04) | 1        |
| 9V or 12V Battery           | 1        |
| Jumper Wires                | As needed |

## Circuit Diagram 🔌
### HC-05 Bluetooth Module:
- **VCC** → **5V**
- **GND** → **GND**
- **TX** → **RX (Pin 0)**
- **RX** → **TX (Pin 1)**

### Motor Driver (L298N) to Arduino:
- **IN1 (Motor A)** → **D3**
- **IN2 (Motor A)** → **D4**
- **IN3 (Motor B)** → **D5**
- **IN4 (Motor B)** → **D6**

### Ultrasonic Sensor (HC-SR04) to Arduino:
- **VCC** → **5V**
- **GND** → **GND**
- **TRIG** → **D7**
- **ECHO** → **D8**

## Code Implementation 💻
The Arduino code listens for **voice commands** via **serial communication** from the **HC-05 module**. It then controls motor directions accordingly. The **ultrasonic sensor** continuously checks for obstacles, stopping the vehicle if an object is detected within **20 cm**.

### Core Functions:
- **moveRobot()**: Moves the vehicle in the desired direction.
- **stopRobot()**: Stops all motors.
- **detectObstacle()**: Measures distance using HC-SR04 and prevents collisions.

## How to Use 📱
1. **Upload the Code**: Flash the provided **Arduino sketch** onto the **Arduino Uno**.
2. **Pair Bluetooth**: Connect the **HC-05 module** to your **smartphone** via **Bluetooth settings**.
3. **Use a Voice Control App**: Download any **Bluetooth voice command app** (e.g., *Arduino Bluetooth Voice Controller*).
4. **Give Commands**: Speak **"forward"**, **"back"**, **"left"**, **"right"**, and the vehicle will move accordingly.
5. **Obstacle Detection**: If an obstacle is within **20 cm**, the vehicle **stops automatically**.

## Future Improvements 🚀
- **Add speed control** using **PWM**.
- **Implement a voice feedback system** for responses.
- **Upgrade to ESP32** for **Wi-Fi control**.

## License 📜
This project is licensed under the **MIT License** – feel free to use, modify, and distribute it with attribution.

---
🚀 **Get Started Today and Build Your Own Voice-Controlled Robot!**

