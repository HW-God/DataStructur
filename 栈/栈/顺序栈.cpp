#include<stdio.h>
#include<stdlib.h>
#define MAX 2

typedef struct
{
	int *sta;
	int top;
}Stack;

void Init(Stack *s)
{
	s->sta = (int*)malloc(sizeof(int)*MAX);
	s->top = 0;
}

void push(Stack *s, int k)
{
	if (s->top < MAX)s->sta[s->top++] = k;
	else
	{
		printf("栈满，无法入栈\n");
	}
}

int IsEmpty(Stack *s)
{
	if (s->top == 0)return 1;
	else return 0;
}

void pop(Stack *s)
{
	if (IsEmpty(s))printf("栈空，无法出栈\n");
	else
	{
		printf("%d出栈\n", s->sta[s->top - 1]);
		s->top--;
	}
}

void front(Stack s)
{
	if (!IsEmpty(&s))printf("栈顶为%d\n", s.sta[s.top - 1]);
	else printf("栈空\n");
}

int main()
{
	Stack s;
	Init(&s);
	
	front(s);
	pop(&s);

	push(&s, 1);
	front(s);
	push(&s, 2);
	front(s);
	push(&s, 3);
	front(s);
	
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	

}