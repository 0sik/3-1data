#include<stdio.h>

int main() {
	int data[4];
	get_data(data,4);
	for (int i = 0; i < 4; i++)
	{
		printf("%d", data[i]);
	}
	return 0;
}

get_data(int data[], int count) {
	printf("get_data> ���� %d���� �Է��ϼ���:",count);
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &data[i]);
	}
}

