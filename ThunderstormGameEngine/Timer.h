/***************************************************************
** Author: Peter Hultgren
** Date: 2017-04-08
** Version 1.0.0
****************************************************************/

#pragma once

#include <chrono>

namespace ts {

	// Define what type of clock we will use so that it's easy to change at a later date.
	typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint;
	typedef std::chrono::duration<double> Duration;

	// Define a macro shortcut for getting the current time.
	#define NOW std::chrono::high_resolution_clock::now()

	class Timer {
		private:
			TimePoint mTime;

		public:
			/** Create a new timer with the current clock cycle. **/
			Timer() { mTime = NOW; };

			/** Create a new timer with the new time. **/
			explicit Timer(TimePoint time) { mTime = time; };

			/** Get the elapsed time.
			*	\param time -The end time to check against. 
			*	\return The elapsed time between the stored start time and the end time. **/
			inline Duration TimeElapsed(TimePoint time) { return time - mTime; };

			/** Get the elapsed time between the stored start time and the current time.
			*	\return The elapsed time between the stored start time and the current time. **/
			inline Duration TimeElapsed() { return NOW - mTime; };

			/** Reset the timer and set it to the current time. **/
			inline void Reset() { mTime = NOW; };

			/** Reset the timer and set it to the given time. 
			*	\param time -The given point in time. **/
			inline void Reset(TimePoint time) { mTime = NOW; };

	};
}