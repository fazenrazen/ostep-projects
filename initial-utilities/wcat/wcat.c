#include <stdlib.h>
#include <stdio.h>

int BUFLEN = 1000;

int main(int argc, char *argv[]) {
    
    int num_files = argc;
    FILE *fp = fopen(argv[1], "r");

    char buffer[BUFLEN];
    char cool[BUFLEN];

    fgets(buffer, BUFLEN, fp);
    fgets(buffer, BUFLEN, fp);

    printf("%s", buffer);
    printf("%s", buffer);





    // Enumerate between files - skip command arg hence file = 1
    // for(int file = 1; file < num_files; file++) {
    //     // Open a file
    //     FILE *fp = fopen(argv[file], "r");

    //     // Check if the file open correctly
    //     if(fp == NULL) {
    //         printf("cannot open file \n");
    //         //strerror(fp);
    //         exit(1);
    //     }

    //     char c = "";
    //     // If char is EOF end the program
    //     while((c == getchar()) != EOF) {
    //         // Read until a newline
    //         while(c != '\n') {
                
    //         }
            
    //         fgets(buffer, BUFLEN, fp);

    //         printf("%s", buffer);

    //         ++fp;
    //     }
    // }
    return(0);
}
