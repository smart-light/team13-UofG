#include "MicroThread.h"
#include <stdio.h>
#include <wiringPi.h>
#include "window.h"
void MicroThread::MicroThread(){
	
}

void MicroThread::~MicroThread{
}

void MicroThread::run(){
	Window *window = new Window();
	if (enable == 0){
	wiringPiSetup();
	window-> number =10;
	}
	else if (enable ==1){
	window-> number = 0;	

}
	else{
	}

}
