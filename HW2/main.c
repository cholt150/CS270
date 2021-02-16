#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0

int makearg(char s[], char ***args);

int main() {
    char **argvec;
    char str[] = "ls -l file";
    int argc;
    #if DEBUG
        printf("calling makearg func\n");
    #endif
    argc = makearg(str, &argvec);
    if(argc == -1) printf("makearg error");
    printf("argc is: %d\n",argc);
    printf("Printing argv...\n");
    int i = 0;
    while(argvec[i] != NULL) {
        printf("argv[%i]: %s\n", i, argvec[i]);
        i++;
    }
    #if DEBUG
        printf("While Loop Done");
    #endif
    return(0);
}

int makearg(char s[], char ***args){
    int argc = 0, i=0;
    while(s[i] != '\0') {
        if(s[i++] == ' ') argc++;
    }
    if(s[i-1] != ' ') {
        argc++; //account for the last word when the string does not end with a space
    }

    int len;

    if(argc == 0){
        *args = NULL;
        return -1;
    }
    *args = malloc((argc + 1) * sizeof(char*));
    (*args)[argc] = NULL;
    #if DEBUG
        printf("first malloc complete\n");
    #endif
    i = 0;
    char* token;
    token = strtok(s," ");
    do {
        len = strlen(token);
        if(len == 0) return -1;
        #if DEBUG
            printf("TOKEN: %s LEN: %d\n",token,len);
        #endif
        (*args)[i] = malloc(len+1);
        #if DEBUG
            printf("ALLOCATED %i BYTES\n",len+1);
        #endif
        strncpy((*args)[i],token,len);
        (*args)[i++][len] = '\0';
        token = strtok(NULL, " ");
    } while(token != NULL);
    return argc;
}