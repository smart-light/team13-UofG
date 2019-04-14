#ifndef THRESHOLD_PWM_H
#define THRESHOLD_PWM_H
#include <cmath>
#include <wiringPi.h>
#include <softPwm.h>


#define RED_LED 0 //red wiringPi   0
#define	GREEN_LED 2//green wiringPi 2
#define	BLUE_LED 3//blue wiringPi 3

class ThresholdPwm{
	public:
	ThresholdPwm();
	~ThresholdPwm();
	void setThreshold(double opt,double number,double number2,double number3);
	void setPwm(double PWM,double PWM2,double PWM3);
	
	private:
	double threshold;
	
	public:
	double pwm;
	double pwm2;
	double pwm3;
	
};
#endif
