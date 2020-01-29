#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	if (argc == 1) {
		return 0;
	}

	for (int i = 1; i < argc; i++) {

		int fileLength = 0;
//		printf("ARGC %d, version %d\n", argc, i);
//		printf("--------------------FILE NAME: ");
//		printf("%s", argv[i]);
//		printf("--------------------\n");
	
		int lineNum = 0;
		FILE * fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("cannot open file\n");
			exit(1);
		}
	
		while (getc(fp) != EOF) {
			fileLength++;
		}

		char * mem = (char *)malloc(fileLength + 1);
		if (mem == NULL) {
			printf("Memory Error\n");
			exit(1);
		}

		rewind(fp);
		int j;
		for (j = 0; j < fileLength; j++) {
			mem[j] = getc(fp);
		}
		mem[j] = '\0';

		printf("%s", mem);
		free(mem);
		fclose(fp);
//		printf("--------------------------END OF FILE--------------------\n\n");
	}
}
