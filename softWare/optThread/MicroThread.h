#ifndef MICRO_THREAD_H
#define MICRO_THREAD_H


#include "CppThread.h"
class MicroThread: public CppThread{
	
	public:
		MicroThread (int _offset)
		{
		offset = _offset;
		}
	public:
		void run();
		void function();
		
	private:
		int offset;
};
	
#endif
