#include "stdafx.h"
#include <windows.h>
#include <winuser.h>
#include "MTimer.h"

using namespace System;

namespace Toolkit{
	static MTimer::MTimer(void)
	{
		LARGE_INTEGER temp;
		// Use QueryPerformanceFrequency to get frequency of the timer
        if (!QueryPerformanceFrequency(&temp))
            throw gcnew ApplicationException("Timer: Performance Frequency Unavailable");

		ticksPerSecond = temp.QuadPart;
	}
	MTimer::MTimer(void)
	{
		baseTime = elapsedTime = getCurrentCounter();
	}

	long long inline MTimer::getCurrentCounter()
	{
        LARGE_INTEGER time;
        QueryPerformanceCounter(&time);

		return time.QuadPart;
	}
	/// <summary>
    /// Reset the one time timer.
    /// </summary>
	void MTimer::Reset(void)
	{
		baseTime = getCurrentCounter();
	}
	/// <summary>
    /// Get the time since last reset.
    /// </summary>
    double MTimer::GetTime()
    {
		return (double)(getCurrentCounter() - baseTime) / (double)ticksPerSecond;
    }

	/// <summary>
    /// Get the current time in seconds.
    /// </summary>
    double MTimer::GetAbsoluteTime()
    {
		return (double)getCurrentCounter() / (double)ticksPerSecond;
    }
	/// <summary>
    /// Get the number of seconds since last call of this function.
    /// </summary>
    double MTimer::GetElapsedTime()
    {
		long long now = getCurrentCounter();
		double result = (double)(now - elapsedTime) / (double)ticksPerSecond;
        elapsedTime = now;
        return result;
    }
}
