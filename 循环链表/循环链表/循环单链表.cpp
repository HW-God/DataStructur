#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkList;

void InitList(LinkList*L)
{
	Node* Head = (Node*)malloc(sizeof(Node));
	Head->next =Head;
	*L = Head;
}

Node * Find(LinkList L, int k)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p = L->next;
	while (p != L && p->data != k)
	{
		p = p->next;
	}
	return p;
}

void HeadInsert(LinkList L,int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = L->next;
	L->next = s;
}

void RearInsert(LinkList L, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;

	Node* p = L;
	while (p->next != L)
	{
		p = p->next;
	}
	p->next = s;
	s->next = L;
}

void Insert(LinkList L,int d, int k)
{
	Node* p = Find(L, d);
	if (p == L)
	{
		printf("²åÈëÊ§°Ü\n");
	}
	else
	{
		Node* s = (Node*)malloc(sizeof(Node));
		s->data = k;
		s->next = p->next;
		p->next = s;
	}
}

void Delete(LinkList L, int k)
{
	Node* p;
	p = L;
	while (p->next != L && p->next->data != k)
	{
		p = p->next;
	}
	if (p->next == L)printf("%d²»´æÔÚ,É¾³ýÊ§°Ü\n", k);
	else
	{
		Node* f;
		f = p->next;
		p->next = p->next->next;
		free(f);
		f = NULL;
	}
}

void Modify(LinkList L, int d, int k)
{
	Node* p;
	p = Find(L,d);
	if (p == L)printf("ÐÞ¸Ä´íÎó£¡\n");
	else
	{
		p->data = k;
	}
}

void Show(LinkList L)
{
	Node* p = L->next;
	while (p != L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}



int main()
{
	LinkList L;
	InitList(&L);
	HeadInsert(L, 1);
	HeadInsert(L, 2);
	HeadInsert(L, 3);
	Show(L);
	RearInsert(L, 4);
	RearInsert(L, 5);
	RearInsert(L, 6);
	Show(L);
	Insert(L, 3, 7);
	Show(L);
	Delete(L, 7);
	Show(L);
	Node* p = Find(L, 4);
	printf("%d\n", p->data);
	Modify(L, 3, 8);
	Show(L);
}