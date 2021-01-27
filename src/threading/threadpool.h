#pragma once 

namespace threading {
 
    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();


            void thread_task();

            template<class F, class R=std::result_of_t<F&()>>
            std::future<R> push(F&& f) {
        
                std::packaged_task<R()> p(std::forward<F>(f));

                auto r = p.get_future();
                {
                    std::unique_lock<std::mutex> l(this->mutex);
                    this->queue.emplace_back(std::move(p));
                }
                
                this->conditional_variable.notify_one(); 

                return r; 
            }

        private:            

            std::mutex mutex;
            std::condition_variable conditional_variable;
            
            std::deque<std::packaged_task<void()>> queue;

            std::vector<std::future<void>> threads;
        
        protected:

    };

}