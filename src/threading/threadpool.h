#pragma once 

namespace threading {

    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();
            void push(std::function<void()> func);
            void worker_thread();
            void wait_finished();

        private:

            std::vector<std::thread> threads;
            std::queue<std::function<void()>> queue;
            std::atomic<bool> accept_functions;

            std::mutex mutex;
            std::condition_variable condition_work;
            std::condition_variable condition_finished;

            bool done = false;
        
        protected:
    };

}