#include "CopyString.h"
#include <string.h>
#include <iostream>
void copyString::init(const char *str)
{
    if(str == nullptr)
    {
        this->buffer = nullptr;
        this->length_buffer = 0;
    }
    else
    {
        this->length_buffer = strlen(str);
        this->buffer = new char[this->length_buffer + 1];
        strcpy(this->buffer, str);
    }
};
copyString::copyString(const char* str)
{
    if(str == nullptr)
    {
        length_buffer = 0;
        buffer = nullptr;        
    }
    else
    {
        length_buffer = strlen(str);
        buffer = new char[length_buffer + 1];
        (void)strcpy(buffer,str);        
    }
    std::cout<<"normal constructor"<<std::endl;
};
copyString::copyString(copyString&& other)
{
    this->buffer = other.buffer;
    this->length_buffer = other.length_buffer;
    other.buffer = nullptr;
    other.length_buffer = 0;
    std::cout<<"move constructor"<<std::endl;
};
copyString::copyString(const copyString& other)
{
    init(other.buffer);
    std::cout<<"copy constructor"<<std::endl;
};
size_t copyString::length()
{
    return this->length_buffer;
};
const char* copyString::data()
{
    return this->buffer;
};
copyString& copyString::operator=(const copyString& other)
{
    if(this != &other)
    {
        delete[] this->buffer;
        init(other.buffer);
    }
    std::cout<<"拷贝赋值"<<std::endl;
    return *this;
};
copyString& copyString::operator=(copyString&& other)
{
    delete[] this->buffer;
    init(other.buffer);
    other.buffer = nullptr;
    std::cout<<"移动赋值"<<std::endl;
    return *this;
};
copyString copyString::operator+(const copyString& other)
{
    copyString ins;
    if(other.buffer == nullptr)
    {
        ins = *this;
    }
    else if(this->buffer == nullptr)
    {
        ins = other;
    }
    else
    {   
        ins.length_buffer = strlen(this->buffer) + strlen(other.buffer) + 1;
        ins.buffer = new char[ins.length_buffer]; 
        strcpy(ins.buffer, other.buffer);
        strcat(ins.buffer, this->buffer);
    }
    return ins;
};
copyString::~copyString()
{
    delete[] this->buffer;
}

