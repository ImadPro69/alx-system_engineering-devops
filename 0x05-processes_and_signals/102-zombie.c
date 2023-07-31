#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - a function that runs forever and returns nothing
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
 * main - the entry to a program that creates 5 zombie processes
 * Return: 0 on success
*/
int main(void)
{
    int children_processes = 0;
    pid_t pid;

    while (children_processes < 5)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0) // Child process
        {
            printf("Zombie process created, PID: %i\n", getpid());
            exit(0); // Child process exits immediately, becoming a zombie
        }
        else // Parent process
        {
            children_processes++;
        }
    }

    if (pid != 0)
        infinite_while();

    return (0);
}

