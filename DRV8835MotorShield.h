#ifndef DRV8835MotorShield_h
#define DRV8835MotorShield_h

#include <Arduino.h>

class DualMotorShield
{
  public:
    DualMotorShield();
  
    void setM1Speed(int speed);
    void setM2Speed(int speed);
    void setSpeeds(int m1Speed, int m2Speed);
    
    void flipM1(bool flip);
    void flipM2(bool flip);
  
  private:
    void init();
    unsigned char _M1DIR;
    unsigned char _M2DIR;
    unsigned char _M1PWM;
    unsigned char _M2PWM;
    bool flippedM1 = false;
    bool flippedM2 = false;
};


#endif