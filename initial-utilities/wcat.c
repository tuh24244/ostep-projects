#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	char buffer[50];
	int lineNum = 0;
	char charPtr;
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("cannot open file\n");
		exit(1);
	}
	charPtr = getc(fp);
	while (charPtr != EOF) {
		charPtr = getc(fp);
		if (charPtr == '\n') {
			lineNum++;
		}
	}
	rewind(fp);
	//printf("Number of lines: %d\n", lineNum);
	for (int i = 0; i < lineNum; i++) {
		fgets(buffer, 50, fp);
		printf("%s", buffer);
	}
	fclose(fp);
}
