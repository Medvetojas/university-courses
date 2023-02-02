#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
    22. szamu feladat: Irjon C nyelvu programot, ami:
    1. letrehoz egy gyermek processzt
    2. az ujonnan letrejott processzben vegrehajtja a "/bin/ls -R/" parancsot a parametereivel egyutt, terjen vissza valamilyen 0-tol kulonbozo ertekkel
    3. a szulo varja meg amig befejezodik a processz, es irja ki a visszateresi erteket
*/

int main()
{
    printf("Parent: The program has started running...\n");

    int returnvalue;
    int pid = fork(); //Child processz létrehozása...


    if( pid == 0 ){
        printf("Child: Forking of Parent process finished successfully.\n\n");
    } else if ( pid < 0 ){
        perror("Parent: Error occurred during forking procedure, exiting with 256...");
        exit(EXIT_FAILURE);
    }

    if( pid == 0 ){ //Ha a child processzben vagyunk, akkor...

        /* 1. megoldás: execl(const char *path, const char *arg, ...);

        Az elso ket parameterben megadjuk az ls eleresi helyet, a harmadik parameterbe az argumentumot, a negyedik parameter pedig mindig NULL.

        execl(
               "/bin/ls",
               "/bin/ls",
               "-R",
               NULL
        );
        */

        /* 2. megoldás (egyben a jelenleg futó): int system(const char *command);

        A fuggveny parameterebe a command stringen keresztul betoltjuk a parancsot a parameterevel egyutt, es a fuggveny vegrehajtja azt.

        */

        char command[50]; //Parancs eltarolasahoz a string letrehozasa
        strcpy(command, "ls -R"); //Parancs irasa a stringbe

        int systemstatus;
        if( ( systemstatus = system(command ) ) < 0){ //system() fuggveny futtatja a command-ban eltarolt parancsot a parametereivel egyutt
            //perror("Child: Error occurred during running the command using system(). Exiting with 256...");
            exit(EXIT_FAILURE);
        }
        printf("\n\nChild: Successfully finished running, exiting with 0...\n");
        exit(EXIT_SUCCESS);

    } else { //Ha a parent processzben vagyunk, akkor...
        waitpid(pid, &returnvalue, 0); //Megvarja amig befejezodik a child processz, es visszaadja a returnvalue valtozoba a visszateresi erteket
        printf("\nParent: Child return value: %d\n", returnvalue);

        if( returnvalue != 0 ){ //Hibas Child futas eseten a Parent is hibaval ter vissza
            printf("Parent: Child process returned with an error, returning with 10...\n");
            return 10;
        } else if ( returnvalue == 0 ){ //Helyes Child futas eseten a Parent 0-val ter vissza
            printf("Parent: Child process successfully exited running, returning with 0...\n");
            return 0;
        }
    }

    return 0;
}
