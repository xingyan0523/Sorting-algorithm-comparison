#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>


void merge(char **arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

    char **left = malloc(sizeof(char*) * n1);
    char **right = malloc(sizeof(char*) * n2);

	
	for (i = 0; i < n1; i++){
        left[i] = malloc(sizeof(char) * 128);
        strcpy(left[i], arr[l + i]);
    }
        
	for (j = 0; j < n2; j++){
        right[j] = malloc(sizeof(char) * 128);
        strcpy(right[j], arr[m + 1 + j]);
    }
        
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (strcmp(left[i], right[j]) < 0) {
            strcpy(arr[k], left[i]);
            free(left[i]);
			i++;
		}
		else {
            strcpy(arr[k], right[j]);
            free(right[j]);
			j++;
		}
		k++;
	}

	while (i < n1) {
        strcpy(arr[k], left[i]);
        free(left[i]);
        i++;
		k++;
	}

	while (j < n2) {
		strcpy(arr[k], right[j]);
        free(right[j]);
		j++;
		k++;
	}
    free(left);
}

void mergeSort(char **arr, int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


void printArray(char **arr, int size){
	for (int i = 0; i < size; i++)
		printf("%s ", arr[i]);
	printf("\n");
}


int main(){
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
	mergeSort(arr, 0, testCase - 1); 
	gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;     
    fprintf(fp,"\t%f", diff / 1000000.0);

	return 0; 
}
