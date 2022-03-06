#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Windowson csak így van ékezetes betû

int main()
{
    setlocale(LC_ALL, "hun"); // Windowson csak így van ékezetes betû
	printf("4. hét - 7. házi feladat - Babik Szilárd\n");
	int db, primek, ok, szam, i, n;
    printf("Adj meg egy számot, és a program kiszámol annyi prímszámot: ");
    do{ // Ellenõrzött beolvasás kezdete
            ok = 1;
            if(scanf("%d", &db) !=1){ // Több adat megadása a szükségesnél, vagy rossz adat megadásának a kizárása
                ok = 0;
                while ((db = getchar()) !='\n');
                printf("Nem jó értéket adtál meg, de adok még neked esélyt, mit szólsz? Add meg újra: ");
                }
            else if (db == 0){ // 0 db prím kizárása
                ok = 0;
                while ((db = getchar()) !='\n');
                printf("Legalább 1 prímszámot hadd adjon meg a program. Add meg újra a számot: ");
                }
    }while (!ok); // Ellenõrzött beolvasás vége

    printf("Az elsõ %d db prímszám az alábbiak:\n", db);{
        for(n = 1;;n++){ //kiszámítás
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
