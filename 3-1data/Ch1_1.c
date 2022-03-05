#include<stdio.h>

int main() {
    int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int i, sum = 0, count = 0;
    int max = 0;
    int min = 0;
    //합 구하기
    for (i = 0; i < 10; i++) {
        sum += data[i];
    }
    printf("합:%d", sum);
    //최대값 구하기
    max = data[0];
    for (i = 1; i < 10; i++)
    {
        if (max < data[i]) {
            max = data[i];
        }
    }
    printf("최대값:%d", max);
    //최소값 구하기
    min = data[0];
    for (i = 1; i < 10; i++)
    {
        if (min > data[i]) {
            min = data[i];
        }
    }
    printf("최소값:%d", min);
    //짝수의 개수 구하기
    for (i = 0; i < 10; i++) {
        if (data[i] % 2 == 0) {
            count++;
        }

    }
    printf("짝수의 개수:%d", count);

    //홀수의 개수 구하기
    //count 초기화
    count = 0;
    for (i = 0; i < 10; i++) {
        if (data[i] % 2 == 1) {
            count++;
        }

    }
    printf("홀수의 개수:%d", count);
}