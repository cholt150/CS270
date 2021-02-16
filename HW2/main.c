#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1

int makearg(char *s, char ***args);

int main() {
    char **argvec;
    char str[] = "ls -l file";
    int argc;
    #if DEBUG
        printf("calling makearg func\n");
    #endif
    argc = makearg(str, &argvec);
    printf("argc is: %d\n",argc);
    printf("Printing argv...\n");
    int i = 0;
    while(argvec[i] != NULL) {
        printf("First NULL check\n");
        printf("%s\n",argvec[i]);
        i++;
    }
    printf("While Loop Done");
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
    if(s[i-1] != ' ') {
        argc++; //account for the last word when the string does not end with a space
    }

    if(argc == 0) {
        args = NULL;
        return 0;
    }


    char **temp_arr = calloc(argc+1, sizeof(char*));

    char *token;
    int j = 0;

    token = strtok(s," "); //Read the initial token.

    do {

        #if DEBUG
            printf("DEBUG: TOKEN = %s\n",token);
        #endif

        if(token != NULL) {
            #if DEBUG
                printf("DEBUG: Length of token is: %i\n",strlen(token));
            #endif
            temp_arr[j] = calloc(strlen(token),sizeof(char));
            i = 0;
            for(i=0;i<strlen(token);i++) {
                temp_arr[j][i] = token[i];
            }
            #if DEBUG
                printf("DEBUG: %s\n",temp_arr[j]);
            #endif
            j++;
        }
        token = strtok(NULL," ");
    } while(token != NULL);

    #if DEBUG
        i = 0;
        printf("DEBUG: PRINTING args FROM WITHIN makearg()\n");
        while(temp_arr[i] != NULL) {
            printf("%s\n",temp_arr[i]);
            i++;
        }
    #endif

    // Organize return values
    temp_arr[argc] = NULL; //append trailing NULL
    args = &temp_arr;
    return argc;
}