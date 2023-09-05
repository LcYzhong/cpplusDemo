#ifndef __COPY__
#define __COPY__
#include <mutex>
#include <condition_variable>
class prosum
{
    public:
        static prosum& getInstance();
        ~prosum(){};

    private:
        prosum(){};

        int buffer[10];
        int write;
        int read;

        std::mutex mux;
        std::condition_variable con_pro;
        std::condition_variable con_sum;

        void pro_item();
        void sum_item();

        void pro_thread();
        void sum_thread();
};
#endif


// buffer malloc sizeof()编译时与执行时数值确定问题
// 类内的static const赋值问题