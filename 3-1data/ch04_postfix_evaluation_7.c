#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;
//
void init_stack(StackType* s)
{
    s->top = -1;
}
//
int is_empty(StackType* s)
{
    return (s->top == -1);
}
//
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
//
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
//
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
//
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}
int prec(char op)
{
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}
void infix_to_postfix(char exp[], char* result)//중위 표기식을 후위 표기식으로 바꾸는거
{
    int i = 0, loc = 0;
    char ch, top_op, t;
    int len = strlen(exp);
    StackType s;
    init_stack(&s);               // 스택 초기화 

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/': // 연산자
           // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                t = pop(&s);
                printf("%c", t);
                result[loc++] = t;
            }
            push(&s, ch);
            break;
        case '(':   // 왼쪽 괄호
            push(&s, ch); 
            break;
        case ')':   // 오른쪽 괄호
            top_op = pop(&s);
            
            // 왼쪽 괄호를 만날때까지 출력
            while (top_op != '(') {
                printf("%c", top_op);
                result[loc++] = top_op;
                top_op = pop(&s);
                
            }
            break;
        default:      // 피연산자
            printf("%c", ch);
            result[loc++] = ch;
            break;
        }
    }
    i = 0;
    while (!is_empty(&s)) {
        // 스택에 저장된 연산자들 출력
        ch = pop(&s);
        result[loc++] = ch;
        printf("%c", ch);
    }
    result[loc++] = '\0';
    printf("\n");
}
// 후위 표기 수식 계산 함수
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';   // 입력이 피연산자이면
            push(&s, value);
        }
        else {   // 연산자이면 피연산자를 스택에서 제거
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {   // 연산을 수행하고 스택에 저장 
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}
//

int main(void)
{
    int result;
    char* s = "(2+3)*4+9";
    char* r = malloc(sizeof(char) * strlen(s) + 1);
    infix_to_postfix(s, r);
    result = eval(r);
    printf("결과값은 %d\n", result);

    free(r);
    return 0;
}
//(2+3)*2+3-5 를 후위 표기식으로 바꾸기
//답 : 23+2*3+5-
// 1. (          2
// 2. (+         23
// 3.            23+
// 4. *          23+2
// 5. +          23+2*
// 6. +          23+2*3
// 7. -          23+2*3+
// 8. -          23+2*3+5
// 9.            23+2*3+5-
