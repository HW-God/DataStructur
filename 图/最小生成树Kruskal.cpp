#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//给定一个带权无向连通图，该图含有n(<=100)个点，m条边。
//要求 找到该图的最小生成树，输出最小生成树的边权和。n个点的数据0～～n-1。边权都小于10000
//邻接矩阵存图时间复杂度O(n^2)  邻接表存图时间复杂度O(n^2)
//排序算法的时间复杂度决定了该算法的时间复杂度
int n, m;
int fa[105];
typedef struct
{
	int x;
	int y;//一条边的两个端点
	int w;//权值
}Edge;
Edge e[10000];

void Sort(int l,int r)
{
	int minn;
	Edge edge;
	for (int i = l; i <= r; i++)
	{
		minn = i;
		for (int j = i + 1; j <= r; j++)
		{
			if (e[j].w < e[minn].w)
			{
				minn = j;
			}
		}
		edge = e[minn];
		e[minn] = e[i];
		e[i] = edge;
	}
}

int Find(int x)
{
	if (fa[x] == x)return x;
	else return fa[x] = Find(fa[x]);
}

void Kruskal()
{
	int sum = 0,num=0;//边权和，统计边的个数
	int rx, ry;

	// 初始化所有点的父亲为自己
	for (int i = 1; i <= n; i++)
		fa[i] = i;


	for (int i = 1; i <= m; i++)
	{
		rx = Find(e[i].x);
		ry = Find(e[i].y);
		//如果二者没有连通则按照顺序将其连通
		if (rx != ry)
		{
			fa[rx] = ry;
			sum += e[i].w;
			num++;
			printf("%d %d : %d\n", e[i].x, e[i].y, e[i].w);
		}
		if (num == n - 1)break;
	}
	printf("sum:%d",sum);
}

int main()
{
	int x, y;


	scanf(" %d %d", &n, & m);

	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		e[i].x = x;
		e[i].y = y;
		e[i].w = w;
	}
	Sort(1,m);//以边权大小进行排序
	Kruskal();

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
