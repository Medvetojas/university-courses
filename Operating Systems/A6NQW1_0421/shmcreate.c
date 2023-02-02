#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 123456L



int main()
{
	int shmid;		/* osztott mem azonosito */
	key_t key;		/* kulcs a shmem-hez */
	int size=512;		/* osztott szegmens meret */
	int shmflg;		/* flag a jellemzokhoz */

	key = SHMKEY;
	/* Megnezzuk, van SHMKEY-es,size meretu szegmens. */
	shmflg = 0;
	if ((shmid=shmget( key, size, shmflg)) < 0) {
	   printf("\nNincs meg szegmens! Keszitsuk el!");
	   shmflg = 00666 | IPC_CREAT;
	   if ((shmid=shmget( key, size, shmflg)) < 0) {
	      perror("\nAz shmget system-call sikertelen!");
	      exit(-1);
	   }
	} else printf("\nVan mar szegmens!");

	printf("Az shmid azonositoja %d: \n", shmid);

	return 0;
}
