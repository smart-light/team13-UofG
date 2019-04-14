#include "opt3001.h"

//Constructor
Opt3001::Opt3001()
{
	config = 0x10C4;
}

//Deconstructor
Opt3001::~Opt3001()
{
}

//Writing to register
void Opt3001::Write(int _addr)
{
	//Initialising wiringPi setup with address of sensor
	addr = _addr;
	fd = wiringPiI2CSetup(_addr);
	wiringPiI2CWriteReg16(fd, CONF_REG, config);
}

//Read Sensor
double Opt3001::Read()
{
	int read = wiringPiI2CReadReg16(fd, RES_REG);
	return readLux(read);
}

double Opt3001::readLux(int res){
		L = res&0xFF; 
		L = L << 8;
		R= res&0xFF00;
		R = R >> 8;
		res = (L|R);

		exp = res&0b1111000000000000;
		exp= exp >> 12;
		LSB=pow(2, exp)*0.01;
		result = res&0b0000111111111111;
		return result*LSB;
	}
