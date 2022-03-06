#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleSignals(int signum);

int main() {
    void (*sigInterruptHandler)(int);
    void (*sigQuitHandler)(int);
    void (*sigReturnHandler)(int);
    sigInterruptHandler = sigQuitHandler = handleSignals;
    sigReturnHandler = signal(SIGINT, sigInterruptHandler);
    if (sigReturnHandler == SIG_ERR){
        perror("Signal error! Program exiting...");
        return 1;
    }
    sigReturnHandler = signal(SIGQUIT, sigQuitHandler);

    if (sigReturnHandler == SIG_ERR){
        perror("Signal error! Program exiting...");
        return 1;
    }
    while(1){
        printf("\nTo stop the program, follow the instructions:\n");
        printf("1. Open a new terminal.\n");
        printf("2. Issue the following command: kill %d or issue CTRL + C 2 times.", getpid());
        sleep(10);
    }
    return 0;
}

void handleSignals(int signum){
    switch(signum){
        case SIGINT:
            printf("\nPress CTRL + C");
            printf("Now restoring SIGINT signal to the default operation");
            signal(SIGINT, SIG_DEL);
            break;
        case SIGQUIT:
            printf("\nPress CTRL+\n");
            break;
        default:
            printf("\nReceived number of signals: %d\n", signum);
            break;
    }
    return;
}