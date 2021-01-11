#include "precomp.h"

namespace Tmpl8 {
    ThreadPool::ThreadPool() {
        int numThreads = std::thread::hardware_concurrency();
       
        try {
             for (int i = 0; i < numThreads; i++) {
                this->workers.push_back(std::thread(&ThreadPool::worker_thread, this));
            }
        } catch(...) {
            this->done = true;
            throw;
        }
    }

    ThreadPool::~ThreadPool() {
        this->done = true; 
    }

    void ThreadPool::worker_thread() {
       
    }

    // void ThreadPool::worker_thread() {
    //     while(!this->done) {
    //         std::function<void()> task;
          
    //     }
    // }
}