#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main() {
    int fd, ret;
    char buf[128];

    buf[0]=0;

    //O_RDONLY - O_RDWR - O_WRONLY -- ezekből valamelyik kötelező
    //O_APPEND - minden write után a végére pozicionál
    //O_CREAT - létrehozás
    //O_TRUNC

    fd=open("A6NQW1.txt",O_RDWR);

    if (fd == -1){
        perror("open() hiba!");
        exit(-1);
    } else{
        printf("Sikeres a fajl megnyitas!\n");
    }

    ret=read(fd,buf,128); //ret: mennyit sikerült beolvasni
    printf("read() olvasott %d byteot, ami a kovetkezo: %s\n", ret, buf);
    strcpy(buf,"Babik Szilard Kristof, A6NQW1, Programtervezo informatikus");

    ret=lseek(fd,0,SEEK_SET); //SEEK_CUR, SEEK_END - ret: hova állt be ténylegesen
    printf("lseek() mondja: %d\n", ret);

    ret=write(fd,buf,6); //ret: mennyit írt ki valójában
    printf("file() mondja: %d\n", ret);

    close(fd);


    return 0;
}