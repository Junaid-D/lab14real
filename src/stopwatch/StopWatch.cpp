#include "StopWatch.h"
#include <ctime>
#include <iostream>
using namespace std;

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 



void StopWatch::reset()
{
	_elapsedTime=0.0;
}

void StopWatch::setTimeScale(const double& timeScale)
{
	_timeScale=timeScale;
	return;

}

void StopWatch::printTime()
{
	cout<<"Current SW time is: "<<getTime()<<endl;
	cout<<"The SW is operating at a time scale of: "<<_timeScale<<endl;
	return;
}

double StopWatch::getTime()
{
	_elapsedTime+=(getProcessTime()-_prevTime)*_timeScale;
	_prevTime=getProcessTime();
	return _elapsedTime;
}

void StopWatch::pauseTiming()
{
	_elapsedTime+=(getProcessTime()-_prevTime)*_timeScale;
	_timeScale=0.0;
	
}

void StopWatch::startTiming()
{
	_timeScale=1.0;
	_prevTime=getProcessTime();

}



double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}

StopWatch::~StopWatch()
{

}
