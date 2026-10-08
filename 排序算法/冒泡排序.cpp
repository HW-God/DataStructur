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

	//冒泡排序：时间复杂度：最好O(n)   最坏和平均O(n^2)  就地排序  稳定的排序
	int flag = 0;//标记本趟是否发生交换
	for (int i = 1; i <= n - 1; i++)
	{
		flag = 0;
		for (int j = 1;j<=n-i;j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		//如果该次未进行交换操作则说明数据已经有序
		if (flag == 1)
			break;
	}





	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
