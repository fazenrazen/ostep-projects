#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

const int BUFLEN = 1000; 

int main(int argc, char *argv[]) { 

    int numFiles = argc; 
    char *search_term = argv[1];
    char *line = NULL; 
    size_t len = 0; 
    ssize_t nread;

    // if no command line args
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    // Search through all files
    for(int file = 2; file < numFiles; file++) {
        FILE *fp = fopen(argv[file], "r");
        
        if(fp == NULL) {
            printf("%s\n", "wgrep: cannot open file");
            exit(1); 
        }

        // read through entire file
        while((nread = getline(&line, &len, fp)) != -1){
            // if we found search term in the line
            if(strstr(line, search_term) != NULL) {
                printf("%s", line); 
            }
        }
        
        fclose(fp);
    }
    
    free(line);

    return(0);
}