#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//带权有向图为例。n个点 m条边  n<100  0<=w<=10000
//十字链表的结点结构
typedef struct Edge
{
	int out;
	struct Edge* outnext;
	int in;
	struct Edge* innext;
	int w;
}Edge;

typedef struct Graph
{
	char data;
	Edge* firstout;
	Edge* firstin;
};
Graph graph[105];

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

	for (int i = 0; i < n; i++)//存储n个点
	{
		scanf(" %c", &graph[i].data);
		graph[i].firstout = graph[i].firstin = NULL;//给指向邻接点的指针赋空值
	}
	
	char x, y;
	int xi, yi, w;//x,y的下标，权值

	for (int i = 0; i < m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x, n);
		yi = Find(y, n);
		Edge* edge = (Edge*)malloc(sizeof(Edge));
		edge->out = xi;
		edge->in = yi;
		edge->w = w;
		edge->outnext = graph[xi].firstout;
		graph[xi].firstout =edge;

		edge->innext = graph[yi].firstin;
		graph[yi].firstin = edge;
	}


	scanf(" %c", &x);//查询某个点的入度和出度
	int out = 0, in = 0;
	xi = Find(x, n);
	Edge* p = graph[xi].firstin;
	while (p != NULL)
	{
		p = p->innext;
		in++;
	}
	p = graph[xi].firstout;
	while (p != NULL)
	{
		p = p->outnext;
		out++;
	}
	printf("in:%d ,out:%d", in, out);
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