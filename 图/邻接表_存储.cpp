//带权无向图为例。n个点 m条边  n<100  0<=w<=10000
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//节点
typedef struct ENode
{
	int data;
	int w;
	struct ENode* next;
}ENode;
//边数组
struct Edge
{
	char data;
	ENode* first;
}Edge[10005];

int Find(char x, int n)
{
	int i = 1;
	for ( i = 1; i <= n; i++)
	{
		if (Edge[i].data == x)
			break;
	}
	return i;
}

int main()
{
	int n, m;
	char x, y;
	int xi, yi, w;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &Edge[i].data);
		Edge[i].first = NULL;
	}

	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x, n);
		yi = Find(y, n);
		ENode* node=(ENode*)malloc(sizeof(ENode));
		node->data = y;
		node->w = w;
		node->next = Edge[xi].first;
		Edge[xi].first = node;

		ENode* node1 = (ENode*)malloc(sizeof(ENode));
		node1->data = x;
		node1->w = w;
		node1->next = Edge[yi].first;
		Edge[yi].first = node;
	}

	scanf(" %c", &x);
	xi = Find(x,n);
	int d = 0;//度
	ENode* p = Edge[xi].first;
	while (p != NULL)
	{
		d++;
		p = p->next;

	}
	printf("%d\n", d);

}
/*
4 5
ABCD
A B 3
A D 6
A C 0
B D 9
D C 4
*/