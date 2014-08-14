#ifndef DRV8835MotorShield_h
#define DRV8835MotorShield_h

#include <Arduino.h>

class DualMotorShield
{
  public:
    DualMotorShield();
  
    static void setM1Speed(int speed);
    static void setM2Speed(int speed);
    static void setSpeeds(int m1Speed, int m2Speed);
    
    static void flipM1(bool flip);
    static void flipM2(bool flip);
  
  private:
    static void init();
    static unsigned char _M1DIR;
    static unsigned char _M2DIR;
    static unsigned char _M1PWM;
    static unsigned char _M2PWM;
    static bool flippedM1 = false;
    static bool flippedM2 = false;
    
    
    static inline void init()
    {
      static boolean initialized = false;

      if (!initialized)
      {
        initialized = true;
        init2();
      }
    }
};


#endif