#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__)
  #define DRV8835MOTORSHIELD_TIMER1_AVAILABLE
#endif

#include <Arduino.h>

class DRV8835MotorShield
{
  public:
    DRV8835MotorShield();
    DRV8835MotorShield(uint8_t M1DIR,
                       uint8_t M1PWM,
                       uint8_t M2DIR,
                       uint8_t M2PWM);

    void setM1Speed(int speed);
    void setM2Speed(int speed);
    void setSpeeds(int m1Speed, int m2Speed);
    void flipM1(boolean flip);
    void flipM2(boolean flip);

  private:
    void initPinsAndMaybeTimer();

    uint8_t _M1DIR;
    uint8_t _M2DIR;
    uint8_t _M1PWM;
    static const uint8_t _M1PWM_TIMER1_PIN = 9;
    uint8_t _M2PWM;
    static const uint8_t _M2PWM_TIMER1_PIN = 10;

    bool _flipM1 = false;
    bool _flipM2 = false;

    bool initialized = false;

    inline void init()
    {
      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};
