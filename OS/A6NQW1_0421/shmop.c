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
	struct vmi {
		int  hossz;
		char szoveg[512-sizeof(int)];
	} *segm;		/* Ezt a strukturat kepezzuk a szegmensre */

	key = SHMKEY;
	shmflg = 0;	/* Nincs IPC_CREAT, feltetelezzuk, az shmcreate
				keszitett osztott memoria szegmenst */
	if ((shmid=shmget( key, size, shmflg)) < 0) {
	    perror("\nAz shmget system-call sikertelen!");
	    exit(-1);
	}

/* Attach */
	shmflg = 00666 | SHM_RND;
	segm = (struct vmi *)shmat(shmid, NULL, shmflg); /* Itt a NULL azt
				jelenti, hogy az OS-re bizom, milyen
				cimtartomanyt hasznaljon. */
	if (segm == (void *)-1) {
		perror("Sikertelen attach");
		exit (-1);
	}
/* Sikeres attach utan a segm cimen ott az osztott memoria.
   Ha van benne valami, kiiratom, utana billentyuzetrol kerek
   uj beteendo szoveget */

	if (strlen(segm->szoveg) > 0)
		printf("\nRegi szoveg: %s (%d hosszon)",segm->szoveg,segm->hossz);

	printf("\nUj szoveget kerek!\n");
	gets(segm->szoveg);
	printf("\nAz uj szoveg: %s\n",segm->szoveg);
	segm->hossz=strlen(segm->szoveg);

/* Detach */
	shmdt(segm);

	exit(0);

}
