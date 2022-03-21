#include<stdio.h>

int fib(int n)
{
	int result;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n >= 2){
		result = fib(n - 1) + fib(n - 2);
		return result;
	}
	else
	{
		printf("양수를 입력하세요");
		return -1;
	
	}
}

int fib_iter(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	int pp = 0;
	int p = 1;
	int result = 0;
	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}


int main(void) {
	int result;
	for (int i = 0; i <= 40; i++) {
		result = fib(i);
		printf("-fib(%d) = %d \n", i, result);
	}

}