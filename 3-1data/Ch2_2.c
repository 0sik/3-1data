#include<stdio.h>
#include<time.h>

//factorial �Լ��� �ݺ��� ���(iterative)���� ����
int factorial_iter(int n) {
	int result = 1;
	if (n > 0) {
		for (int i = n; i > 1; i--) {
			result = result * i;
		}
	}
	else {
		printf("<���>�ش� ���ڿ� ���ؼ� fcatorial�� ���ǵ��� ����.");
		return 0;
	}
	return result;
}

int factorial(int n) {
	int result = 1;
	if (n == 1) {
		return 1; //���̻� ��� ȣ���� ���� �ʴ� ���..
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
	printf(">����ð� = %f sec \n", duration);
	return 0;
}

