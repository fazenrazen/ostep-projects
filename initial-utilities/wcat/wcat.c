#include <stdlib.h>
#include <stdio.h>

// i made a comment with a bug

int BUFLEN = 1000;

int main(int argc, char *argv[]) {
    
    int num_files = argc;
    char buffer[BUFLEN];

    // iterate through all files 
    for(int file = 1; file < num_files; file++) {
        // iterate through all lines - end at EOF
        FILE *fp = fopen(argv[file], "r");

        feof(fp); // this is api contract UB that is hard to detect with San

        // check if NULL is error
        if(fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        // read the whole program
        while(fgets(buffer, sizeof(buffer), fp)) {
            printf("%s",  buffer);
        }
    }

    return(0);
}
