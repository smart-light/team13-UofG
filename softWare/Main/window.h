#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_slider.h>
#include <qwt/qwt_abstract_slider.h>
#include <QBoxLayout>
#include <QThread>
#include "OptThread.h"
#include "ThresholdPwm.h"
#include <cmath>

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments
	~Window();
	void timerEvent( QTimerEvent * );
public slots:
	void setNumber(double number);
	void setNumber2(double number);
	void setNumber3(double number);
// internal variables for the window class
private:
  // graphical elements from the Qwt library - http://qwt.sourceforge.net/annotated.html
	QwtKnob      *knob;
	QwtKnob      *knob2;
	QwtKnob      *knob3;
	QwtThermo    *thermo;
	QwtThermo    *thermo2;
	QwtThermo    *thermo3;
	QwtSlider	 *slider;
	double number;
	double number2;
	double number3;
	double pwm;
	double pwm2;
	double pwm3;
	double optData;
	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // horizontal layout
	
	ThresholdPwm *thresholdPwm;
	QThread *qThread;
	OptThread *optThread;

};

#endif // WINDOW_H
