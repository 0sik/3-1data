#include <stdio.h>
#include <stdlib.h>

// 스택이 전역 변수로 구현된다. 
// 스택 element : int
#define	MAX_STACK_SIZE	100		// 스택의 최대 크기

typedef int element;

typedef struct {
	element *data;
	int capacity;
	int	top;
} StackType;
	

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (s->capacity-1));
}
// 삽입 함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		//2배로 저장 용량 확대.
		s->capacity *= 2;
		s->data = (element*)realloc(s->data,s->capacity*sizeof(element));
		printf("<FULL>용량 = %d 개\n", s->capacity);
	}
	(s->top)++;
	s->data[s->top] = item;
	
}
// 삭제 함수
element pop(StackType* s)
{
	element temp;
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		temp = s->data[s->top];
		(s->top)--;
		return temp;
	}
}
// 피크 함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


void print_stack(StackType* s)
{
	// 1. 스택에 있는 ele. 수 출력 = top + 1
	printf("Stack (%d 개) : ", s->top + 1);
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
