#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//带权无向图为例。n个点 m条边  n<100  0<=w<=10000
//多重邻接表的结点结构
typedef struct ENode
{
	int u;
	struct ENode* Unext;
	int v;
	struct ENode* Vnext;
	int w;
}ENode;

struct Graph
{
	char data;
	ENode* first;
}graph[105];

int Find(char x, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (graph[i].data == x)break;
	}
	return i;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &graph[i].data);
		graph[i].first = NULL;
	}
	
	char x, y;
	int w, xi, yi;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x, n);
		yi = Find(y, n);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->u = xi;
		s->v = yi;
		s->w = w;
		
		s->Unext = graph[xi].first;
		graph[xi].first = s;

		s->Vnext = graph[yi].first;
		graph[yi].first = s;
	}

	scanf(" %c", &x);
	xi = Find(x, n);
	ENode*p = graph[xi].first;
	int d=0;

	while (p != NULL)
	{
		d++;
		if (p->u == xi)p = p->Unext;
		else p = p->Vnext;
	}
	printf("%d", d);
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