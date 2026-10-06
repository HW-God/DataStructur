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

	//Ö±½Ó²åÈëÅÅÐò
	int j, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i+1];
		for ( j = i; j >= 1; j--)
		{
			if (a[j] > x)
			{
				a[j + 1] = a[j];
			}
			else break;
		}
		a[j + 1] = x;
	}


	
	
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
