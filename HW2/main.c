#include <stdio.h>
#include <string.h>

#define DEBUG 1

int makearg(char *s, char ***args);

int main() {
    char **argv;
    char str[] = "ls -l file";
    int argc;
    #if DEBUG
        printf("calling makearg func\n");
    #endif
    argc = makearg(str, &argv);
    printf("argc is: %d",argc);
    return(0);
}

int makearg(char *s, char ***args) {
    int argc = 0, i=0;
    while(s[i] != '\0') {
        #if DEBUG
            printf("looping through string\n");
        #endif
        if(s[i] == ' ') argc++;
        i++;
    }
    argc++; //account for the last word

    
    return argc;
}