#include "ProduceConsume.h"
SingleProduceSingleConsume& SingleProduceSingleConsume::getInstance()
{
    static SingleProduceSingleConsume ins_;
    return ins_;
};
void SingleProduceSingleConsume::produce_item(int & pro_data)
{
    std::unique_lock<std::mutex> lck(this->mux);
    if((this->write_position+1)%MAX_BUFF_SIZE == this->read_position)
    {
        this->var_full.wait(lck);
    }
    this->data_buff[this->write_position] = pro_data;
    std::cout<<"this->write_position "<<this->write_position<<std::endl;
    sleep(1);
    this->write_position = (this->write_position+1)%MAX_BUFF_SIZE;
    this->var_empty.notify_all();
};
void SingleProduceSingleConsume::produce_task()
{   
    int data{1};
    while(true)
    {  
        SingleProduceSingleConsume::getInstance().produce_item(data);
    }
};
int SingleProduceSingleConsume::consume_item()
{
    int data{0};
    std::unique_lock<std::mutex> lck(this->mux);
    if(this->read_position == this->write_position)
    {
        this->var_empty.wait(lck);
    }
    data = this->data_buff[this->read_position];
    std::cout<<"this->read_position : "<<this->read_position<<std::endl;
    std::cout<<"data : "<<data<<std::endl;
    this->read_position = (this->read_position + 1)%MAX_BUFF_SIZE;
    this->var_full.notify_all();
    return data;
};
void SingleProduceSingleConsume::consume_task()
{
    int data{0};
    while(true)
    {
        data = this->consume_item();
    }
};