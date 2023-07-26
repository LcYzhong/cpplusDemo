
#ifndef PROJECTTEST_PRINTSUM_H
#define PROJECTTEST_PRINTSUM_H
#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <unistd.h>
// 生产者消费者经典问题
#define MAX_BUFF_SIZE 10
class SingleProduceSingleConsume
{
    public:
        static SingleProduceSingleConsume& getInstance();
        ~SingleProduceSingleConsume(){};
        
    private:
        SingleProduceSingleConsume(){};
        SingleProduceSingleConsume(const SingleProduceSingleConsume & ins){};
        const SingleProduceSingleConsume & operator=(const SingleProduceSingleConsume & ins){};
        std::mutex mux;
        std::thread task_pro;
        std::thread task_con;
    
    private:
        std::condition_variable var_full;
        std::condition_variable var_empty;
        int data_buff[10];
        int total_item{10};
        int read_position{9};
        int write_position{0};

    public:
        void produce_item(int & pro_data);
        void produce_task();
        int consume_item();
        void consume_task();
};
#endif //PROJECTTEST_PRINTSUM_H
