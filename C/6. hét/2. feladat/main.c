#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#define N 15

int main()
{
    // Babik Szil�rd - gyakorlat 6.pdf - 2. k�telez� h�zi feladat

    setlocale(LC_ALL, "hun");
	char szoveg[N]; //15 karakter maximum
	int i;
    char ch;
    printf("Q lenyom�s�ig olvassa a karaktereket:\n");
    while ( (ch=getchar()) != 'Q' && i<N-1) {
        szoveg[i] = ch;
        i++;
    }
    szoveg[i] = '\0';

    for(i=0;i<=strlen(szoveg)-1;i++){
        if(szoveg[i] == 'A'){
            printf("Ava");
        } else if(szoveg[i] == 'a'){
            printf("ava");
        }else{
        printf("%c", szoveg[i]);
        }
    }

    return 0;
}
