#include "Wire.h"
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;
float roll = 0, pitch = 0;
int servoXCenter = 90; // Center position for X-axis servo
int servoYCenter = 90; // Center position for Y-axis servo

Servo servoX; // Servo motor for X-axis stabilization
Servo servoY; // Servo motor for Y-axis stabilization

void setup() {
  Serial.begin(9600);
  Wire.begin();
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
  
  servoX.attach(10); // Attach X-axis servo to pin 9
  servoY.attach(9); // Attach Y-axis servo to pin 10
}
void loop() {
  mpu.update();
  if ((millis() - timer) > 10) { // print data every 10ms    
    roll = mpu.getAngleX();
    pitch = mpu.getAngleY();
    Serial.print("X : ");
    Serial.print(roll);
    Serial.print("\tY : ");
    Serial.print(pitch);
    Serial.print("\tZ : ");
    Serial.println(mpu.getAngleZ());
    timer = millis();
    stabilizeSpoon();
  }
}

void stabilizeSpoon() {
  int servoXPosition = servoXCenter - roll; // Calculate servo position for X-axis
  int servoYPosition = servoYCenter + pitch; // Calculate servo position for Y-axis
  Serial.print(servoXPosition);
  Serial.print(" , ");
  Serial.println(servoYPosition);
  servoX.write(constrain(servoXPosition, 0, 180)); // Write servo position for X-axis with bounds
  servoY.write(constrain(servoYPosition, 0, 90)); // Write servo position for Y-axis with bounds
}