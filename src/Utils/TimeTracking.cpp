#include "stdafx.h"
#include "Utils/TimeTracking.h"
#include "TimerDelayer.h"

namespace utils
{
TimeTracking::TimeTracking(long i_expectedRunningMS)
	: m_timerDelayer((float) i_expectedRunningMS)
{
	m_timerConnection = m_timerDelayer->sig_onExpired.Connect(
		[i_expectedRunningMS]()
		{
			ASSERT_PLAIN_MSG(false, "Failed: Expected time executing below {}ms", i_expectedRunningMS);
		});
	m_timerDelayer->CreateTimerThread();
}

TimeTracking::~TimeTracking()
{
	m_timerConnection.Disconnect();
}
}