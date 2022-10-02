#include<stdio.h>

extern void init() __attribute__ ((constructor));
extern void fini() __attribute__ ((destructor));

int main()
{
    for(int i = 0; i < 10; i++)
        printf("Hello world!\n");
        
    return 0;    
}

void init()
{
    puts("init");    
}

void fini()
{
    puts("fini");    
}
