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

	//选择排序：执行n-1趟排序：在当前的乱序区中找到最小的数据，将其和乱序区的第一个位置交换。

	int min;
	for (int i = 1; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[min] > a[j])min = j;
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}


	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
