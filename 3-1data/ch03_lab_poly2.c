#include <stdio.h>
#define MAX_TERMS 101
struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {5,6}, {4,4}, {7,2}, {2,1}, {9,0},{7,4},{2,3},{5,2},{3,0} };//�ΰ��� ���׽İ� ������� �� 2�����迭�� ����
int avail = 9;//��� ���� �����ϴ� ��ġ

char compare(int a, int b);
void attach(float coef, int expon);
poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce);
void print_poly(int s, int e);

//
int main(void)
{
	int As = 0, Ae = 4, Bs = 5, Be = 8, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}

// �� ���� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰��Ѵ�.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;//expon�� ���� �ְ� avail����
}

// C = A + B
poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>': 	// A�� ���� > B�� ����
			attach(terms[As].coef, terms[As].expon);
			As++;			break;
		case '=': 	// A�� ���� == B�� ����
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++; Bs++;		break;
		case '<': 	// A�� ���� < B�� ����
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;			break;
		}

	// A�� ������ �׵��� �̵���
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	// B�� ������ �׵��� �̵���
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}