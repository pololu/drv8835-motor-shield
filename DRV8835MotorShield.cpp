#include "DRV8835MotorShield.h"

DualMotorShield::DualMotorShield()
{
  _M1DIR = 7;
  _M1PWM = 8;
  _M2DIR = 9;
  _M2PWM = 10;
  init();
}

void DualMotorShield::init()
{
  pinMode(_M1DIR,OUTPUT);
  pinMode(_M1PWM,OUTPUT);
  pinMode(_M2DIR,OUTPUT);
  pinMode(_M2PWM,OUTPUT);
}

void DualMotorShield::setM1Speed(int speed)
{
  bool sign = (speed < 0);
  
  if (sign)
    speed = -speed;
  if (flippedM1)
    sign = !sign;
  
  analogWrite(_M1PWM, speed);
  digitalWrite(_M1DIR, (int)sign);
}

void DualMotorShield::setM2Speed(int speed)
{
  bool sign = (speed < 0);
  
  if (sign)
    speed = -speed;
  if (flippedM2)
    sign = !sign;
    
  if (speed > 255)
    speed = 255;

  analogWrite(_M2PWM, speed);
  digitalWrite(_M2DIR, (int)sign);
}

void DualMotorShield::setSpeeds(int m1Speed, int m2Speed){
  setM1Speed(M1);
  setM2Speed(M2);
}

void DualMotorShield::flipM1(bool flip)
{
  flippedM1 = flip;
}

void DualMotorShield::flipM2(bool flip)
{
  flippedM2 = flip;
}