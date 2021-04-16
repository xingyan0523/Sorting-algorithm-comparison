#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* a, int* b) { 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


void heapmaintain(int *arr, int n, int i) {
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	
	if (left < n && arr[left] > arr[largest])
		largest = left;

	
	if (right < n && arr[right] > arr[largest])
		largest = right;


	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapmaintain(arr, n, largest);
	}
}


void heapSort(int *arr, int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapmaintain(arr, n, i);


	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapmaintain(arr, i, 0);
	}
}

void printArray(int *arr, int size) { 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 


int main()
{
	int testCase = 1000000;
	int *arr = malloc(sizeof(int) * testCase);
	FILE *fp = fopen("./result", "a");

	for(int i = 0; i < testCase; i++)
		scanf("%d", &arr[i]);
		
	struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
	heapSort(arr, testCase);
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"\t%f\n", diff / 1000000.0);

	return 0; 	
}