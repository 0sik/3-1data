#include <stdio.h>
#include <stdlib.h>

// ������ ���� ������ �����ȴ�. 
// ���� element : int
#define	MAX_STACK_SIZE 100		// ������ �ִ� ũ��

typedef int element;

typedef struct  {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
		

// ���� ���� ���� �Լ�
int is_empty(StackType*s)
{ 
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(StackType* s,element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)]= item; 
	
}
// ���� �Լ�
element pop(StackType* s)
{

	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	//else return stack[top--]; �ؿ� �ڵ带 ���ΰ�
	else {
		return s->data[(s->top)--];
	}
}
// ��ũ �Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

void init_stack(StackType* s) {
	s->top = -1;
}
int main(void)
{
	StackType s1, s2, s3;
	init_stack(&s1);
	init_stack(&s2);
	init_stack(&s3);
	element temp;
	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);

	push(&s2, 100);
	push(&s2, 101);
	
	push(&s3, 200);
	push(&s3, 201);

	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s2));
	printf("%d\n", pop(&s3));

	return 0;
}
