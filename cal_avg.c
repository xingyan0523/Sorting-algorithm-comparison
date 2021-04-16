#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char **argv){
    FILE *fp = fopen("./result", "a+");
	int times = 1;
    double sum[3] = {0};
    char buf[512];

    if(argc > 1){
        times = atoi(argv[1]);
    }

    while(fgets(buf ,512, fp)){
        int offset = 0;
        for(int i = 0; i < 3; i++){
            double tmp;
            sscanf(buf + offset, "%lf", &tmp);
            offset += 9;
            sum[i] += tmp;
        }
        
    }

    for(int i = 0; i < 3; i++){
        sum[i] /= times;
    }
    fprintf(fp, "Average:\n");
    fprintf(fp, "quicksort\tmergesort\theapsort\n");
    fprintf(fp, "%lf\t%lf\t%lf\n", sum[0], sum[1], sum[2]);

	
    return 0;
}