#ifndef OPT3001_H
#define OPT3001_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <cmath>
//Defining Configuration and Results Register

#define CONF_REG 0x01
#define RES_REG 0x00

class Opt3001{
public:
	Opt3001(); 
	~Opt3001();
	void Write(int _addr); // Writes to sensor 
	double Read(); // Reads value 
	double readLux(int res);// convert LUX
private:
	int config;
	int addr;
	int fd;
	int L;
	int R;
	int exp;
	double LSB;
	int result;
	

	
};
#endif
