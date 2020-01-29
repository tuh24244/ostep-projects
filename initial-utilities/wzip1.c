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

        FILE * writep = fopen("output.txt", "w");
        char output[fileLength];
        int outputNum[1];
        int counter = 0;
	int total = 0;
	int nc = 0;
        int m;
        int n;
	int temp = 0;
        for (m = 0, n = m + 1; m < fileLength-1;) {
                int letterCount = 1;
                if (mem[m] != mem[n]) {
                        //output[counter] = mem[m];
                        //counter++;
			//m++;
			//n++;
			putc(mem[m], writep);
			m++;
			n++;
			temp = m;
                }
		//m=m-2;
		//n=n-2;
		while (mem[m] == mem[n]) {
			letterCount++;
			m++;
			n++;
			temp = m;
		}
		if (letterCount > 1) {
			m = m-letterCount;
			n = n-letterCount;
			int test  = letterCount;
			fwrite(&test, sizeof(int), 1, writep);
			putc(mem[temp], writep);
			m = temp+letterCount-1;
			n = temp+letterCount;
		}
		//fwrite(output, sizeof(char), counter-1, wp);
		//m = m - 1;
		//n = n - 1;
		//total++;
          /*      while (mem[m] == mem[n]) {
                        letterCount++;
                        m++;
                        n++; 
                }
		int d = letterCount;
		for (nc = 0; nc < 1; nc++) {
			outputNum[nc] = d;
		}
		fwrite(outputNum, sizeof(int), 1, wp); 
*/
	/*
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
	*/


        }
        //fwrite(output, 4, counter, wp);
        fclose(writep);
}

