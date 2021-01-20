#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for(int i = 0; i < num_threads; i++) {
            this->threads.push_back(std::thread(&ThreadPool::worker_thread, this));
        }        
    }

    ThreadPool::~ThreadPool() {
        this->done = false;

        for(std::thread& thread : this->threads) {
            thread.join();
        }
    }

    void ThreadPool::push(std::function<void()> func) {
        std::unique_lock<std::mutex> lock(this->mutex);
        this->queue.push(func);
        lock.unlock();
        this->cond.notify_one();
    }

    void ThreadPool::worker_thread() {
        std::function<void()> func;

        while(!this->done) {
            {
                std::unique_lock<std::mutex> lock(this->mutex);
                this->cond.wait(lock, [this](){
                    return !this->queue.empty();
                });
                if (this->queue.empty()) {
                    return;
                }

                func = this->queue.front();
                this->queue.pop();
            }
            func();
        }
    }
}