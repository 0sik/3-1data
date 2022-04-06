#include <stdio.h>
#include <stdlib.h>

// ������ ���� ������ �����ȴ�. 
// ���� element : int
#define	MAX_STACK_SIZE	100		// ������ �ִ� ũ��

typedef int element;

typedef struct {
	element *data;
	int capacity;
	int	top;
} StackType;
	

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (s->capacity-1));
}
// ���� �Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		//2��� ���� �뷮 Ȯ��.
		s->capacity *= 2;
		s->data = (element*)realloc(s->data,s->capacity*sizeof(element));
		printf("<FULL>�뷮 = %d ��\n", s->capacity);
	}
	(s->top)++;
	s->data[s->top] = item;
	
}
// ���� �Լ�
element pop(StackType* s)
{
	element temp;
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		temp = s->data[s->top];
		(s->top)--;
		return temp;
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


void print_stack(StackType* s)
{
	// 1. ���ÿ� �ִ� ele. �� ��� = top + 1
	printf("Stack (%d ��) : ", s->top + 1);
	for (int i = 0; i <= s->top; i++) {
		printf("[%d] ", s->data[i]);
	}
	printf("\n");
}


void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element));
}


int main(void)
{
	StackType  s1;
	
	init_stack( &s1 );
	push(&s1, 1);
	print_stack(&s1);
	push(&s1, 2);
	print_stack(&s1);
	push(&s1, 3);
	print_stack(&s1);
	printf("%d\n", pop(&s1));
	print_stack(&s1);
	printf("%d\n", pop(&s1));
	print_stack(&s1);
	printf("%d\n", pop(&s1));
	print_stack(&s1);
	free(s1.data);
	return 0;
}
