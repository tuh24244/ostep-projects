#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        
	char buffer[50];
	char searchTerm[50];
        char charPtr;
        int lineNum = 0;
	int wordAppears = 0;
	
	if (argv[2] == NULL) {
		printf("wgrep: searchterm[file...]\n");
		exit(1);
	}
 
	FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
        }
	printf("Search term: %s\n", argv[1]);
        charPtr = getc(fp);
        while (charPtr != EOF) {
                charPtr = getc(fp);
                if (charPtr == '\n') {
                        lineNum++;
                }
        }
        rewind(fp);

        for (int j = 0; j < lineNum; j++) {
                fgets(buffer, 50, fp);
		int size = sizeof(buffer)/sizeof(buffer[0]);
		int wordSize = strlen(argv[1]);
		int match = 0;
		for (int m = 0; m < size; m++) {
			if (buffer[m] == argv[1][0]){
				for (int n = 0, q = m; n < wordSize; n++, q++) {
					if (buffer[q] == argv[1][n]) {
						match++;
					}
					if (match == wordSize) {
						printf("%s", buffer);
						wordAppears++;
						break;
					}
				}
				match = 0;
			}
		}
        }
	fclose(fp);
	if (wordAppears == 0) {
		printf("NOT FOUND\n");
	}
	printf("\n");
}

