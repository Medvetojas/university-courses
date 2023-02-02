#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void Handler(int sig);

int main(void)
{
    if (signal(SIGTERM, Handler) == SIG_ERR)
    {
        printf("Signal handler creation failed. Exiting with error.\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        sleep(3);
		printf("\nWaiting...\n");
    }

    return 0;
}

void Handler(int sig)
{
    signal(sig, SIG_IGN);
    printf("SIGTERM signal: %d\n", sig);
}