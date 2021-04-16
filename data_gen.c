#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char **argv){
	srand(0);
	int testcase = 1000000;
	
	if(!strcmp(argv[1], "-s")){
		FILE *fp = fopen("data_str","w");

		for (int i = 0; i < testcase; i++) {
			int len = rand() % 100 + 1; //1~100個字元組成字串
        	for(int j = 0; j < len; j++){ 
				int type = rand() % 3;
				if(type == 0){
					fprintf(fp, "%c", rand() % 10 + '0');
				}
				else if(type == 1){
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
		FILE *fp = fopen("data_num","w");
		for (int i = 0; i < testcase; i++) {
        	fprintf(fp, "%d ",rand());
    	}
	}

    return 0;
}