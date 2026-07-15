#include<stdio.h>
#include<stdlib.h>

//定义左端指针指向真正数据，右端指针指向真正数据的下一个

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

typedef struct
{
	Node* l;
	Node* r;
}Deque;

void Init(Deque* q)
{
	Node*s = (Node*)malloc(sizeof(Node));
	Node* head = (Node*)malloc(sizeof(Node));
	head->pre = s;
	head->next = NULL;
	s->next = head;
	s->pre = NULL;

	q->r = q->l = head;
}

void LInsert(Deque* q, int k)
{
	q->l->pre->data = k;
	q->l = q->l->pre;
	Node* s = (Node*)malloc(sizeof(Node));
	s->pre = NULL;
	s->next = q->l;
	q->l->pre = s;
}

void RInsert(Deque* q, int k)
{
	q->r->data = k;
	Node* s = (Node*)malloc(sizeof(Node));
	q->r->next = s;
	s->pre = q->r;
	s->next = NULL;
	q->r = s;
}

void LDelete(Deque* q)
{
	if (q->l == q->r)
	{
		printf("队空，无法删除\n"); 
			return;
	}
	Node* s = q->l;
	printf("%d出栈\n", q->l->data);
	q->l = q->l->next;
	q->l->pre = NULL;
	free(s);
}

void RDelete(Deque* q)
{
	if (q->l == q->r)
	{
		printf("队空，无法删除\n");
		return;
	}
	Node* s = q->r;
	q->r = q->r->pre;
	printf("%d出栈\n", q->r->data);
	q->r->next = NULL;
	free(s);
}

int main()
{
	Deque q;
	Init(&q);
	LInsert(&q, 1);
	LInsert(&q, 2);
	LInsert(&q, 3);
	RInsert(&q, 4);
	RInsert(&q, 5);
	RInsert(&q, 6);

	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);

	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
}