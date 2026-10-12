#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, a[105];

void MergeSort(int l,int r)
{
	if (l >= r)return;
	int mid = (l + r) / 2;

	MergeSort(l, mid);
	MergeSort(mid + 1, r);

	int i = l, j = mid+1;
	int te[105],k=0;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
		{
			te[k] = a[i];
			k++;
			i++;
		}

		else
		{
			te[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		te[k] = a[i];
		i++;
		k++;
	}
	while (j <= n)
	{
		te[k] = a[j];
		j++;
		k++;
	}

	for (i = 0; i < k; i++)
	{
		a[i + l] = te[i];
	}
	return;
}

int main()
{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	//¹é²¢ÅÅÐò
	MergeSort(1,n);



	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
