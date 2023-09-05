#include <threadPool.h>
#include <vector>
threadPool::threadPool()
{
    start_pool = false;
};
void threadPool::start()
{
    start_pool = true;
    int i{0};
    for(i = 0; i < threadSize; i++)
    {
        pool_threads.push_back(&std::thread(std::bind(threadLoop,this)));
    }
};
void threadPool::threadLoop()
{
    while(start_pool)
    {
        Task task = take();
        if(task)
        {
            task();
        }
    }
};
threadPool::Task threadPool::take()
{
    std::unique_lock<std::mutex> unique_mux(mux);
    while(pool_tasks.empty()&&start_pool)
    {   
        con_var.wait(unique_mux);
    };
    
    Task task;
    if(!pool_tasks.empty()&&start_pool)
    {
        task = pool_tasks.top().second;
        pool_tasks.pop();
    }
    return task;    
};
threadPool::~threadPool()
{
    {
        std::unique_lock<std::mutex> unique_mux(mux);
        start_pool = false;
        con_var.notify_all();
    }
    for(Threads::iterator iter = pool_threads.begin(); iter != pool_threads.end(); iter++)
    {
        (*iter)->join();
        delete *iter;
    }
    pool_threads.clear();
};
void threadPool::addTask(const Task& task)
{
    std::unique_lock<std::mutex> unique_lock(mux);
    TaskPair tem_pair(level0,task);
    pool_tasks.push(tem_pair);
    con_var.notify_all();
};
void threadPool::addTask(const TaskPair& taskPair)
{
    std::unique_lock<std::mutex> unique_lock(mux);
    pool_tasks.push(taskPair);
    con_var.notify_all();
};