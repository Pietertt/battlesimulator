#pragma once

namespace threading {

        class ThreadPool;

        class Worker {

            public:
                Worker(ThreadPool* pool);

            private:
                ThreadPool* pool;

            protected:
        };
    
}