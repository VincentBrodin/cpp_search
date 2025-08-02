#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <memory>
#include <mutex>

#include "queue.h"

namespace utils {
template <typename T>
class SafeQueue {
   private:
	std::unique_ptr<Queue<T>> queue;
	std::mutex mutex;

   public:
	SafeQueue() { queue = std::make_unique<Queue<T>>(); };
	~SafeQueue() = default;

	void enqueue(T value) {
		mutex.lock();
		queue->enqueue(value);
		mutex.unlock();
	}

	T dequeue() {
		mutex.lock();
		auto val = queue->dequeue();
		mutex.unlock();
		return val;
	}

	size_t len() {
		mutex.lock();
		auto _len = queue->len;
		mutex.unlock();
		return _len;
	}

	bool is_empty() {
		mutex.lock();
		auto empty = queue->is_empty();
		mutex.unlock();
		return empty;
	}
};
}  // namespace utils
#endif /* SAFE_QUEUE_H */
