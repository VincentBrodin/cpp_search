#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <stdexcept>

namespace utils {
template <typename T>
class Queue {
   private:
	struct Node {
		T value;
		std::shared_ptr<Node> next;
		Node(const T& val) {
			value = val;
			next = nullptr;
		}
	};
	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;

   public:
	size_t len = 0;

	Queue() {
		head = nullptr;
		tail = nullptr;
	};
	~Queue() = default;

	void enqueue(T value) {
		auto new_node = std::make_shared<Node>(value);

		if (!tail) {
			head = new_node;
			tail = new_node;
		} else {
			auto old_node = tail;
			old_node->next = new_node;
			tail = new_node;
		}
		len++;
	}

	T dequeue() {
		if (!tail) {
			throw std::runtime_error("Queue is empty");
		}

		auto node = head;

		if (!node->next) {
			head = nullptr;
			tail = nullptr;
		} else {
			head = node->next;
		}

		len--;
		return node->value;
	}

	bool is_empty() { return head == nullptr; }
};
}  // namespace utils
#endif /* QUEUE_H */
