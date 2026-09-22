#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 10001
//带权无向图为例。n个点 m条边  n<=100  0<=w<=10000
int Graph[10005][10005];
char vertex[10005];


int Find(char x, int n)
{
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		if (vertex[i] == x)
			break;
	}
	return i;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, & m);
	char x, y;
	int xi, yi, w;
	//初始化刚开始时默认所有点之间均没有连线
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Graph[i][j] = inf;
		}
	}
	//存顶点
	for (int i = 1; i <= n; i++)
		scanf(" %c", &vertex[i]);
	//存边
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x, n);
		yi = Find(y, n);
		Graph[xi][yi] = w;
		Graph[yi][xi] = w;
	}

	scanf(" %c", &x);
	xi = Find(x, n);
	int d = 0;//度
	for (int j = 1; j <= n; j++)
	{
		if (Graph[xi][j] != inf)d++;
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