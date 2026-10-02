#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 10001
//n（<=100）个点,m条边的带权(边权<10000)无向图，求起点s到其他点的最短路径。//保证起点一定能走到其他点
//默认点的数据是0～～n-1
//邻接矩阵存图或者邻接表 时间复杂度是O(n^2)
int n, m;
int g[105][105];
int dist[105];//当前顶点距离树的距离
int flag[105];//1表示当前顶点已经是最短的
int pre[105];//当前点的最短距离的前一个点

void Dijkstra(int x)
{

	flag[x] = 1;
	dist[x] = 0;

	int Min = INF;//记录当前离树最近的距离
	int k;//记录当前离树最近点的下标
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0 && dist[i] > g[x][i])
		{
			pre[i] = x;
			dist[i] = g[x][i];
		}
	}


	for (int i = 1; i <= n - 1; i++)
	{
		Min = INF;
		k = -1;
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] < Min)
			{
				Min = dist[j];
				k = j;
			}
		}
		if (k == -1) continue;
		flag[k] = 1;

		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] > dist[k] + g[k][j])
			{
				dist[j] = dist[k] + g[k][j];
				pre[j] = k;
			}
		}
	}
}


int main()
{
	scanf("%d %d", &n, &m);

	//初始化数组
	for (int i = 0; i < n; i++)
	{
		//开始时所有点离树的距离均为INF,前一个点均为-1不存在
		dist[i] = INF;
		pre[i] = -1;
		for (int j = 0; j < n; j++)
			g[i][j] = INF;
	}

	int x, y, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = g[y][x] = w;
	}

	int s;//起点
	scanf("%d", &s);
	Dijkstra(s);

	for (int i = 0; i < n; i++)
	{
		//s---->i的最短路径
		printf("%d到%d的最短距离是%d,", s, i, dist[i]);
		printf("最短路径为：%d ", i);//输出终点
		int p = pre[i];
		while (p != -1)//依次输出前面的点
		{
			printf("%d ", p);
			p = pre[p];
		}
		printf("\n");
	}

}
/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/