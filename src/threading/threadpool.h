#pragma once 

namespace threading {

    class Worker;
    //typedef Queue<int> intQueue ;

    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();

        private:
            std::vector<Worker*> workers;
            ThreadsafeQueue<std::function<void()>>* work;
        
        protected:
    };

}