#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void merge(int *arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int left[n1], right[n2];

	for (i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];

	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


void printArray(int *arr, int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(){
	int testCase = 1000000;
	int *arr = malloc(sizeof(int) * testCase);
	FILE *fp = fopen("./result", "a");

	for(int i = 0; i < testCase; i++)
		scanf("%d", &arr[i]);
		
	struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
	mergeSort(arr, 0, testCase-1); 
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"\t%f", diff / 1000000.0);

	return 0; 
}
