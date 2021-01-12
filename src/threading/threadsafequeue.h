#pragma once

namespace threading {

    template<typename T>
    class ThreadsafeQueue {
    
        public:
            ThreadsafeQueue() {

            }

            void push(T block) {
                std::lock_guard<std::mutex> lock(this->mutex);
                this->work_queue.push_back(std::move(block));
                this->condition_variable.notify_one();
            }

            void wait_and_pop(T& value) {
                std::unique_lock<std::mutex> lock(this->mutex);
                this->condition_variable.wait(lock, [this]{ return !this->work_queue.empty(); });
                value = std::move(this->work_queue.front());
                this->work_queue.pop_back();
            }

            bool try_pop(T& value) {
                std::lock_guard<std::mutex> lock(this->mutex);
                if (this->work_queue.empty()) return false;
                value = std::move(this->work_queue.front());
                this->work_queue.pop_back();
                return true;
            }

        private:
            std::mutex mutex;
            std::deque<T> work_queue;
            std::condition_variable condition_variable;

        protected:

    };
}