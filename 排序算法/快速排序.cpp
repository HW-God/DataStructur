#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, a[105];

void Sort(int l,int r)
{
	if (l >= r)return;
	int i = l, j = r;
	int x = a[l];
	while (i < j)
	{
		for (j; j > i; j--)
		{
			if (a[j] < x)
			{
				a[i] = a[j];
				break;
			}
		}

		for (; i < j; i++)
		{
			if (a[i] > x)
			{
				a[j] = a[i];
				break;
			}
		}
	}
	a[i] = x;
	Sort(l, i - 1);
	Sort(i + 1, r);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	Sort(1, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
