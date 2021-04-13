// C program to illustrate
// open system call
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int is_ps(char* filename) {
    char buf[11];
    int fd = open(filename, O_RDONLY);
    read(fd,buf,11);
    close(fd);
    if(strcmp(buf,"%!PS-Adobe\n") == 0)
        return 1;
    else 
        return 0;
}

int is_pdf(char* filename) {
    char buf[7];
    char v_num;
    int fd = open(filename, O_RDONLY);
    read(fd, buf, 7);
    read(fd, &v_num, 1);
    close(fd);
    if((strcmp(buf,"%PDF-1.") == 0) && ((v_num > 47) && (v_num < 58))) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_ascii(char* filename) {
    char buf;
    int fd = open(filename, O_RDONLY);
    while(read(fd,&buf,1)){
        if(buf > 127) {
            close(fd);
            return 0;
        }
    }
    close(fd);
    return 1; //if all characters are <= 127
}

int is_dos(char* filename) {
    char curr_char;
    char prev_char;
    int ascii_flag = is_ascii(filename);
    int fd = open(filename, O_RDONLY);
    while(read(fd,&curr_char,1)){
        if(ascii_flag && (curr_char == '\n') && (prev_char == '\r')) {
            close(fd);
            return 1;
        }
        prev_char = curr_char;
    }
    close(fd);
    return 0; //if newlines are normal
}

int is_elf(char* filename) {
    char buf[4];
    int fd = open(filename, O_RDONLY);
    read(fd,buf,4);
    close(fd);
    if((buf[0] == 127) && (buf[1] == 'E') && (buf[2] == 'L') && (buf[3] == 'F'))
        return 1;
    else 
        return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("More or less than the required number of arguments!\n");
        return -1;
    }
    if(is_ps(argv[1])) {
        printf("I think the file is a postscript file!\n");
        return 0;
    }
    else if(is_pdf(argv[1])) {
        printf("I think the file is a PDF file!\n");
        return 0;
    }
    else if(is_elf(argv[1])) {
        printf("I think the file is an ELF file!\n");
        return 0;
    }
    else if(is_dos(argv[1])) {
        printf("I think the file is a DOS ASCII file!\n");
        return 0;
    }
    else if(is_ascii(argv[1])) {
        printf("I think the file is an ASCII file!\n");
        return 0;
    }
    else {
        printf("Unknown Binary file!\n");
        return 0;
    }
}