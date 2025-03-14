#include "stdafx.h"
#include "Exercises/Deadlock.h"
#include "Utils/DurationTracker.h"
#include "Log.h"

#define DurationTracker(Name) \
	utils::DurationTracker LABEL(tracker)( \
	[](){INFO_LOG("Measure", "{} Begin Tracking elapsed time.", Name);}, \
	[](utils::DurationTracker::Duration_t i_duration){INFO_LOG("Measure", "{} elapsed time: {}s", Name, std::chrono::duration<double>(i_duration).count());} \
	);

int main(int argc, char** argv)
{
	DurationTracker("main");
	exercises::Deadlock deadlock;
	utils::Log::Wait();
	return 0;
}