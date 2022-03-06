#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: ./A6NQW1_gyak9_3a PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]); //atoi: stringet int tipussa alakit
    kill(pid, SIGALRM);
    return 0;
}