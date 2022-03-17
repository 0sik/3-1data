#include<stdio.h>
#include<time.h>

//factorial 함수를 반복적 방법(iterative)으로 구현
int factorial_iter(int n) {
	int result = 1;
	if (n > 0) {
		for (int i = n; i > 1; i--) {
			result = result * i;
		}
	}
	else {
		printf("<경고>해당 숫자에 대해서 fcatorial이 정의되지 않음.");
		return 0;
	}
	return result;
}

int factorial(int n) {
	int result = 1;
	if (n == 1) {
		return 1; //더이상 재귀 호출을 하지 않는 경우..
	}
	else {
		result = n * factorial(n - 1);
	}
	return result;
}

int main(void) {
	int result;
	double duration;
	clock_t start, stop;
	start = clock();
	for (int i = 2; i < 10; i++) {
		result = factorial_iter(i);
		//result = factorial(i);
		printf("fact(%d)=%d\n", i, result);
	}
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf(">실행시간 = %f sec \n", duration);
	return 0;
}

