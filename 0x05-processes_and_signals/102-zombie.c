#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (fork() == 0)
        {
            printf("Zombie process created, PID: %d\n", getpid());
            exit(0);
        }
    }

    return infinite_while();
}
