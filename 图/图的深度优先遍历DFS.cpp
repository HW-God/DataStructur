#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//有n（<=100）个点 m条边的无权无向图 对该图进行遍历。
//DFS时间复杂度：邻接矩阵存图:O(n^2)    邻接表存图O(n+m)    
//采用邻接矩阵存储图

char v[105];//顶点数组
int g[105][105] = {0};//邻接矩阵 g[i][j]=g[j][i]=1 存在i----j
int flag[105];//标记数组 标记某点是否访问过

int Find(int n, char x)
{
	int i = 0;
	for (i; i < n; i++)
	{
		if (v[i] == x)break;
	}
	return i;
}

void DFS(int n,int x)
{
	printf("%c", v[x]);
	flag[x] = 1;
	for (int j = 0; j < n; j++)
	{
		if (g[x][j] == 1 && flag[j] != 1)
		{
			DFS(n, j);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)//存储顶点
	{
		scanf(" %c", &v[i]);
	}

	char x, y;
	int xi, yi;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c %c", &x, &y);
		xi = Find(n,x);
		yi = Find(n, y);
		g[xi][yi] = g[yi][xi] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (flag[i] != 1)
		{
			DFS(n,i);
		}
	}

}
/*
9 16
ABCDEFGHI
A B
A F
B G
G F
B C
B I
C I
C D
I D
D G
D H
D E
G H
H E
E F
F G
*/