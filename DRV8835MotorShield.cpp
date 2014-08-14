#include "DRV8835MotorShield.h"

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined (__AVR_ATmega32U4__)
  #define USE_20KHZ_PWM
#endif

  static unsigned char _M1DIR = 7;
  static unsigned char _M1PWM = 8;
  static unsigned char _M2DIR = 9;
  static unsigned char _M2PWM = 10;
  static bool flippedM1 = false;
  static bool flippedM2 = false;

DRV8835MotorShield::DRV8835MotorShield()
{
  
}

void DRV8835MotorShield::initPinsAndMaybeTimer()
{
  pinMode(_M1DIR,OUTPUT);
  pinMode(_M1PWM,OUTPUT);
  pinMode(_M2DIR,OUTPUT);
  pinMode(_M2PWM,OUTPUT);
  
  #ifdef USE_20KHZ_PWM
  // Timer 1 configuration
  // prescaler: clockI/O / 1
  // outputs enabled
  // phase-correct PWM
  // top of 400
  //
  // PWM frequency calculation
  // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
  TCCR1A = 0b10100000;
  TCCR1B = 0b00010001;
  ICR1 = 400;
#endif
}

void DRV8835MotorShield::setM1Speed(int speed)
{
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }
  if (speed > 400)  // Max 
    speed = 400;
    
#ifdef USE_20KHZ_PWM
  OCR1B = speed;
#else
  analogWrite(_M1PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
#endif 

  if (reverse ^ flippedM1) // flip if speed was negative or flipLeft setting is active, but not both
    digitalWrite(_M1DIR, HIGH);
  else
    digitalWrite(_M1DIR, LOW);
}

void DRV8835MotorShield::setM2Speed(int speed)
{
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
    
#ifdef USE_20KHZ_PWM
  OCR1A = speed;
#else
  analogWrite(_M2PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
#endif

  if (reverse ^ flippedM2) // flip if speed was negative or flipRight setting is active, but not both
    digitalWrite(_M2DIR, HIGH);
  else
    digitalWrite(_M2DIR, LOW);
}

void DRV8835MotorShield::setSpeeds(int m1Speed, int m2Speed){
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

void DRV8835MotorShield::flipM1(bool flip)
{
  flippedM1 = flip;
}

void DRV8835MotorShield::flipM2(bool flip)
{
  flippedM2 = flip;
}