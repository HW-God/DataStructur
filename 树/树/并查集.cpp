#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, m;//n个数据为1~n，m次操作，n和m均小于100
int f[105];//f[i]=j,j为i的根节点，根节点的结果为自己本身
int h[105];//标记每个集合树的高度

int Max(int a, int b) { return a > b ? a : b; }

int Find(int x)
{
	if (f[x] == x)return x;
	else
	{
		int p = Find(f[x]);
		f[x] = p;//让根结点直接做每个结点的父亲----->路径压缩
		return p;
	}
}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;//初始时所有数据独自为一个集合
		h[i] = 1;
	}

	while (m--)
	{
		//op==1 合并 ，op==2 查询
		int op, x, y ,rx ,ry;
		scanf("%d %d %d", &op, &x, &y);
		if (op == 1)
		{
			rx = Find(x);
			ry = Find(y);
			if (rx != ry)
			{	//按秩合并：合并时 高的树的根结点做父亲
				if (h[rx] > h[ry])
				{
					f[ry] = rx;
					h[rx] = Max(h[rx], h[ry] + 1);
				}
				else
				{
					f[rx] = ry;
					h[ry] = Max(h[ry], h[rx] + 1);
				}
			}

		}
		else
		{
			rx = Find(x);
			ry = Find(y);
			if (rx == ry)printf("Y\n");
			else printf("N\n");
		}
	}
}
/*
8 6
2 3 7
1 3 7
2 3 7
1 7 6
1 4 8
2 8 3
*/