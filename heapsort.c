#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "sort.h"

int main(int argc, char **argv) { 	
	int testCase = 1000000;
	struct timeval start;
    struct timeval end;
    unsigned long diff;
	FILE *fp = fopen("./result", "a");

	if(!strcmp("-s", argv[1])){
		char **arr = malloc(sizeof(char*) * testCase);
		char buf[128];
	
		
		int i = 0;
		while(fgets(buf, 128, stdin)){
			arr[i] = malloc(sizeof(char) * 128);
			strcpy(arr[i], buf);
			i++;
		}

		gettimeofday(&start, NULL);
		heapSort_str(arr, testCase - 1); 
		gettimeofday(&end, NULL);
		
	}
	else if(!strcmp("-n", argv[1])){
		int *arr = malloc(sizeof(int) * testCase);
	
	
		for(int i = 0; i < testCase; i++)
			scanf("%d", &arr[i]);

		gettimeofday(&start, NULL);
		heapSort(arr, testCase - 1); 
		gettimeofday(&end, NULL);
		
	}


    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"%f\n", diff / 1000000.0);
	
	return 0; 
}