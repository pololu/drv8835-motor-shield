#ifndef DRV8835MotorShield_h
#define DRV8835MotorShield_h

#include <Arduino.h>

class DRV8835MotorShield
{
  public:
  
    static void setM1Speed(int speed);
    static void setM2Speed(int speed);
    static void setSpeeds(int m1Speed, int m2Speed);
    
    static void flipM1(bool flip);
    static void flipM2(bool flip);
  
  private:
    static void initPinsAndMaybeTimer();
    static const unsigned char _M1DIR;
    static const unsigned char _M2DIR;
    static const unsigned char _M1PWM;
    static const unsigned char _M2PWM;
    static bool flippedM1;
    static bool flippedM2;
    
    
    static inline void init()
    {
      static boolean initialized = false;

      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};


#endif