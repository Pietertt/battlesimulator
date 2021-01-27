#pragma once 

namespace threading {
 
    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();


            void worker();

            template<class F, class R = std::result_of_t<F&()>>
            std::future<R> push(F&& f) {
                std::packaged_task<R()> p(std::forward<F>(f));

                auto result = p.get_future();
                
                std::unique_lock<std::mutex> lock(this->mutex);
                this->queue.push(std::move(p));
                lock.unlock();
                
                this->conditional_variable.notify_one(); 

                return result; 
            }

        private:            

            std::mutex mutex;
            std::condition_variable conditional_variable;
            
            std::queue<std::packaged_task<void()>> queue;

            std::vector<std::future<void>> threads;

            bool done = false;
        
        protected:

    };

}