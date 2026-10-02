#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//链栈
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LinkStack;

LinkStack Init()
{
	LinkStack s = (LinkStack)malloc(sizeof(Node));
	s->next = NULL;
	return s;
}

LinkStack Push(LinkStack st, int k)
{
	LinkStack s = (LinkStack)malloc(sizeof(Node));
	s->data = k;
	s->next = st->next;
	st->next = s;
	return st;
}

LinkStack Pop(LinkStack st)
{
	if (st->next == NULL)
	{
		printf("栈空\n");
	}

	LinkStack p=NULL;
	p = st->next;
	st->next = p->next;
	free(p);
	p = NULL;
	return st;
}

int GetTop(LinkStack st)
{
	return st->next->data;
}

int IsEmpty(LinkStack st)
{
	if (st->next == NULL)return 1;
	else return 0;
}

//////////////图/////////////////
//含有n个点m条边的有向图 n<100
//邻接表存图

int n, m;

typedef struct ENode
{
	int data;
	struct ENode* next;
}ENode;

struct
{
	int data;
	ENode* first;
}g[105];
char V[105];//顶点数组 
int pre[105];//每个点的入度
char Topo[105];
int k = 0;

int Find(char x)
{
	int i = 1;
	for (; i <= n; i++)
	{
		if (V[i] == x)break;
	}
	return i;
}

void TopoSort()
{
	LinkStack st=NULL;
	st = Init();
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == 0)Push(st, i);
	}

	while (!IsEmpty(st))
	{
		int q = GetTop(st);
		Pop(st);
		Topo[++k] = V[q];
		//遍历当前该点的邻接点，同时相应的入度--
		ENode* p = g[q].first;
		while (p != NULL)
		{
			pre[p->data]--;
			if (pre[p->data] == 0)Push(st, p->data);
			p = p->next;
		}
	}
}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &V[i]);
		g[i].data = i;
		g[i].first = NULL;
	}
	char x, y;
	int rx, ry;




	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c", &x, &y);
		rx = Find(x);
		ry = Find(y);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->data = ry;
		s->next = g[rx].first;
		g[rx].first = s;
		pre[ry]++;
	}
	TopoSort();

	if (k < n)
	{
		printf("有环\n");
	}
	else
	{
		//输出拓扑序列
		for (int i = 1; i <= k; i++)
		{
			printf("%c ", Topo[i]);
		}
	}
}
/*
6 8
ABCDEF
A B
A C
A D
C B
C E
F D
F E
D E
*/
