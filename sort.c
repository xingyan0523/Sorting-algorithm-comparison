#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"


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


void merge_str(char **arr, int l, int m, int r){
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

void mergeSort_str(char **arr, int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort_str(arr, l, m);
		mergeSort_str(arr, m + 1, r);
		merge_str(arr, l, m, r);
	}
}


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