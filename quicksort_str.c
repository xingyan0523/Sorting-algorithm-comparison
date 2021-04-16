#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>




int partition (char **arr, int low, int high) { 
	char pivot[100];
	strcpy(pivot, arr[high]); 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) { 
		if (strcmp(arr[j], pivot) < 0) { 
			i++; 
			char tmp[100];
			strcpy(tmp, arr[i]);
			strcpy(arr[i], arr[j]);
			strcpy(arr[j], tmp); 
		} 
	} 
	char tmp[100];
	strcpy(tmp, arr[i + 1]);
	strcpy(arr[i + 1], arr[high]);
	strcpy(arr[high], tmp); 
	
	return (i + 1); 
} 

void quickSort(char **arr, int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 




int main() { 	
	int testCase = 1000000;
	char **arr = malloc(sizeof(char*) * testCase);
	char buf[128];
	
	FILE *fp = fopen("./result", "a");
	int i = 0;
	while(fgets(buf, 128, stdin)){
		arr[i] = malloc(sizeof(char) * 128);
		strcpy(arr[i], buf);
		i++;
	}
	
		
	struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
	quickSort(arr, 0, testCase - 1); 
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"%f", diff / 1000000.0);
	
	return 0; 
}