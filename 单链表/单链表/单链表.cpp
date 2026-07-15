#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkList;

void InitLink(LinkList *L)
{
	LinkList Head=(Node*)malloc(sizeof(Node));
	Head->next = NULL;
	*L = Head;
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
	Node* p =L;
	s->data = k;
	s->next = NULL;

	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}

Node* Find(LinkList L,int k)
{
	Node* p = L->next;
	while (p != NULL && p->data != k)
	{
		p = p->next;
	}
	return p;
}

void Insert(LinkList L, int m, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	Node* p = L->next;
	s->data = k;
	while (p!=NULL &&p->data != m)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("%d插入失败,查找的值不存在\n",k);
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
}

void Delete(LinkList L, int k)
{

	Node* p = L->next;
	Node* pre = L;
	while (p != NULL && p->data != k)
	{
		pre = p;
		p = p->next;
	}

	if (p == NULL)
	{
		printf("%d不存在，无法删除!\n", k);
	}
	else
	{
		pre->next = p->next;
	}
	free(p);
	p = NULL;
}

void Modify(LinkList L, int m, int k)
{
	Node* p;
	p=Find(L, m);
	if (p == NULL)
	{
		printf("%d不存在，无法修改\n",m);
	}
	else
	{
		p->data = k;
	}
}
void Show(LinkList L)
{
	Node* p = L->next;
	while (p!= NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList L=NULL;
	InitLink(&L);
	HeadInsert(L, 1);
	HeadInsert(L, 2);
	HeadInsert(L, 3);
	Show(L);
	RearInsert(L, 4);
	RearInsert(L, 5);
	RearInsert(L, 6);
	Show(L);

	Insert(L, 3, 7);
	Insert(L, 2, 8);
	Show(L);

	Delete(L, 7);
	Delete(L, 8);
	Show(L);
	Node*p=Find(L, 1);
	printf("%d\n",p->data); 
	Node* p2 = Find(L, 8);
	Show(L);

	Modify(L,3, 9);
	Show(L);



}