#ifndef __COPYSTRING__
#define __COPYSTRING__
#include <stdio.h>
class copyString 
{
    private:
        char * buffer;
        size_t length_buffer;
        void init(const char *str);

    public:
        copyString(const char* str = nullptr);
        copyString(copyString &&other);
        copyString(const copyString &other);
        ~copyString();
        
        size_t length();
        const char* data();

        copyString& operator=(const copyString& other);
        copyString& operator=(copyString&& other);
        copyString operator+(const copyString& other);
};
#endif