#include<stdio.h>
#include<time.h>
//�ݺ����
double slow_power(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result = result * x;
	}
	return result;
}
//��ȯ���
double power(double x, int n) {
	double result;
	if (n == 0) {
		return 1.0;
	}
	else if (n % 2 == 0) { //n�� ¦��
		result = power(x * x, n / 2);
		printf("power>result = %lf\n", result);
		return result;
	}
	else{ //n�� Ȧ��
		result = x * power(x * x, (n - 1) / 2);
		printf("power-odd>result = %lf\n", result);
		return result;
	
	}
}
int main(void) {
	double result;
	//2^i �ŵ�����
	for (int i = 2; i <= 15; i++) {
		result = power(2.0, i);
		printf("2^%d = %lf\n", i, result);
		
	}


	return 0;
}