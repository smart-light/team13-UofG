#include "opt.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <unistd.h>
//UNIT TEST FOR OPT3001 AMBIENT LIGHT SENSOR
static const int OPT_ADDRESS = 0x45;

int main(void){
	float val;
	int maxlux = 90000;
	Opt3001 *OptTest;
	OptTest = new Opt3001();
	while(1){
	//Testing Write to Sensor
	OptTest->Write(OPT_ADDRESS);

    //Testing Write to Sensor
	val = OptTest->Read();
	if (val < 0 ){
		throw std::out_of_range("Error: Sensor reading out of range");
	}

	usleep(110000);
	//Results
	std::cout << "Read Sensor value: " << val << " lux" << std::endl;
}
}
