#ifndef __THREADPOOL__
#define __THREADPOOL__
#include <functional>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
class threadPool
{
    public:         
        static const int threadSize{3};
        enum taskPriority { level0, level1, level2 };
        typedef std::function<void()> Task;
        typedef std::pair<taskPriority, Task> TaskPair;

        threadPool();
        ~threadPool();

        void start();
        void stop();
        void addTask(const Task& task);
        void addTask(const TaskPair& taskPair);

    private:
        threadPool(const threadPool&);
        const threadPool& operator=(const threadPool&);

        struct taskCmp
        {
            bool operator()(const TaskPair& var_1, const TaskPair& var_2)
            {
                return var_1.first > var_2.first;
            }
        };
        
        void threadLoop();
        Task take();

        typedef std::vector<std::thread*> Threads;
        typedef std::priority_queue<TaskPair, std::vector<TaskPair>, taskCmp> Tasks;

        Threads pool_threads;
        Tasks pool_tasks;

        std::mutex mux;
        std::condition_variable con_var;
        bool start_pool;

};
#endif
// 1）vector中的resize问题
// 2）pair用法
// 3) 上锁之后notify_all问题