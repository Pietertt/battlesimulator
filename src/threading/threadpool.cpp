#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for(int i = 0; i < num_threads; i++) {
            this->threads.push_back(std::thread(&ThreadPool::worker_thread, this));
        }

        this->work = new ThreadsafeQueue<std::function<void()>>();
    }

    ThreadPool::~ThreadPool() {
       delete this->work;

     

        // for(std::thread thread : this->threads) {
        //     thread.join();
        // }
    }

    void ThreadPool::worker_thread() {
        while(!this->done) {
            std::function<void()> task;
            if(this->work->try_pop(task)) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }
}