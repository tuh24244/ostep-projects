#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	if (argc == 1) {
		printf("wgrep: searchterm[file...]\n");
		exit(1);
	}

        char charPtr;
        int lineNum = 0;
        int fileLength = 0;
        int lineLength = 0;
	int wordAppears = 0;
	int match = 0;
	int wordSize = strlen(argv[1]);

	fflush(stdin);
 
	if (argc == 3) {
        	FILE *fp = fopen(argv[2], "r");
        	if (fp == NULL) {
                	printf("wgrep: cannot open file\n");
                	exit(1);
        	}
        	//printf("Search term: %s\n", argv[1]);
        	while (getc(fp) != EOF) {
                	fileLength++;
        	}
        	rewind(fp);
        	for (int i = 0; i < fileLength; i++) {
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
        
        	//char character;
        	char arr[lineNum][fileLength];
        	//printf("lineNum: %d\n", lineNum);
        	//printf("fileLength: %d\n", fileLength);
        	for (int j = 0, k = 0; j < lineNum;) {
                	char character = getc(fp);
                	if (character == '\n') {
                        	arr[j][k] = '\0';
                        	j++;
                        	k = 0;
                	}
                	else {
                        	arr[j][k] = character;
                        	k++;
                	}
        	}

        	//int wordSize = strlen(argv[1]);
        	int match = 0;
        	for (int m = 0; m < lineNum; m++) {
                	for (int n = 0, p = 0; n < fileLength; n++) {
                        	if (arr[m][n] == argv[1][p]) {
                                	match++;
                                	p++;
                        	}
                        	else {
                                	match = 0;
                                	p = 0;
                        	}
                        	if (match == wordSize) {
                                	//printf("lineNum %d reads: ", m);
                                	printf("%s\n", arr[m]);
                                	wordAppears++;
                                	match = 0;
                                	p = 0;
                                	break;
                                }
                	}
                	match = 0;
        	}		
        	if (wordAppears == 0){
                	printf("No results\n");
        	}
	}

	else if (argc == 2) {
        	char buffer[80];
        	gets(buffer);
                int u = 0;
                int f;
                for (f = 0; f < strlen(buffer); f++) {
                        if (buffer[f] != '\0') {
                                u++;
                        }
                }
                buffer[f] = '\0';
        	int y = 0;
        	for (int x = 0; y < u; y++) {
                	if (argv[1][x] == buffer[y]) {
                        	match++;
                        	x++;
                	}
                	else if (argv[1][x] != buffer[y]) {
                        	match = 0;
                        	x = 0;
                	}
                	if (match == wordSize) {
                        	printf("%s", buffer);
                        	break;
                	}
        	}

        }
}
