#include "window.h"
//#include <bcm2835.h>
#include <QDebug>


Window::Window() : number(0),number2(0),number3(0),pwm(0),pwm2(0),pwm3(0)// <-- 'c++ initialisation list' - google it!
{
	//setup qthread opt3001 thread
	qThread = new QThread();
	optThread = new OptThread();	
	optThread ->moveToThread(qThread);
	connect(optThread,SIGNAL(workRequested()),qThread,SLOT(start()));
	connect(qThread,SIGNAL(started()),optThread,SLOT(doWork()));
	connect(optThread,SIGNAL(finished()),qThread,SLOT(quit()),Qt::DirectConnection);
	
	// set up the knob
	knob = new QwtKnob;
	knob->setValue(number);
	knob2 = new QwtKnob;
	knob2->setValue(number2);
	knob3 = new QwtKnob;
	knob3->setValue(number3);
	connect( knob, SIGNAL(valueChanged(double)), SLOT(setNumber(double)));
	connect( knob2, SIGNAL(valueChanged(double)), SLOT(setNumber2(double)));
	connect( knob3, SIGNAL(valueChanged(double)), SLOT(setNumber3(double)));
	
	// use the Qt signals/slots framework to update the gain -
	// every time the knob is moved, the function will be called
	slider = new QwtSlider;
	slider->setScale(0,1);
	slider->setScaleStepSize(1);
	slider->setGroove(true);
	slider->setTotalSteps(1);
	slider->setOrientation(Qt::Horizontal);


	// set up the thermometer
	thermo = new QwtThermo;
	thermo->setScale(0,10);
	thermo->setFillBrush( QBrush(Qt::blue) );
	thermo->show();
	thermo->setOrientation(Qt::Horizontal);
	
	thermo2 = new QwtThermo;
	thermo2->setScale(0,10);
	thermo2->setFillBrush( QBrush(Qt::green) );
	thermo2->show();
	thermo2->setOrientation(Qt::Horizontal);
	
	thermo3 = new QwtThermo;
	thermo3->setScale(0,10);
	thermo3->setFillBrush( QBrush(Qt::red) );
	thermo3->show();
	thermo3->setOrientation(Qt::Horizontal);


	// set up the VLayout - thermo above knob 
	vLayout = new QVBoxLayout;
	vLayout->addWidget(slider);
	vLayout->addWidget(thermo);
	vLayout->addWidget(knob);
	vLayout->addWidget(thermo2);
	vLayout->addWidget(knob2);
	vLayout->addWidget(thermo3);
	vLayout->addWidget(knob3);
	setLayout(vLayout);
	
}
Window::~Window(){

}

void Window::timerEvent( QTimerEvent * )
{	
	//setup pin configure and pwm control
	thresholdPwm = new ThresholdPwm();
	
	//slider mode exchange
	if(slider-> value() ==1){
	optThread->requestWork();
	optData=optThread->data;
		if (optData <1 || optData >1500){
			qDebug("Out of The Range");
		} 
		else{
			thresholdPwm-> setThreshold(optData/15,number,number2,number3);
			this-> pwm =thresholdPwm-> pwm;
			this-> pwm2 =thresholdPwm->pwm2;
			this-> pwm3 = thresholdPwm->pwm3;
			thresholdPwm-> setPwm(pwm,pwm2,pwm3);
		}
	}
	else{
		this-> pwm = number;
		this-> pwm2 = number2;
		this-> pwm3 = number3;
		thresholdPwm-> setPwm(pwm,pwm2,pwm3);
	}
	
	thermo->setValue(pwm);
	thermo2->setValue(pwm2);
	thermo3->setValue(pwm3);

}

void Window::setNumber(double number){
	this->number = number;
}

void Window::setNumber2(double number){
	this->number2 = number;
}
void Window::setNumber3(double number){
	this->number3 = number;
}


