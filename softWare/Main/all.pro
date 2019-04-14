# Qt project file - qmake uses his to generate a Makefile

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Main

greaterThan(QT_MAJOR_VERSION, 4): LIBS+= -lqwt-qt5 -lm
lessThan(QT_MAJOR_VERSION, 5): LIBS += -lqwt -lm

#wiringPi include files can be found druing compile
INCLUDEPATH += /usr/local/include

#To link the bcm  and wiringPi library when making the executable
LIBS += -L/usr/local/lib -lwiringPi
LIBS += -L/usr/local/lib -lbcm2835
 
HEADERS += window.h OptThread.h opt3001.h ThresholdPwm.h

SOURCES += main.cpp window.cpp OptThread.cpp opt3001.cpp ThresholdPwm.cpp
	   
