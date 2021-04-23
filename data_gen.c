#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char **argv){
	srand(0);
	int testcase = 1000000;
	
	if(!strcmp(argv[1], "-s")){
		FILE *fp = fopen("dataset2.txt","w");

		for (int i = 0; i < testcase; i++) {
        	for(int j = 0; j < 100; j++){ 
				int type = rand() % 2;
				if(type == 0){
					fprintf(fp, "%c", rand() % 26 + 'a');
				}
				else {
					fprintf(fp, "%c", rand() % 26 + 'A');
				}
			}
			fprintf(fp, "\n");
    	}
	}
	else if(!strcmp(argv[1], "-n")){
		FILE *fp = fopen("dataset1.txt","w");
		for (int i = 0; i < testcase; i++) {
        	fprintf(fp, "%d\n", rand());
    	}
	}

    return 0;
}
