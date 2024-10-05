# Self-Stabilizing Spoon

This project demonstrates a self-stabilizing spoon that compensates for hand tremors or unwanted movements using servo motors and an MPU6050 gyroscope and accelerometer sensor. The system detects the spoon's tilt in real-time and adjusts the position of the spoon to keep it stable, making it useful for individuals with tremors or motor control issues.

## Features
- Real-time tilt detection using the MPU6050 sensor.
- X-axis and Y-axis stabilization using servo motors.
- Adjustable center positions for fine-tuning the stabilization behavior.
- Lightweight and efficient code for responsive control.

## Components Used
- [MPU6050](https://www.invensense.com/products/motion-tracking/6-axis/mpu-6050/) (6-axis Gyroscope + Accelerometer)
- 2x Servo motors (for X and Y axis)
- Arduino (any model with sufficient pins, e.g., Arduino Uno, Nano, etc.)
- Connecting wires
- Spoon (or similar object to stabilize)



### Connections:
- **MPU6050**:  
  - VCC -> 5V (on Arduino)  
  - GND -> GND (on Arduino)  
  - SDA -> A4 (on Arduino)  
  - SCL -> A5 (on Arduino)
- **Servo Motors**:  
  - ServoX -> Pin 10 (on Arduino)  
  - ServoY -> Pin 9 (on Arduino)  
  - VCC -> 5V  
  - GND -> GND

