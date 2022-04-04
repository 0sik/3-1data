#include <stdio.h>
#include <stdlib.h>

// ������ ���� ������ �����ȴ�. 
// ���� element : int
#define	MAX_STACK_SIZE 100		// ������ �ִ� ũ��
typedef	int element;			// �������� �ڷ���
element stack[MAX_STACK_SIZE];	// 1���� �迭
int  top = -1;			

// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	//else stack[++top] = item; �ؿ� �ڵ带 ���ΰ�
	else {
		top++;
		stack[top] = item;
	}
}
// ���� �Լ�
element pop()
{
	element temp;
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	//else return stack[top--]; �ؿ� �ڵ带 ���ΰ�
	else {
		temp = stack[top];
		top--;
		return temp;
	}
}
// ��ũ �Լ�
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}
void print_stack(void) {
	//1.���ÿ� �ִ� ele. �� ��� = top + 1
	printf("Stack (%d��) : ", top + 1);
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
