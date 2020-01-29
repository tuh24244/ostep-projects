
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
        
        char buffer[50];
        char charPtr;
        int lineNum = 0;
        int fileLength = 0;
        int lineLength = 0;

        if (argv[2] == NULL) {
                printf("wgrep: searchterm[file...]\n");
                exit(1);
        }
 
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
        }
//        printf("Search term: %s\n", argv[1]);
        while (getc(fp) != EOF) {
                fileLength++;
                //if (getc(fp) == '\n') {
                //        lineNum++;
                //}
        }
        rewind(fp);
        for (int q = 0; q < fileLength; q++) {
                if (getc(fp) == '\n') {
                        lineNum++;
                }
        }

        char * mem = (char *)malloc(fileLength + 1);

        if (mem == NULL) {
                printf("Memory Error");
                exit(1);
        }

        rewind(fp);
        
        char character;
        char twoD[lineNum][fileLength];
//        printf("lineNum: %d\n", lineNum);
//        printf("fileLength: %d\n", fileLength);
        for (int i = 0, j = 0; i < lineNum;) {
                char character = getc(fp);
                if (character == '\n') {
                        twoD[i][j] = '\0';
                        i++;
                        j = 0;
                }
                else {
                        twoD[i][j] = character;
                        j++;
                }
        }

        int wordSize = strlen(argv[1]);
        int match = 0;
        int wordAppears = 0;
        for (int m = 0; m < lineNum; m++) {
                for (int n = 0, q = 0; n < fileLength; n++) {
                        if (twoD[m][n] == argv[1][q]) {
                                match++;
                                q++;
                        }
                        else {
                                match = 0;
                                q = 0;
                        }
                        if (match == wordSize) {
//                                printf("lineNum %d reads: ", m);
                                printf("%s\n", twoD[m]);
                                wordAppears++;
                                match = 0;
                                q = 0;
                                break;
                                                        }
                }
                match = 0;
        }

        if (wordAppears == 0){
                printf("No results\n");
        }

//        printf("Word appears: %d\n", wordAppears);
}
