#include <stdio.h>
#include <stdlib.h>

/*
    Ékezettel nem mûködik a program, minden mással igen.
    Babik Szilárd - A6NQW1
*/

char* titkositas(char* szoveg);
char* dekodolas(char* szoveg);

int main()
{
    int x;
    char szoveg[100];
    printf("Adj meg egy szoveget: ");
    scanf("%[^\n]", szoveg);

    printf("\nValassz az alabbi lehetosegek kozul:\n");
    printf("1 = Titkositas\n");
    printf("2 = Dekodolas\n");
    printf("A Te valasztasod: ");

    int ok;
    char ch;
    do{
        ok = 1;
        if((scanf("%d", &x)) != 1){
            ok = 0;
            printf("Beolvasasi hiba! Probald ujra: ");
            while((ch=getchar()) != '\n');
        }
    }while(!ok);

    char *d;
    if(x == 1){
        d = titkositas(szoveg);
        printf("A titkositott szoveg: %s", d);
    }else if(x == 2){
        d = dekodolas(szoveg);
        printf("A dekodolt szoveg: %s", d);
    }else{
        printf("Nem letezo opciot adtal meg! A program leall!");
        return 1;
        }
    return 0;
}

char* titkositas(char* szoveg){ //hozzátesz 3-at az ASCII értékhez
    char* seged = szoveg;
    int i;
    for(i = 0; (i < 100 && szoveg[i] != '\0'); i++){
        szoveg[i] = szoveg[i] + 3;
        }
    return seged;
}

char* dekodolas(char* szoveg){ //elvesz 3-at az ASCII értékből
    int i;
    char* seged = szoveg;
    for(i = 0; (i < 100 && szoveg[i] != '\0'); i++){
        szoveg[i] = szoveg[i] - 3;
        }
    return seged;
}
