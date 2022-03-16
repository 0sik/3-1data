#include<stdio.h>

int factorial(int n)
{
	if (n <= 1) return(1);
	else return (n * factorial_n_1(n - 1));
}
int factorial2(int n)
{
	if (n <= 1) return(1);
	else return (n * factorial2(n - 1));
}
int factorial_iter(int n)
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return(v);
}
