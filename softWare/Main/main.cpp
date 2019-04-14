#include <window.h>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// create the window
	Window window;
	window.showMinimized();

	// call the window.timerEvent function every 110 ms
	window.startTimer(110);

	// execute the application
	return app.exec();
}
