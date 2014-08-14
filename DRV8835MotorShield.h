#ifndef DRV8835MotorShield_h
#define DRV8835MotorShield_h

#include <Arduino.h>

class DRV8835MotorShield
{
  public:
    DRV8835MotorShield();
  
    static void setM1Speed(int speed);
    static void setM2Speed(int speed);
    static void setSpeeds(int m1Speed, int m2Speed);
    
    static void flipM1(bool flip);
    static void flipM2(bool flip);
  
  private:
    static void initPinsAndMaybeTimer();
    
    
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