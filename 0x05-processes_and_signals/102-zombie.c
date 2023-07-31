#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();

        if (child_pid > 0)
        {
            printf("Zombie process created, PID: %d\n", child_pid);
            sleep(1); // Add a small delay to give the parent time to print before going to the next iteration.
        }
        else
        {
            exit(0); // Child exits immediately without doing anything.
        }
    }

    infinite_while(); // The parent process enters an infinite loop, keeping the zombies "alive."

    return (0);
}

