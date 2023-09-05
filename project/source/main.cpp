#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <functional>
#include "ProduceConsume.h"
#include <mutex>
#include "CopyString.h"
#include <vector>
#include <queue>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int  main()
{
    int freq_var{0},loss{0};



    int num=0;
    int pre_a,pre_b;
    int max_b;
    int max_a;
    int res_data;
    do
    {   

        scanf("%d:%d",&freq_var,&loss);
        if(num!=0)
        {
            if(pre_b<loss)
            {                                                                                                                                                                                                                                                                                                                                                                                                                           
                max_b = loss;
            }else{
                max_b = pre_b;
            }
            if(freq_var+pre_b<pre_a+loss)
            {
                max_a = freq_var+pre_b;
            }else{
                max_a = pre_a+loss;
            }
            res_data = max(max_a,max_b);
        }
        pre_a = freq_var;
        pre_b = loss;
        num++;

     

    }while(getchar()!='\n');
    if(num==1)
    {
        cout<<loss<<endl;
    }
    else
    {
cout<<res_data<<endl;
    }

}


// int main() {
//     int a, b;
//     int data[6];
//     int  i = 0;
//     int min_data =0;
//     int num_data[3];
//     int max_data = 0;
//     while (cin>>data[i]) { // 注意 while 处理多个 case

//         if(i==0)
//         {
//             min_data = data[0];
//         }
//         if(i==1)
//         {
//             max_data = data[1];
//         }
//         if(data[i]<min_data)
//         {
//             min_data = data[i];
//         }
//         if(data[i]>max_data)
//         {
//             max_data = data[i];
//         }
//     i++;
//         if(i==6)
//         {
//             break;
//         }
//     }
//     int res_data = 0;
//     num_data[0] = data[1]-data[0];
//     num_data[1] = data[3]-data[2];
//     num_data[2] = data[5]-data[4];
//     if(num_data[0]+num_data[1]+num_data[2] < max_data - min_data)
//     {
//         cout<<"-1"<<endl;
//         return 0;
//     }
//     res_data = max(max(data[0]+data[2],data[0]+data[4]),max(data[2]+data[4],data[1]+data[3]));
//     res_data = max(res_data,max(data[1]+data[5],data[3]+data[5]));
//     cout<<res_data<<endl;
// }
// #include <iostream>
// using namespace std;

// int main() {
//     int a, b;
//     int data[6];
//     int  i = 0;
//     int min = 0;
//     int max = 0;
//     int num_data[3];
//     while (cin>>data[i]) { // 注意 while 处理多个 case
//         i++;
//         if(i==6)
//         {
//             break;
//         if(i==0)
//         {
//             min = data[0];
//         }
//         if(i==1)
//         {
//             max = data[1];
//         }
//         if(data[i]<min)
//         {
//             min = data[i];
//         }
//         if(data[i]>max)
//         {
//             max = data[i];
//         }
//     }
//     num_data[0] = data[1]-data[0];
//     num_data[1] = data[3]-data[2];
//     num_data[2] = data[5]-data[4];
//     if(num_data[0]+num_data[1]+num_data[2] < max - min)
//     {
//         cout<<"-1"<<endl;
//         return 0;
//     }
//  0 1 2 3 4 5
//     data[1] data[3] data[5]
// }

// 64 位输出请用 printf("%lld")

// class class_test
// {
//     public:
//         const int  data;
//     class_test():data(1){};
// };
// void fun_test()
// {
//     std::cout<<"end"<<std::endl;
// };
// template<typename T, typename... TV>
// void fun_test(T arg_1, TV... args)
// {
//     std::cout<<"arg_1 : "<<arg_1<<std::endl;
//     fun_test(args...);
// };
// typedef std::function<void()> Task;
// void fun_thread()
// {
//     for(int i=0;i<10;i++)
//     {
//         std::cout<<"fun_thread"<<std::endl;
//     };
// };
// void fun_test_1()
// {
//     std::cout<<"fun_test)_1"
// }

// int main()
// {
//     class_test ins = class_test();
//     std::cout<<"ins.data : "<<ins.data<<std::endl;

// enum 测试
// enum class DATA: int
// {

//     level1 = 2,
//     level2,
//     level3,
// };
// int main()
// {
//     enum DATA ins_1 = DATA::level2;
//     std::cout<<(int)ins_1<<std::endl;
// };
// 测试优先级队列
// int main()
// {   
//     typedef struct node {int var_1;int var_2;}NODE;
//     struct strcmp
//     {
//         bool operator()(NODE par_1,NODE par_2)
//         {
//             return par_1.var_1 > par_2.var_1;
//         };
//     };
//     typedef std::priority_queue<NODE,std::vector<NODE>,strcmp> Task;
//     Task tasks;
//     NODE var_1{1,1};
//     NODE var_2{2,1};
//     NODE var_3{6,1};
//     NODE var_4{4,1};
//     tasks.push(var_1);
//     tasks.push(var_2);
//     tasks.push(var_3);
//     tasks.push(var_4);
//     do
//     {   
//         NODE iter = tasks.top();
//         std::cout<<"iter : "<<iter.var_1<<std::endl;
//         tasks.pop();
//     }while(!tasks.empty());

// };
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
  