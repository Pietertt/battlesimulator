#include "../precomp.h"

namespace threading {

    ThreadPool::ThreadPool(int num_threads) {
        for(int i = 0; i < num_threads; i++) {
            Worker* worker = new Worker(this);
            this->workers.push_back(worker);
        }

        this->work = new ThreadsafeQueue<std::function<void()>>();
    }

    ThreadPool::~ThreadPool() {
    //    delete this->work_queue;

    //     for(Worker* worker : this->workers) {
    //         delete worker;
    //     }
    }
}