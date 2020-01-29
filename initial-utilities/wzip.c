#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        
	int fileLength = 0;
        int letterCount = 0;

        FILE * fp = fopen(argv[1], "r");
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
	fclose(fp);

	FILE * wp = fopen("output.txt", "w");
	char output[fileLength];
	int outputNum[fileLength];
	int counter = 0;
	int m;
	int n;
	for (m = 0, n = 1; m < fileLength-1; m++, n++) {
		int letterCount = 1;
		if (mem[m] != mem[n]) {
			output[counter] = mem[m];
			counter++;
		}
		while (mem[m] == mem[n]) {
			letterCount++;
			m++;
			n++; 
		}
		if (letterCount > 1 && letterCount < 10) {
			output[counter] = letterCount + '0';
			counter++;
			output[counter] = mem[m];
			counter++;
		}
		else if(letterCount > 9) {
			int temp = letterCount;
			int digits = 1;
			char tempChar = letterCount;
			while (temp > 9) {
				temp /= temp;
				digits++;
			}
			int z;
			int r;
			temp = letterCount;
			for (z = counter; z < counter + digits; z++) {
				if (temp > 9) {
					r = temp % 10;
					temp /= 10;
					output[z] = (temp) + '0';
				}
				else {
					output[z] = r + '0';
					z++;
					output[z] = mem[m];
				}
			} 
			counter = z;
		}


	}
	fwrite(output, 1, counter, wp);
	fclose(wp);
}



