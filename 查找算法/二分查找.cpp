#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, a[105], k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);

	//折半查找
	int mid, l = 1, r = n;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (k > a[mid])l = mid + 1;
		else if (k < a[mid])r = mid - 1;
		else break;
	}
	if (l <= r)printf("%d在数组中的下标:%d", k, mid);
	else printf("该数不存在数组中");

}