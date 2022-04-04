#include <stdio.h>
#include <stdlib.h>

// 스택이 전역 변수로 구현된다. 
// 스택 element : int
#define	MAX_STACK_SIZE 100		// 스택의 최대 크기
typedef	int element;			// 데이터의 자료형
element stack[MAX_STACK_SIZE];	// 1차원 배열
int  top = -1;			

// 공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	//else stack[++top] = item; 밑에 코드를 줄인것
	else {
		top++;
		stack[top] = item;
	}
}
// 삭제 함수
element pop()
{
	element temp;
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	//else return stack[top--]; 밑에 코드를 줄인것
	else {
		temp = stack[top];
		top--;
		return temp;
	}
}
// 피크 함수
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}
void print_stack(void) {
	//1.스택에 있는 ele. 수 출력 = top + 1
	printf("Stack (%d개) : ", top + 1);
	for (int i = 0; i <= top; i++) {
		printf("[%d]", stack[i]);
	}
	printf("\n");
}
int main(void)
{
	push(1);
	print_stack();
	push(2);
	print_stack();
	push(3);
	print_stack();
	printf("%d\n", pop());
	print_stack();
	printf("%d\n", pop());
	print_stack();
	printf("%d\n", pop());
	print_stack();
	return 0;
}
