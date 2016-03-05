#pragma once
namespace Toolkit{

	/// <summary>
    /// High-accuracy timer
    /// </summary>
	public ref class MTimer
	{
	private:
		long long ticksPerSecond;
        long long elapsedTime;
        long long baseTime;
		long long inline getCurrentCounter();
	public:
		MTimer(void);

		/// <summary>
        /// Reset the one time timer.
        /// </summary>
		void Reset(void);
		/// <summary>
		/// Get the time since last reset.
		/// </summary>
		double GetTime();
		/// <summary>
        /// Get the current time in seconds.
        /// </summary>
		double GetAbsoluteTime();
		/// <summary>
        /// Get the number of seconds since last call of this function.
        /// </summary>
		double GetElapsedTime();
	};
}
