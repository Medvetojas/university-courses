#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

	char bekert[100];
    printf("Enter a command you would like to execute: ");
    scanf("%s", bekert);

	system(bekert);

	return 0;
}