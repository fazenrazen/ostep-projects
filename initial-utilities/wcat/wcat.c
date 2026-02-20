#include <stdlib.h>
#include <stdio.h>

int BUFLEN = 1000;

int main(int argc, char *argv[]) {
    
    int num_files = argc;
    char buffer[BUFLEN];

    // iterate through all files 
    for(int file = 1; file < num_files; file++) {
        // iterate through all lines - end at EOF
        FILE *fp = fopen(argv[file], "r");

        // check if NULL is error
        if(fp == NULL && ferror(fp)) {
            printf("cannot open file, errored out \n");
            exit(1);
        }
        else if(fp == NULL && feof(fp)) {
            printf("cannot open file, end of file \n");
            exit(1);
        }

        // read the whole program
        while(!feof(fp)) {
            // print process
            fgets(buffer, BUFLEN, fp);
            printf("%s", buffer);
        }
    }

    return(0);
}
