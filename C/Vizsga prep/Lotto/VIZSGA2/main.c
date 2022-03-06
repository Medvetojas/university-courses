#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipp
{
    int szamok[5];
} Tipp;

Tipp beker();

int main()
{
    FILE *fp = fopen("kimenet.txt","w+");
    Tipp bekertszamok[6];
    int joszamok[] = {5, 27, 32, 67, 90};

    int i;
    for (i = 0; i<6; i++)
    {
        printf("Mezo %d:\n",i+1);
        bekertszamok[i] = beker();
    }

    for (i = 0; i<6; i++)
    {
        int j, db=0;
        for (j = 0; j<5; j++)
        {
            if (bekertszamok[i].szamok[j]==joszamok[j]) db++;
            fprintf(fp,"%d ",bekertszamok[i].szamok[j]);
        }
        fprintf(fp,"\n");
        printf("Talalatok %d. = %d\n",i,db);
    }
    fclose(fp);
    return 0;
}

Tipp beker()
{
    Tipp acttipp;

    int i;
    for (i = 0; i<5; i++)
    {
        bool ok = false;
        while (!ok)
        {
            ok=true;
            if (!scanf("%d",&(acttipp.szamok[i])))
            {
                printf("Hibas adat!\n");
                while (getchar()!='\n');
                ok=false;
            }
            else
            {
                if ((acttipp.szamok[i]<1) || (acttipp.szamok[i]>95))
                {
                    printf("Rossz intervallum!\n");
                    while (getchar()!='\n');
                    ok=false;
                }
                else
                {
                    if (i!=0)
                    {
                        if (acttipp.szamok[i]<=acttipp.szamok[i-1])
                        {
                            printf("A szam nem nagyobb az elozonel!\n");
                            while (getchar()!='\n');
                            ok=false;
                        }
                    }
                }
            }
        }
    }

    return acttipp;
}
