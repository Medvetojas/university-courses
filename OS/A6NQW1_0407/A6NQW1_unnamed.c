#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2]; //2 elemű: szülő és gyerek
    int child;

    if(pipe(fd)){ //a pipe() fv. megnyitja és létrehozza a csővezetéket, illetve visszaadja az fd változóban a két fájlleírót.
        perror("pipe error");
        return 1;
    }

    child = fork();

    if(child > 0) {
        char s[1024];
        close(fd[1]);
        read(fd[0], s, sizeof(s));
        printf("%s", s);
        //A gyerekfolyamat lezárja az olvasóvéget, mert csak olvasni fog, majd kilvassa az üzenetet, és lezárja az olvasóvéget is.
        close(fd[0]); //szülő processz lezárása
    }else if(child == 0){ //ha a gyerek
        //A gyerekfolyamat lezárja az olvasóvéget, mert csak írni fog, majd beírja az üzenetet, és lezárja az íróvéget is.
        close(fd[0]);
        write(fd[1], "BSZ A6NQW1!\n", 13);
        close(fd[1]);
    }

    return 0;
}