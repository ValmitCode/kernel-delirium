#include <stdio.h>
#include <stdlib.h>
#include <linux/module.h>
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h> 

char* pattern_gen(char* binary, char* fd_middle){   
    char* result = (char*)malloc(strlen(binary) + strlen(fd_middle) + 100);
    strcpy(result, "alias ");
    strcat(result, binary);
    strcat(result,  " > ");
    strcat(result, fd_middle);
    return result;
}

int main(int argv, char** args){
    char* path = getenv("PATH");
    char* token;
    DIR* directory; 
    if (path) token = strtok(path, ":");
    while (token){
        printf("%s\n", token);
        token = strtok(NULL, ":");
        directory = opendir(token);
        
    }
    char* alias = pattern_gen(args[0], args[1]);
    printf("%s", alias);
    free(alias);
    return 0;
}