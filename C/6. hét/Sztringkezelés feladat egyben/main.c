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
    //szöveg beolvasása
    char ch;
    printf("Írj be egy szöveget (nagy Q inputtal befejezés):\n");
    while ( (ch=getchar()) != Q && i<N-1) {
        szoveg[i] = ch;
        i++;
    }
    szoveg[i] = '\0'; // sztring vége

    //szöveg kíírása
    printf("\nA beolvasott szöveg:\n%s\n", szoveg);

    //a szöveg fordított kíírása
    printf("A szöveg megfordítva:\n");
    for(i=strlen(szoveg)-1; i>=0; i--) {
        printf("%c", szoveg[i]);
    }

    //a szöveg fordított kíírása pointerrel
    char *fp = forditott;
    i = strlen(szoveg)-1;
    while (i>=0) {
        *fp = szoveg[i];
        fp++;
        i--;
    }
    *fp= '\0';
    printf("\nA szöveg megfordítva pointerrel:\n%s\n", forditott);

    //nagybetûsítés új tömbbel
    char *np = nagy;
    i=0;
    while (i<strlen(szoveg)) {
        *np = toupper(szoveg[i]);
        np++;
        i++;
    }
    *np = '\0';
    printf("\nA szöveg nagybetûsen:\n%s\n", nagy);

    //nagybetûsítés pointerrel
    char *sp = szoveg;
    while(*sp) {
        *sp=toupper(*sp);
        sp++;
    }
    *sp = '\0';
    printf("A szöveg nagybetûvel pointerrel:\n%s\n", szoveg);

    //'E' betûk megszámolása
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
    printf("A szövegben az 'E' betûk száma: %d\n", db);
    printf("Ez a szöveg karaktereinek %.2f%%-a\n", ((float)db/i)*100);

    return 0;
}
