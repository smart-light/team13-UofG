#ifndef OPT_THREAD_H
#define OPT_THREAD_H
#include <QObject>
#include <QThread>
#include "opt3001.h"

#define opt_addr 0x45

class OptThread : public QObject
{
	Q_OBJECT

public:
	OptThread();
	~OptThread();
	void requestWork();
	Opt3001 *opt3001;
	double data;
	
signals:

	void finished();
	void workRequested();
	
public slots:

	void doWork();
};
#endif
