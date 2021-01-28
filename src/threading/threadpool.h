#pragma once 

namespace threading {
 
    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();
            void worker();

        template<typename F, typename R = std::result_of_t<F&()>>
        std::future<R> push(F&& function) {
            std::packaged_task<R()> packet(std::forward<F>(function));

            auto future = packet.get_future(); 
            {
                std::unique_lock<std::mutex> lock(mutex);
                this->queue.emplace_back(std::move(packet)); 
            }
            
            this->condition_work.notify_one(); 

            return future; 
        }

        private:            
            std::mutex mutex;
            std::condition_variable condition_work;
            std::deque<std::packaged_task<void()>> queue;
            std::vector<std::future<void>> finished;
        
        protected:

    };

}