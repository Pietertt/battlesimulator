#pragma once 

#include "object.h"

namespace threading {

    class Worker;

    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();

            void worker_thread();

            template<typename FunctionType>
            void submit(FunctionType f) {
                object s;
                s.f = f;
                s.parameter = 1;
                //std::cout << s.parameter << std::endl;
                this->work->push(s);
            }

        private:

            std::vector<std::thread> threads;
            ThreadsafeQueue<object>* work;


            bool done = false;
        
        protected:
    };

}