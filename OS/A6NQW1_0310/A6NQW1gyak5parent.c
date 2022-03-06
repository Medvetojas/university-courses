#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int pid = fork(); //visszater a child pid-jevel
	
	if (pid < 0){
		perror("fork error");
	} else if (pid == 0){
		if (execl("./A6NQW1gyak5child", "./A6NQW1gyak5child", NULL) < 0){ //csak akkor ter vissza (-1), ha sikertelen (hasznalat: execl(filepath, argumentumok(elso mindig a filepath, az utolso pedig NULL)
			perror("execl error");
		}
	}
	
	if (waitpid(pid, NULL, 0) < 0{
		perror("wait error");
	}
	
	int terminated_status;
	
	if(WIFEXITED(terminated_status)){ //WIFEXITED: visszaadja, hogy terminalodott-e a processz?
		int exit_status = WEXITSTATUS(status); //WEXITSTATUS: visszaadja az exit statust(csak true WIFEXITED eseten hasznalando)
		printf("A child processz kilepesi erteke: %d\n", exit_status);
	}
	
	return 0;
}
		