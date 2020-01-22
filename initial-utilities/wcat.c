#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	char buffer[50];
	char charPtr;
	for (int i = 1; i < argc; i++) {
	printf("--------------------FILE NAME: ");
	printf("%s", argv[i]);
	printf("--------------------\n");
	int lineNum = 0;
	FILE *fp = fopen(argv[i], "r");
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
	for (int j = 0; j < lineNum; j++) {
		fgets(buffer, 50, fp);
		printf("%s", buffer);
	}
	fclose(fp);
	printf("--------------------------END OF FILE--------------------\n");
	}
}
