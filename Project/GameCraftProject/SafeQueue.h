#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H

#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>

template<typename T>
class SafeQueue {
private:
	// Container
	std::queue<T> m_queue;

	// Sync
	std::mutex m_mtx;
	std::condition_variable m_cv;
public:
	SafeQueue() = default;
	SafeQueue(const SafeQueue&) = delete;            // disable copying
	SafeQueue& operator=(const SafeQueue&) = delete; // disable assignment

	inline T pop() {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_cv.wait(lock, [this]() {return !m_queue.empty();});
		auto item = m_queue.front();
		m_queue.pop();
		return item;
	}

	inline bool pop(T & item) {
		std::unique_lock<std::mutex> lock(m_mtx);
		if (m_queue.empty())
			return false;
		m_cv.wait(lock, [this]() {return !m_queue.empty();});
		item = std::move(m_queue.front());
		m_queue.pop();
		return true;
	}

	inline void push(const T& item) {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_queue.push(item);
		lock.unlock();
		m_cv.notify_one();
	}
	
	inline void push(T&& item) {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_queue.push(std::move(item));
		lock.unlock();
		m_cv.notify_one();
	}

	inline bool empty() {
		std::unique_lock<std::mutex> lock(m_mtx);
		return m_queue.empty();
	}

	inline int size() {
		std::unique_lock<std::mutex> lock(m_mtx);
		return m_queue.size();
	}
};

#endif // !SAFEQUEUE_H