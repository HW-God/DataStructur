#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, a[105];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	//希尔排序：时间复杂度：当n在常见范围内，O(n^1.3),最坏情况下O(n^2)。就地排序。不稳定。
	int k = 0;//排序的趟数
	int j, x;
	for (int d = n / 2; d >= 1; d /= 2)
	{
		k++;
		for (int i = 1; i <= n-d; i++)
		{
			x = a[i + d];
			for (j = i; j >= 1; j -= d)
			{
				if (a[j] > x)
				{
					a[j + d] = a[j];
				}
				else break;
			}
			a[j + d] = x;
		}

		printf("第%d趟排序得到的结果:", k);
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");


	}






	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
/*
10
8 9 1 7 2 3 5 4 6 0
*/