#include <DRV8835MotorShield.h>


DRV8835MotorShield motors;

void setup()
{
}

void loop()
{
  for (int speed = 0; speed <= 255; speed++)
  {
    motors.setM1Speed(speed);
    delay(2);
  }

  for (int speed = 255; speed >= 0; speed--)
  {
    motors.setM1Speed(speed);
    delay(2);
  }


  for (int speed = 0; speed <= 255; speed++)
  {
    motors.setM2Speed(speed);
    delay(2);
  }

  for (int speed = 255; speed >= 0; speed--)
  {
    motors.setM2Speed(speed);
    delay(2);
  }


  for (int speed = 0; speed <= 255; speed++)
  {
    motors.setSpeeds(speed, speed);
    delay(2);
  }

  for (int speed = 255; speed >= 0; speed--)
  {
    motors.setSpeeds(speed, speed);
    delay(2);
  }
}

