#include <iostream>
#include <string.h>
#include <string>
#include "printSum.h"
int main() {
    
    int data[] = {1,2,3,4,5,6};
    printf("data : %p\n",data);
    printf("&data : %p\n",&data);
    printf("&data+1 : %p\n",&data+1);
    printf("data+1 : %p\n",data+1);
}
  