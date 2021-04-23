all: cal_avg data_gen heapsort mergesort quicksort test

cal_avg: cal_avg.c
	gcc cal_avg.c -g -o cal_avg

data_gen: data_gen.c
	gcc data_gen.c -g -o data_gen

heapsort: heapsort.c
	gcc heapsort.c sort.c sort.h -g -o heapsort

mergesort: mergesort.c
	gcc mergesort.c sort.c sort.h -g -o mergesort

quicksort: quicksort.c
	gcc quicksort.c sort.c sort.h -g -o quicksort

test: test.c
	gcc test.c -g -o test

clean:
	rm cal_avg 
	rm data_gen 
	rm heapsort 
	rm mergesort 
	rm quicksort 
	rm test
	rm result