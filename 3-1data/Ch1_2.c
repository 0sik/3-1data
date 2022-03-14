#include<stdio.h>
#include<time.h>
int main(void) {
	//time 은 초단위여서 clock에비해 잘안씀
	int i;
	//clock_t start, stop;
	time_t start, stop;
	double sum = 0.0, duration;
	//start = clock();
	start = time(NULL);
	for (i = 0; i < 1000000000; i++){
		sum = sum + i;

	}
	//stop = clock();
	stop = time(NULL);
	//duration = (double)(stop - start)/CLOCKS_PER_SEC;
	duration = difftime(stop, start);
	printf(">sum = %lf, exe time = %lf sec \n ", sum,duration);


	return 0; //정상종료
}