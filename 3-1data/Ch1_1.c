#include<stdio.h>

int main() {
    int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int i, sum = 0, count = 0;
    int max = 0;
    int min = 0;
    //�� ���ϱ�
    for (i = 0; i < 10; i++) {
        sum += data[i];
    }
    printf("��:%d", sum);
    //�ִ밪 ���ϱ�
    max = data[0];
    for (i = 1; i < 10; i++)
    {
        if (max < data[i]) {
            max = data[i];
        }
    }
    printf("�ִ밪:%d", max);
    //�ּҰ� ���ϱ�
    min = data[0];
    for (i = 1; i < 10; i++)
    {
        if (min > data[i]) {
            min = data[i];
        }
    }
    printf("�ּҰ�:%d", min);
    //¦���� ���� ���ϱ�
    for (i = 0; i < 10; i++) {
        if (data[i] % 2 == 0) {
            count++;
        }

    }
    printf("¦���� ����:%d", count);

    //Ȧ���� ���� ���ϱ�
    //count �ʱ�ȭ
    count = 0;
    for (i = 0; i < 10; i++) {
        if (data[i] % 2 == 1) {
            count++;
        }

    }
    printf("Ȧ���� ����:%d", count);
}