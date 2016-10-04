#ifndef __NY_TIMER__
#define __NY_TIMER__

#include <windows.h>

class NYTimer
{
public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

	NYTimer()
	{
		QueryPerformanceCounter(&lastUpdateTime);
		LARGE_INTEGER li_freq;
		QueryPerformanceFrequency(&li_freq);
		freq = li_freq.QuadPart;
		freq /= 1000;
	}

	void start(void)
	{
		QueryPerformanceCounter(&lastUpdateTime);
	}

	float getElapsedSeconds(bool restart = false)
	{
		LARGE_INTEGER timeNow;
		QueryPerformanceCounter(&timeNow);
		LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

		float elapsed = (float)((float)elapsedLong / (float)freq);
		elapsed /= 1000.0f;

		if (restart)
			lastUpdateTime = timeNow;

		return elapsed;
	}

	unsigned long getElapsedMs(bool restart = false)
	{
		LARGE_INTEGER timeNow;
		QueryPerformanceCounter(&timeNow);
		LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

		unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);

		if (restart)
			lastUpdateTime = timeNow;


		return elapsed;
	}
};

#endif