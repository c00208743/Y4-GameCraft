#ifndef THREADPOOL_H
#define THREADPOOL_H

// Containers
#include <vector>
#include "SafeQueue.h"

#include <future>

class ThreadPool {
public:
	ThreadPool(const int numThreads) : m_workers(std::vector<std::thread>(numThreads)), m_stop(false) {};

	/// <summary>
	/// Thread worker class that operates on tasks in the threadpool when available
	/// </summary>
	class ThreadWorker {
	private:
		int m_id;
		ThreadPool * m_pool;
	public:
		ThreadWorker(ThreadPool * pool, const int id)
			: m_pool(pool), m_id(id) {
		}

		void operator()() {
			std::function<void()> func;
			bool removed = false;
			while (!m_pool->m_stop) {
				{
					std::unique_lock<std::mutex> lock(m_pool->m_mtx);
					if (m_pool->m_tasks.empty()) {
						m_pool->m_cv.wait(lock);
					}
					removed = m_pool->m_tasks.pop(func);
				}
				if (removed)
					func();
			}
		}
	};

	// Inits thread pool
	void init() {
		m_stop = false;
		for (int i = 0; i < m_workers.size(); ++i) {
			m_workers[i] = std::thread(ThreadWorker(this, i));
		}
	}

	// Submit a function to be executed asynchronously by the pool
	template<typename F, typename...Args>
	auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
		// Create a function with bounded parameters ready to execute
		std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
		// Encapsulate it into a shared ptr in order to be able to copy construct / assign 
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

		// Wrap packaged task into void function
		std::function<void()> wrapper_func = [task_ptr]() {
			(*task_ptr)();
		};

		// Enqueue generic wrapper function
		m_tasks.push(wrapper_func);

		// Wake up one thread if its waiting
		m_cv.notify_one();

		// Return future from promise
		return task_ptr->get_future();
	}

	// Non copyable
	ThreadPool(const ThreadPool &) = delete;
	ThreadPool(ThreadPool &&) = delete;
	ThreadPool & operator=(const ThreadPool &) = delete;
	ThreadPool & operator=(ThreadPool &&) = delete;

	// Waits until threads finish their current task and shutdowns the pool
	void shutdown() {
		m_stop = true;
		m_cv.notify_all();

		for (int i = 0; i < m_workers.size(); ++i) {
			if (m_workers[i].joinable()) {
				m_workers[i].join();
			}
		}
	}

private:
	std::vector<std::thread> m_workers;
	SafeQueue<std::function<void()>> m_tasks;
	
	// Sync
	std::mutex m_mtx;
	std::condition_variable m_cv;
	bool m_stop;
};
#endif // !THREADPOOL_H