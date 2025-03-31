#pragma once

namespace utils
{
class TimeTracking
{
public:
	TimeTracking(long i_expectedRunningMS);
	~TimeTracking();

private:
	unique_ref<class TimerDelayer> m_timerDelayer;
	Connection m_timerConnection;
};
}