#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>

#include "fid.c"

int main(int argc, char *argv[]) {
    DIR *myDirectory;
    struct dirent *myFile;
    struct stat *myStats;
    time_t t;

    if(argc == 1) {
        myDirectory = opendir(".");
        if (myDirectory) {
            readdir(myDirectory);
            readdir(myDirectory);
            while ((myFile = readdir(myDirectory)))
                printf("%s\n", myFile->d_name);
        }
    }

    else {
        if (strcmp(argv[1],"-t") == 0) {
            myDirectory = opendir(".");
            if (myDirectory) {
                readdir(myDirectory);
                readdir(myDirectory);
                while ((myFile = readdir(myDirectory))){
                    lstat(myFile->d_name, myStats);
                    //t = myStats->st_atime;
                    int fd = open(myFile->d_name,O_RDONLY);
                    fstat(fd,myStats);
                    printf("%s\n",myFile->d_name);
                    char date[36];
                    printf("    Access: %li\n", (long int)myStats->st_atime);
                    printf("    Modify: %li\n", (long int)myStats->st_mtime);
                    printf("    Change: %li\n", (long int)myStats->st_ctime);
                }
            }
        }
        else if(strcmp(argv[1],"-f") == 0) {
            myDirectory = opendir(".");
            if (myDirectory) {
                readdir(myDirectory);
                readdir(myDirectory);
                while ((myFile = readdir(myDirectory))){
                    printf("%s  |  ", myFile->d_name);
                    fid((char*)myFile->d_name);
                }
            }
        }
        else {
            printf("argument error!\n");
        }
    }

    return (0);
}