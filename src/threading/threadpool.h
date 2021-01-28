#pragma once 

namespace threading {
 
    class ThreadPool {
        public:
            ThreadPool(int num_threads);
            ~ThreadPool();


            void thread_task() {
                while(true){
                // pop a task off the queue:
                std::packaged_task<void()> f;
                {
                    // usual thread-safe queue code:
                    std::unique_lock<std::mutex> l(m);
                    if (work.empty()){
                    v.wait(l,[&]{return !work.empty();});
                    }
                    f = std::move(work.front());
                    work.pop_front();
                }
                // if the task is invalid, it means we are asked to abort:
                if (!f.valid()) return;
                // otherwise, run the task:
                f();
            }
            }

            template<class F, class R=std::result_of_t<F&()>>
        std::future<R> queue(F&& f) {
            // wrap the function object into a packaged task, splitting
            // execution from the return value:
            std::packaged_task<R()> p(std::forward<F>(f));

            auto r=p.get_future(); // get the return value before we hand off the task
            {
            std::unique_lock<std::mutex> l(m);
            work.emplace_back(std::move(p)); // store the task<R()> as a task<void()>
            }
            v.notify_one(); // wake a thread to work on the task

            return r; // return the future result of the task
        }

        private:            

             // the mutex, condition variable and deque form a single
  // thread-safe triggered queue of tasks:
  std::mutex m;
  std::condition_variable v;
  // note that a packaged_task<void> can store a packaged_task<R>:
  std::deque<std::packaged_task<void()>> work;

  std::vector<std::future<void>> finished;
        
        protected:

    };

}