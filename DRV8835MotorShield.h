#ifndef DualMotorShield_h
#define DualMotorShield_h

#include <Arduino.h>

class DualMotorShield
{
	public:
		DualMotorShield();
		DualMotorShield(unsigned char M1DIR, unsigned char M1PWM, unsigned char M2DIR, unsigned char M2PWM);
	
		void setM1Speed(int speed);
		void setM2Speed(int speed);
		void setSpeeds(int M1, int M2);
		
		void flipM1(bool flip);
		void flipM2(bool flip);
	
	private:
		void init();
		unsigned char _M1DIR;
		unsigned char _M2DIR;
		unsigned char _M1PWM;
		unsigned char _M2PWM;
		bool flippedM1;
		bool flippedM2;
};


#endif