#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for (std::size_t i = 0; i < num_threads; ++i) {
            this->finished.push_back(std::async(std::launch::async, [=]{ this->thread_task(); }));
        }
    }   

    ThreadPool::~ThreadPool() {

    }   

    // void ThreadPool::worker() {
    //     while(!this->done){
    //         std::packaged_task<void()> task;
            
    //         std::unique_lock<std::mutex> lock(this->mutex);
    //         if (this->queue.empty()){
    //             conditional_variable.wait(lock, [=] {return !this->queue.empty();});
    //         }
            
    //         task = std::move(this->queue.front());
    //         lock.unlock();
    //         this->queue.pop_back();
            
    //         task();
    //     }
    // }
}