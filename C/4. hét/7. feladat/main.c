#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Windowson csak �gy van �kezetes bet�

int main()
{
    setlocale(LC_ALL, "hun"); // Windowson csak �gy van �kezetes bet�
	printf("4. h�t - 7. h�zi feladat - Babik Szil�rd\n");
	int db, primek, ok, szam, i, n;
    printf("Adj meg egy sz�mot, �s a program kisz�mol annyi pr�msz�mot: ");
    do{ // Ellen�rz�tt beolvas�s kezdete
            ok = 1;
            if(scanf("%d", &db) !=1){ // T�bb adat megad�sa a sz�ks�gesn�l, vagy rossz adat megad�s�nak a kiz�r�sa
                ok = 0;
                while ((db = getchar()) !='\n');
                printf("Nem j� �rt�ket adt�l meg, de adok m�g neked es�lyt, mit sz�lsz? Add meg �jra: ");
                }
            else if (db == 0){ // 0 db pr�m kiz�r�sa
                ok = 0;
                while ((db = getchar()) !='\n');
                printf("Legal�bb 1 pr�msz�mot hadd adjon meg a program. Add meg �jra a sz�mot: ");
                }
    }while (!ok); // Ellen�rz�tt beolvas�s v�ge

    printf("Az els� %d db pr�msz�m az al�bbiak:\n", db);{
        for(n = 1;;n++){ //kisz�m�t�s
            for(i=2;i<n;i++){
                if(n%i==0){
                    break;
                }
            }
            if(i==n){
                printf("%d ", i);
                primek++;
                if(primek == db){
                    break;
                }
            }
        }
    }
return 0;
}
