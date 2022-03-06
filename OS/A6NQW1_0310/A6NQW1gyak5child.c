#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	
	int opcio;
	
	printf("Add meg valamelyik szamot: 1 - exit, 2 - abort, 3 - nullaval valo osztas");
	scanf("%d", &opcio);
	
	switch(opcio){
		case 1:
			exit(0);
		case 2:
			abort();
		case 3: 
			return 10/0;
		default:
			printf("Nem jo szamot valasztottal...");
			return 0;
	}
	
	return 0;
	
}