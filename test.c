#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



// ./test -type times
// type -s = string -n = integer
int main (int argc, char **argv){
   

    int times = 1;
    char avg[128] = "./cal_avg ";
    
        
    if(argc > 2){
        times = atoi(argv[2]);
        strcat(avg, argv[2]);
    }

    char data_gen[128] = "./data_gen ";
    char quick[128] = "./quicksort";
    char merge[128] = "./mergesort";
    char heap[128] = "./heapsort";

    strcat(data_gen, argv[1]);
    if(!strcmp(argv[1], "-s")){
        strcat(quick, " -s < dataset2.txt");
        strcat(merge, " -s < dataset2.txt");
        strcat(heap, " -s < dataset2.txt");
    }
    else{
        strcat(quick, " -n < dataset1.txt");
        strcat(merge, " -n < dataset1.txt");
        strcat(heap, " -n < dataset1.txt");
    }


    for(int i = 0; i < times; i++){
        system(data_gen);
        system(quick);
        system(merge);
        system(heap);
    }

    
    system(avg);


    return 0;
}