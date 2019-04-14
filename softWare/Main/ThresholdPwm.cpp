#include "ThresholdPwm.h"
ThresholdPwm::ThresholdPwm()
{	
	//wiringPi setup
	wiringPiSetup();
	softPwmCreate(RED_LED,0,100);	
	softPwmCreate(GREEN_LED,0,100);	
	softPwmCreate(BLUE_LED,0,100);		
}

ThresholdPwm::~ThresholdPwm(){

}

void ThresholdPwm:: setThreshold(double opt,double number,double number2,double number3)
{	
	//threshold setup
	threshold = 5/ opt;
	if (number < threshold){
		this-> pwm =number;
	}
	else{
		this-> pwm = threshold;
	}
	
	if (number2 < threshold){
		this-> pwm2 =number2;
	}
	else{
		this-> pwm2 = threshold;
	}
	
	if (number3 < threshold){
		this-> pwm3 =number3;
	}
	else{
		this-> pwm3 = threshold;
	}
	
}

void ThresholdPwm:: setPwm(double PWM,double PWM2, double PWM3)
{
	
	softPwmWrite(RED_LED,PWM);	
	softPwmWrite(GREEN_LED,PWM2);	
	softPwmWrite(BLUE_LED,PWM3);		
	
}
