#include <iostream>
#include <string.h>
#include <string>
#include "ProduceConsume.h"
#include "CopyString.h"

int main()
{   
    copyString ins_1("123");
    copyString ins_2("456");
    
    copyString ins_3(ins_1 + ins_2);

}
// 单生产者消费者
// int main() {

//     std::thread task_pro(
//         &SingleProduceSingleConsume::produce_task,
//         &SingleProduceSingleConsume::getInstance());
//     std::thread task_con(
//         &SingleProduceSingleConsume::consume_task,
//         &SingleProduceSingleConsume::getInstance()
//     );
//     task_con.join();
//     task_pro.join();
//     return 0;
// };
  