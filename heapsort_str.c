#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



void heapmaintain(char **arr, int n, int i) {
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
		heapmaintain(arr, n, largest);
	}
}


void heapSort(char **arr, int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapmaintain(arr, n, i);


	for (int i = n - 1; i > 0; i--) {
        char tmp[128];
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);
		heapmaintain(arr, i, 0);
	}
}

void printArray(char **arr, int size) { 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%s ", arr[i]); 
	printf("\n"); 
} 


int main()
{
	int testCase = 1000000;
	char **arr = malloc(sizeof(char*) * testCase);
    char buf[128];
	
    FILE *fp = fopen("./result", "a+");
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
	heapSort(arr, testCase);
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"\t%f\n", diff / 1000000.0);
	
	return 0; 	
}