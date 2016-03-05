#pragma once

namespace Toolkit{
	public ref class RateEstimator
	{
	private:
		System::Collections::Generic::Queue<double>^ times;
		System::Collections::Generic::Queue<double>^ values;
		

	public:
		RateEstimator(void);
		void AddNewSum(double newSum);
		double GetSlop(void);
	};
}

