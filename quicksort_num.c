#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


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


void printArray(int *arr, int size) { 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 


int main() { 	
	int testCase = 1000000;
	int *arr = malloc(sizeof(int) * testCase);
	FILE *fp = fopen("./result", "a");
	
	for(int i = 0; i < testCase; i++)
		scanf("%d", &arr[i]);
		
	struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
	quickSort(arr, 0, testCase-1); 
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"%f", diff / 1000000.0);

	return 0; 
} 

