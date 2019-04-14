#include "ThresholdPwm.h"
int main(void){
	while(1){
	double opt;
	double number;
	double number2;
	double number3;
	ThresholdPwm *thresholdPwm = new ThresholdPwm();
	opt = thresholdPwm-> optData;
	number = thresholdPwm-> number;
	number2 =thresholdPwm-> number2;
	number3 = thresholdPwm-> number3;
	thresholdPwm-> setThreshold(opt/15,number,number2,number3);
	double pwm =thresholdPwm-> pwm;
	double pwm2 =thresholdPwm->pwm2;
	double pwm3 = thresholdPwm->pwm3;
	thresholdPwm-> setPwm(pwm,pwm2,pwm3);
}
}
