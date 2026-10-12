#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n, a[105];
//计数排序

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	//稳定
	int cnt[100005] = { 0 };//cnt[1]=2，表示1出现两次
	int sum[100005] = { 0 };//前缀和sum[a]=b,表示小于等于a的数有b个
	int ans[105];//存放有序序列

	int maxx = a[1];//当前序列最大值和最小值
	int ind;
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
		if (maxx < a[i])maxx = a[i];
	}

	sum[1] = cnt[1];
	for (int i = 2; i <= maxx; i++)
		sum[i] = sum[i - 1] + cnt[i];

	for (int i = n; i >= 1; i--)
	{
		ind = sum[a[i]];
		ans[ind] = a[i];
		sum[a[i]]--;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;



	//不稳定
	//int cnt[100005] = { 0 };//cnt[1]=2，表示1出现两次
	//int minn = a[1];
	//int maxx = a[1];
	//for (int i = 1; i <= n; i++)
	//{
	//	cnt[a[i]]++;
	//	if (minn > a[i])minn = a[i];
	//	if (maxx < a[i])maxx = a[i];
	//}

	//for (int i = minn; i <= maxx; i++)
	//{
	//	for (int j = 0; j < cnt[i]; j++)
	//	{
	//		printf("%d ", i);
	//	}
	//}



}



