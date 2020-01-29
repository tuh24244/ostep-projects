#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	
	int fileLength = 30;
        int letterCount = 0;

        FILE * fp = fopen(argv[1], "r");
        if (fp == NULL) {
                printf("cannot open file\n");
                exit(1);
        }
        
        //while (getc(fp) != EOF) {
        //        fileLength++;
        //}

        //char * mem = (char *)malloc(fileLength + 1);
        //if (mem == NULL) {
        //        printf("Memory Error\n");
        //        exit(1);
       // }
       // rewind(fp);

	int i;
        for (i = 0; i < fileLength; i++) {
//		if (sizeof(mem[i]) == sizeof(char)) {
//                	mem[i] = getc(fp);
//		}
//		else if (sizeof(mem[i]) == sizeof(int)) {
//			printf("test");
		printf(fread(fp, 4, fileLength, stdout));
//		}
        }
//        mem[i] = '\0';
        fclose(fp);
/*
        FILE * writep = fopen("unzip.txt", "w");
        char output[fileLength];
        int outputNum[1];
        int counter = 0;
        int m;
        int n;
        int temp = 0;
        for (m = 0, n = m + 1; m < fileLength-1; m++) {
		printf("%c, %d\n", mem[m], sizeof(mem[m]));
		if (sizeof(mem[m]) == 1) {
			printf("test");
			fwrite(mem, sizeof(char), 1, writep);
		}
	}
	fclose(writep);
}

*/
}
