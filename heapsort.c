#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



void heapmaintain_str(char **arr, int n, int i) {
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 
	
	if (left < n && strcmp(arr[largest], arr[left]) < 0)
		largest = left;

	
	if (right < n && strcmp(arr[largest], arr[right]) < 0)
		largest = right;


	if (largest != i) {
        char tmp[128];
        strcpy(tmp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], tmp);
		heapmaintain_str(arr, n, largest);
	}
}


void heapSort_str(char **arr, int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapmaintain_str(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
        char tmp[128];
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);
		heapmaintain_str(arr, i, 0);
	}
}

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
		printf("%d\n", arr[i]); 
	printf("\n"); 
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