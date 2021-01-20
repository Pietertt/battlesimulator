#pragma once 

#include "object.h"

namespace threading {

    class Worker;

    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();
            void push(std::function<void()> func);

            void worker_thread();

        private:

            std::vector<std::thread> threads;
            std::queue<std::function<void()>> queue;
            std::atomic<bool> accept_functions;

            std::mutex mutex;
            std::condition_variable cond;

            bool done = false;
        
        protected:
    };

}