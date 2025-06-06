#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char*argv[]) {
    FILE *fd;
    char buf[21];
    int nchars;
    int fd1 = open("test.txt",O_RDONLY);
    int fd2 = open("test.txt", O_WRONLY);
    int fd3 = open("test.txt", O_RDONLY);
    buf[20] = '\0';
    if (read(fd1, buf,20)==20){
        printf("fd1: %s\n", buf);
    }
    close(fd1);

    strcpy(buf, "testing 123...");
    int len = strlen(buf);
    if (write(fd2, buf, len) != len) {
        perror("2.6.text");
        exit(EXIT_FAILURE);
    }
    close(fd2);
    if (read(fd3, buf, 20) == 20) {
        printf("fd1: %s\n", buf);
    }
    close(fd3);

    return EXIT_SUCCESS;

}