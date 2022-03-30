#include<stdio.h>
void func(int *a, int *b);
int main() {
	int a = 1, b = 2;
	printf("1> a = %d, b = %d\n", a, b);
	func(&a,&b);
	printf("2> a = %d, b = %d\n", a, b);
	return 0;
}

void func(int *a, int *b) {
	int tmp;
	printf("func-1> a = %d, b = %d\n", *a, *b);
	tmp = *a;
	*a = *b;
	*b = tmp;

	printf("func-2> a = %d, b = %d\n", *a, *b);
}