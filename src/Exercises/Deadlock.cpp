#include "stdafx.h"
#include "Exercises/Deadlock.h"
#include "Log.h"

namespace exercises
{
Deadlock::Deadlock()
	: m_shutdown(false)
	, m_taskLooper(*this, m_mutex, m_cv)
	, m_taskThread(&Deadlock::_Run, this)
{

}

Deadlock::~Deadlock()
{
	std::lock_guard lock(m_mutex);
	m_taskLooper.Push(TaskLooper_t::Task{ .runnable = &Deadlock::DoLastTask, .callback = [](int) {} });
	m_shutdown = true;
	m_cv.notify_one();
	m_taskThread.join();
}

void Deadlock::_Run()
{
	m_taskLooper.Run([this]() {return m_shutdown; });
}

int Deadlock::DoLastTask()
{
	INFO_LOG("Deadlock", "Finalizing last task");

	return 0;
}
}
