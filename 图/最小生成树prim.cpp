#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 10001
//给定一个带权无向连通图，该图含有n(<=100)个点，m条边。要求 找到该图的最小生成树，输出最小生成树的边权和。n个点的数据0～～n-1。边权都小于10000
//邻接矩阵存图时间复杂度O(n^2)  邻接表存图时间复杂度O(n^2)
int g[105][105];
int dis[105];//标记dis[i]=x，点i到树的距离
int flag[105];//flag为1 代表该点已经访问过了
int n, m;
int sum = 0;//边权之和

int Min(int x, int y) { return x < y ? x : y; }

void prim(int x)
{
	//初始化所有点到树的距离为INF
	for (int i = 0; i < n; i++)
		dis[i] = INF;

	dis[x] = 0;
	flag[x] = 1;
	for (int i = 0; i < n; i++)
	{
		if (g[x][i] != INF && flag[i] == 0)
		{
			dis[i] = Min(dis[i], g[x][i]);
		}

	}

	for (int i = 1; i <= n - 1; i++)
	{
		int minn = INF;//当前最短的距离
		int k=-1;//最短距离的顶点
		for (int j = 0; j < n; j++)
		{
			if (flag[j]==0 && dis[j] < minn)
			{
				minn = dis[j];
				k = j;
			}
		}
		if (k != -1)
		{
			flag[k] = 1;
			sum += minn;
			printf("点%d 通过边权为%d的边 连到生成树上\n", k, minn);
		}
		for (int j = 0; j < n; j++)
		{
			if (g[k][j] != INF && flag[j] == 0)
			{
				dis[j] = Min(dis[j], g[k][j]);
			}
		}
	}
	printf("%d", sum);
}

int main()
{
	int x, y, w;
	scanf("%d %d", &n, &m);
	//初始化邻接矩阵，不存在边的两点间距离为INF
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			g[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = g[y][x] = w;
	}

	prim(1);
}
/*
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
*/