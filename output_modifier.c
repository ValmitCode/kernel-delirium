#include <stdio.h>
#include <linux/module.h>
#include <unistd.h>
#include <string.h>

#define STDOUT 1
#define STDIN 0

void path_traversal(){
    char path[] = "afeafnajef:kaefaklenflka:aklenfaenfl:";
    char* token;
    char* path = getenv("PATH");
    if (path) token = strtok(path, ':');
    if (token) printf('%s', &token);
}

int main(int argv, char** args){
    char buffer[2048];
    //size_t streamFd = open("in_the_middle.txt", , )
    printf("Test");
    size_t update = read(STDOUT, buffer, 50);
    size_t spoil = write(STDOUT, buffer, 50);
    printf("Moo");
    path_traversal();
    return 0;
}