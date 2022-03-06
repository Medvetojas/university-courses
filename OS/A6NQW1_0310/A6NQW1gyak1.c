#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int status;

	if ( (status = system("date")) < 0){ //system: fork()-ot hasznalva, letrehoz egy gyermekprocesszt ami vegrehajtja system parametereben megadott parancsot, -1 a visszateresi ertek ha sikertelen a processz letrehozas
		perror("system() error");
	}

	if (WIFEXITED(status)){
		printf("Normalis befejeződés, visszaadott érték = %d\n", WEXITSTATUS(status));
	}

	return 0;
}