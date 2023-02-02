#include <stdio.h>
#include <unistd.h>

int main(void){
	
	int i;
	
	for (i = 0; i < 5; i++){
		printf("Babik Szilárd Kristóf - A6NQW1\n");
		sleep(1); //sleep: alszik a hivo szal annyi masodpercig, amennyi az argumentumban van (visszater 0-val, vagy ha megszakad, annyival, amennyi masodperc volt meg hatra)
	}
	
	return 0;
	
}