#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include "ScorePickup.h"

class Semaphore {
public:
	Semaphore(std::vector<ScorePickup> * pickups, ScorePickup * s) : m_pickups(pickups), m_scorePickup(s) {}
	inline void notify() {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_count++;
		m_cv.notify_one();
	}

	inline void wait() {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_cv.wait(lock, [this]() {return m_count > 0; });
		// Critical section

		// Non Critical section
		m_count--;
		// Manual Unlock to avoid waking and reblocking waiting thread
		lock.unlock();
	}
private:
	std::mutex m_mtx;
	std::condition_variable m_cv;
	int m_count = 0;
	std::vector<ScorePickup> * m_pickups;
	ScorePickup * m_scorePickup;
};

#endif //!SEMAPHORE_H