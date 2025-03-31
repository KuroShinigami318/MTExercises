#pragma once
#include "Utils/TaskLooper.h"
#include "Utils/TimeTracking.h"

namespace exercises
{
class Deadlock
{
public:
	using Callback_t = std::function<void(int)>;
	using TaskLooper_t = utils::TaskLooper<int(Deadlock::*)(), Callback_t>;

public:
	Deadlock();
	~Deadlock();

private:
	int DoLastTask();
	void _Run();

private:
	utils::TimeTracking m_timeTracking;
	bool m_shutdown;
	std::mutex m_mutex;
	std::condition_variable m_cv;
	TaskLooper_t m_taskLooper;
	std::thread m_taskThread;
};
}