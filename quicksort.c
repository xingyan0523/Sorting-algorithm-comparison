#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



int partition_str (char **arr, int low, int high) { 
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

void quickSort_str (char **arr, int low, int high) { 
	if (low < high) { 
		int pi = partition_str(arr, low, high); 
		quickSort_str(arr, low, pi - 1); 
		quickSort_str(arr, pi + 1, high); 
	} 
} 

void swap(int* a, int* b) { 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int *arr, int low, int high) { 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) { 
		if (arr[j] < pivot) { 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int *arr, int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}

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
		quickSort_str(arr, 0, testCase - 1); 
		gettimeofday(&end, NULL);
	}
	else if(!strcmp("-n", argv[1])){
		int *arr = malloc(sizeof(int) * testCase);
	
	
		for(int i = 0; i < testCase; i++)
			scanf("%d", &arr[i]);

		gettimeofday(&start, NULL);
		quickSort(arr, 0, testCase - 1); 
		gettimeofday(&end, NULL);
	}


    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"%f\t", diff / 1000000.0);
	
	return 0; 
}