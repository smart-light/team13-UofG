#include "OptThread.h"

OptThread::OptThread(){

		
}
OptThread::~OptThread(){
	
}
void OptThread::requestWork(){

	emit workRequested();
}

void OptThread::doWork(){
	opt3001 = new Opt3001();
	opt3001->Write(opt_addr);
	data = opt3001->Read(); 	
	emit finished();
	delete opt3001;
}

