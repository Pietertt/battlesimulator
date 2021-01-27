#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for (std::size_t i = 0; i < num_threads; ++i) {
            this->threads.push_back(
                std::async(
                std::launch::async,
                [this]{ thread_task(); }
                )
            );
        }
    }   

    ThreadPool::~ThreadPool() {

    }   

    void ThreadPool::thread_task() {
        while(true){
            std::packaged_task<void()> task;
            {
                std::unique_lock<std::mutex> lock(this->mutex);
                if (this->queue.empty()){
                    conditional_variable.wait(lock, [&] {return !this->queue.empty();});
                }
                
                task = std::move(this->queue.front());
                this->queue.pop_front();
            }
            
            if (!task.valid()) return;
            task();
        }
    }
}