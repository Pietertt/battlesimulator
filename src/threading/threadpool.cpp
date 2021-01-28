#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for (std::size_t i = 0; i < num_threads; ++i) {
            this->futures.push_back(std::async(std::launch::async, [=]{ this->worker(); }));
        }
    }   

    ThreadPool::~ThreadPool() {
        this->done = true;

    }   

    void ThreadPool::worker() {
        while (!this->done) {
            std::packaged_task<void()> function;
            
            std::unique_lock<std::mutex> lock(mutex);
            if (this->queue.empty()) {
                this->condition_work.wait(lock, [&] {return !queue.empty(); });
            }
            
            function = std::move(queue.front());
            queue.pop_front();
            lock.unlock();
            
            if (!function.valid()) return;
            function();
        }
    }
}