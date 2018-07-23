#ifndef STOPWATCH_H
#define STOPWATCH_H


/*
	stopwatch should have a start pause and reset for the purpose given
	no need for deep copy -no dynamic alloc
*/


class StopWatch{

public:
	//StopWatch();
	StopWatch(const double& timeScale=1.0):_timeScale(timeScale){}

	void startTiming();//start timer, sets time scale to 1
	void reset();//resets timer- does not change time scale
	double getTime();//shows time held by sw-changes the internal timestamp
	void printTime();
	void setTimeScale(const double& timeScale=1.0);
	void pauseTiming();/*sets time scale to 0--if getTime is called 
	befor and after pausing, the value returned will not have increased */


	~StopWatch();

private:	
	// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
	double getProcessTime();//should put in some overflow protection
	double _prevTime=0.0;// previous timestamp- used to calc time delta
	double _elapsedTime=0.0;// internal stopwatch val
	double _timeScale=1.0;//time scale- used for pausing

};
#endif
