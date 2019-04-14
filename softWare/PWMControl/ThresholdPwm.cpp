#include "ThresholdPwm.h"
ThresholdPwm::ThresholdPwm()
{	
	optData=100;
	number=80;
	number2=70;
	number3=60;//change value to test, number between 0 to100, optData between 1-1500
	//wiringPi setup
	wiringPiSetup();
	softPwmCreate(RED_LED,0,100);	
	softPwmCreate(GREEN_LED,0,100);	
	softPwmCreate(BLUE_LED,0,100);		
}

ThresholdPwm::~ThresholdPwm(){

}

void ThresholdPwm:: setThreshold(double opt,double Number,double Number2,double Number3)
{	
	//threshold setup
	threshold = 5/ opt;
	if (Number < threshold){
		this-> pwm =Number;
	}
	else{
		this-> pwm = threshold;
	}
	
	if (number2 < threshold){
		this-> pwm2 =Number2;
	}
	else{
		this-> pwm2 = threshold;
	}
	
	if (number3 < threshold){
		this-> pwm3 =Number3;
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
