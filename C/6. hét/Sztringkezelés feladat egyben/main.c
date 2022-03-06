#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define Q 81
#define N 100

int main()
{
    setlocale(LC_ALL, "hun");
	char szoveg[N], forditott[N], nagy[N];
    int i = 0;
    //sz�veg beolvas�sa
    char ch;
    printf("�rj be egy sz�veget (nagy Q inputtal befejez�s):\n");
    while ( (ch=getchar()) != Q && i<N-1) {
        szoveg[i] = ch;
        i++;
    }
    szoveg[i] = '\0'; // sztring v�ge

    //sz�veg k��r�sa
    printf("\nA beolvasott sz�veg:\n%s\n", szoveg);

    //a sz�veg ford�tott k��r�sa
    printf("A sz�veg megford�tva:\n");
    for(i=strlen(szoveg)-1; i>=0; i--) {
        printf("%c", szoveg[i]);
    }

    //a sz�veg ford�tott k��r�sa pointerrel
    char *fp = forditott;
    i = strlen(szoveg)-1;
    while (i>=0) {
        *fp = szoveg[i];
        fp++;
        i--;
    }
    *fp= '\0';
    printf("\nA sz�veg megford�tva pointerrel:\n%s\n", forditott);

    //nagybet�s�t�s �j t�mbbel
    char *np = nagy;
    i=0;
    while (i<strlen(szoveg)) {
        *np = toupper(szoveg[i]);
        np++;
        i++;
    }
    *np = '\0';
    printf("\nA sz�veg nagybet�sen:\n%s\n", nagy);

    //nagybet�s�t�s pointerrel
    char *sp = szoveg;
    while(*sp) {
        *sp=toupper(*sp);
        sp++;
    }
    *sp = '\0';
    printf("A sz�veg nagybet�vel pointerrel:\n%s\n", szoveg);

    //'E' bet�k megsz�mol�sa
    int db = 0;
    char *ep = szoveg;
    i = 0;
    while(*ep) {
        if (*ep=='E'){
            db++;
        }
        ep++;
        i++;
    }
    printf("A sz�vegben az 'E' bet�k sz�ma: %d\n", db);
    printf("Ez a sz�veg karaktereinek %.2f%%-a\n", ((float)db/i)*100);

    return 0;
}
