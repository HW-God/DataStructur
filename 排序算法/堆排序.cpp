#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, a[105];
//选择排序下都是大根堆

void Swap(int x, int y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

//向上调整，一边读入数据，一边调整
void UpAdjust(int x)
{
	int now = x;
	int f = x / 2;
	while (f >= 1)
	{
		if (a[now] > a[f])
		{
			Swap(now, f);
			now = f;
			f = now / 2;
		}
		else break;
	}
}

//向下调整，先读数据再统一调整
//从下标为x的子树开始，不断调整，直至根节点 1
//len表示堆在数组中所占有的长度
void DownAdjust(int x, int len)
{
	for (int i = x ; i >= 1; i--)
	{
		int now = i;
		int chi;
		while (2*now <= len)
		{
			chi = 2 * now;
			if (chi < len && a[chi] < a[chi+1])chi++;
			if (a[chi] > a[now])
			{
				Swap(chi, now);
				now = chi;
			}
			else break;
		}
	}

}


int main()
{

	scanf("%d", &n);

	////////////////////////////////////////////////
	//      向上建堆
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		UpAdjust(i);
	}
	
	for (int i = 1; i < n; i++)
	{
		Swap(1, n - i + 1);
		int now = 1;
		int next;
		while (2*now<=n-i)
		{
			next = 2 * now;
			if (next < n - i && a[next] < a[next + 1])next++;
			if (a[now] < a[next])
			{
				Swap(now, next);
				now = next;
			}
			else break;
		}
		
	}


	////////////////////////////////////////////////
	//      向下建堆
	//for (int i = 1; i <= n; i++)
	//{
	//	scanf("%d", &a[i]);
	//}

	//DownAdjust(n/2,n);

	//for (int i = 1; i < n; i++)
	//{
	//	//每次建堆之后将最大的数放在队尾，然后对堆顶进行调整
	//	Swap(1, n - i + 1);
	//	DownAdjust(1,n-i);
	//}


	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
