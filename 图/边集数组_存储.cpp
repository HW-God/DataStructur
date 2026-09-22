//带权无向图为例。n个点 m条边  n<100  0<=w<=10000
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char vertex[10005];

typedef struct Edge
{
	int a, b;
	int w;
}Edge;


int Find(char x,int n)
{
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		if (vertex[i] == x)
		{
			break;
		}
	}
	return i;
}


int main()
{
	int n, m;
	char x, y;
	int  xi, yi,w;
	Edge edge[10001];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &vertex[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y,&w);
		xi = Find(x, n);
		yi = Find(y, n);
		edge[i].a = xi;
		edge[i].b = yi;
		edge[i].w = w;
	}
	//查找某一个点的度
	char c;
	scanf(" %c", &c);
	int ci = Find(c, n);
	int d = 0;
	for (int i = 1; i <= m; i++)
	{
		if (edge[i].a == ci || edge[i].b == ci)
		{
			d++;
		}
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