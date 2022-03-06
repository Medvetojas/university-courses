#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void Handler(int sig);

int main(void)
{
    if (signal(SIGALRM, Handler) == SIG_ERR)
    {
        printf("Signal handler creation failed. Exiting with error.\n");
        exit(EXIT_FAILURE);
    }

    pause();
    return 0;
}

void Handler(int sig)
{
    printf("A6NQW1\n");
	printf("From now on I'm not blocked!\n");
    exit(1);
}