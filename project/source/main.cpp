#include <iostream>
#include <string.h>
#include <string>
#include "ProduceConsume.h"
void fun_test()
{
    std::cout<<"test"<<std::endl;
};
int main() {

    std::thread task_pro(
        &SingleProduceSingleConsume::produce_task,
        &SingleProduceSingleConsume::getInstance());
    std::thread task_con(
        &SingleProduceSingleConsume::consume_task,
        &SingleProduceSingleConsume::getInstance()
    );
    task_con.join();
    task_pro.join();
    return 0;
};
  