#pragma once 

namespace threading {

    class Worker;
    //typedef Queue<int> intQueue ;

    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();

            void worker_thread();

            template<typename FunctionType>
            void submit(FunctionType f) {
                this->work->push(std::function<void()>(f));
            }

        private:
            std::vector<std::thread> threads;
            ThreadsafeQueue<std::function<void()>>* work;
            bool done = false;
        
        protected:
    };

}