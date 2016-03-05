#include "stdafx.h"
#include "RateEstimator.h"
#include "MTimer.h"

// Max length of historic data queue (slow when too large)
#define QUEUE_MAX_LENGTH 2048

// Rate Calculate span (fast response when small, mild when large)
#define TIME_SPAN 1

namespace Toolkit{
	RateEstimator::RateEstimator(void)
	{
		times = gcnew System::Collections::Generic::Queue<double>();
		values = gcnew System::Collections::Generic::Queue<double>();
	}
	void RateEstimator::AddNewSum(double newSum)
	{
		double now = MTimer::GetAbsoluteTime();
		System::Threading::Monitor::Enter(values);
		while (times->Count >= QUEUE_MAX_LENGTH)
		{
			times->Dequeue();
			values->Dequeue();
		}
		times->Enqueue(now);
		values->Enqueue(newSum);
		System::Threading::Monitor::Exit(values);
	}
	double RateEstimator::GetSlop(void)
	{
		array<double>^ t;
		array<double>^ y;
		System::Threading::Monitor::Enter(values);
		while (times->Count > 0 && MTimer::GetAbsoluteTime() - times->Peek() > TIME_SPAN)
		{
			times->Dequeue();
			values->Dequeue();
		}
		t = times->ToArray();
		y = values->ToArray();
		System::Threading::Monitor::Exit(values);
		if (t->Length != y->Length)
			throw gcnew System::ApplicationException("Time value count mismatch @ RateEstimator");
		if (t->Length <= 1)
			return 0;

		double sum_t = 0;
		double sum_y = 0;
		for (int i = 0; i < t->Length; i++)
		{
			sum_t += t[i];
			sum_y += y[i];
		}

		double avr_t = sum_t / t->Length;
		double avr_y = sum_y / t->Length;

		double sum_dtdy = 0;
		double sum_dt2 = 0;
		for (int i = 0; i < t->Length; i++)
		{
			double dt = t[i] - avr_t;
			sum_dt2 += dt * dt;
			sum_dtdy += dt * (y[i] - avr_y);
		}

		return sum_dtdy / sum_dt2;
	}
}
