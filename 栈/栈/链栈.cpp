#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	Node* next;
}Node,*LinkList;

void Init(LinkList *L)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	*L = head;
}

void Push(LinkList L, int k)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	p->next = L->next;
	L->next = p;
}

void Pop(LinkList L)
{
	if (L->next != NULL)
	{
		Node* p = L->next;
		L->next = L->next->next;
		printf("%d出栈\n", p->data);
		free(p);
	}
	else
		printf("栈空，无法出栈\n");
}

int front(LinkList L)
{
	if (L->next != NULL)
	{
		printf("栈顶为%d\n", L->next->data);
		return L->next->data;
	}
	else
	{
		printf("栈空 \n");
		return -1;
	}
}

int IsEmpty(LinkList L)
{
	if (L->next == NULL)return 1;
	return 0;
}

int main()
{
	LinkList L=NULL;
	Init(&L);
	front(L);
	Pop(L);
	

	Push(L, 1);
	front(L);
	Push(L, 2);
	front(L);
	Push(L, 3);
	front(L);

	if (IsEmpty(L))printf("该栈为空栈\n");
	else printf("该栈为非空栈\n");
	Pop(L);
	Pop(L);
	Pop(L);
	Pop(L);
	if (IsEmpty(L))printf("该栈为空栈\n");
	else printf("该栈为非空栈\n");
}