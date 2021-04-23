#ifndef SORT
#define SORT



int partition (int *arr, int low, int high);
void quickSort(int *arr, int low, int high);


int partition_str (char **arr, int low, int high);
void quickSort_str (char **arr, int low, int high);

void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);

void merge_str(char **arr, int l, int m, int r);
void mergeSort_str(char **arr, int l, int r);

void heapmaintain(int *arr, int n, int i);
void heapSort(int *arr, int n);

void heapmaintain_str(char **arr, int n, int i);
void heapSort_str(char **arr, int n);

void swap(int* a, int* b);

#endif