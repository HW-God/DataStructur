#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	Node* next;
	Node* pre;
}Node,*LinkList;
 
void InitList(LinkList* L)
{
	Node* Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	Head->pre = NULL;
	*L = Head;
}

Node* Find(LinkList L, int k)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p = L->next;
	while (p!=NULL && p->data != k)
	{
		p = p->next;
	}
	return p;
}

void HeadInsert(LinkList L,int k)
{
	Node*s = (Node*)malloc(sizeof(Node));
	s->data = k;

	s->next = L->next;
	L->next = s;
	s->pre = L;
	if(s->next!=NULL)s->next->pre = s;
}

void RearInsert(LinkList L, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = NULL;

	Node* p = (Node*)malloc(sizeof(Node));
	p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
	s->pre = p;
}

void Insert(LinkList L, int d, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s = Find(L, d);
	if (s == NULL)
	{
		printf("插入失败\n");
	}
	else
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = k;
		p->next = s->next;
		s->next = p;
		p->pre = s;
		if (p->next != NULL)p->next->pre = p;
	}
}

void Delete(LinkList L, int k)
{
	Node* s;
	s = Find(L, k);
	if (s == NULL)
	{
		printf("%d不存在，无法删除\n", k);
	}
	else
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p = s->pre;
		p->next = s->next;
		if (s->next != NULL)s->next->pre = p;
		free(s);
		s = NULL;
	}
}

void Modify(LinkList L,int d, int k)
{
	Node* s;
	s = Find(L, d);
	if (s == NULL)
	{
		printf("修改失败！\n");
	}
	else
	{
		s->data = k;
	}
}

void Show(LinkList L)
{
	L = L->next;
	while (L!=NULL)
	{
		printf("%d ", L->data);
		L = L->next;
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
	Insert(L, 2, 8);
	Show(L);

	Delete(L, 7);
	Delete(L, 8);
	Show(L);
	Node* p = Find(L, 1);
	printf("%d\n", p->data);
	Node* p2 = Find(L, 8);
	Show(L);

	Modify(L, 3, 9);
	Show(L);

}