#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - a function that runs Forever and returns nothing
 * Return: 0 in the end
*/
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - the entry to a Program that creats 5 zombie process
 * Return: 0 on sucess
*/
int main(void)
{
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid > 0)
        {
            printf("Zombie process created, PID: %d\n", child_pid);
        }
        else
        {
            exit(0);
        }
    }

    infinite_while();

    return (0);
}

