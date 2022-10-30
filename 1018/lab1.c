#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void showFlag(int);

extern void init() __attribute__ ((constructor));

char flag[50] = "FLAG{thIZ_!s_f4C3_f1@g}";
pid_t pid = 1;
int r;

int main()
{
    for(int i = 0; i < r; i++)
    {
        if(pid > 0)
            pid = fork();
    }
    int user_input = 0;
    if(pid > 0)
    {
        printf("How many times I fork: ");
        scanf("%d", &user_input);
        if(user_input == r)
            showFlag(user_input);
        else
            printf("Try again :(\n");
    }

    return 0;
}

void init()
{
    if(pid > 0)
    {
        int table[] = {33, 55, 10, 110, 49, 126, 39, 45, 38, 119, 6, 108, 25, 86, 67, 43, 70};
        srand(time(NULL));
        const int MIN = 100;
        const int MAX = 1000;
        r = rand() % (MAX - MIN + 1) + MIN;

        for(int i = 5; i < 22; i++)
            flag[i] ^= (r % 255) ^ table[i - 5];
    }
}

void showFlag(int ans)
{
    for(int i = 5; i < 22; i++)
        flag[i] ^= (ans % 255);
    printf("%s", flag);
}
