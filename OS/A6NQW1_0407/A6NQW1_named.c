#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int child;

    //Itt hozzuk létre a FIFO fájlt. A felhasználónak írási és olvasási joga lesz.
    mkfifo("a6nqw1", S_IRUSR | S_IWUSR);

    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        //A szülőfolyamat megnyitja a fájlt olvasásra, mert csak olvasni fog, majd kiolvassa az üzenetet.
        fd = open("a6nqw1", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);

        //Lezárja és törli a fájlt.
        close(fd);
        unlink("a6nqw1");
    } else if(child == 0){
        int fd;

        //A gyerekfolyamat megnyitja a fájlt írásra, mert csak írni fog, majd beleírja az üzenetet, végül lezárja.
        fd = open("a6nqw1", O_WRONLY);
        write(fd, "BSZ A6NQW1!\n", 13);
        close(fd);
    }

    return 0;
}