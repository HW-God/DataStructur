#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
char data[MAX] = {" "};
int flag= 0;//flag=0表示左节点，1为右节点

//所有数据均保证可以找到父亲
int Find(char fx)
{
	for (int i = 1; i < MAX; i++)
	{
		if (data[i] == fx)return i;
	}
}

int main()
{
	int n;
	char root;
	scanf("%d %c", &n, &root);
	n--;
	data[1] = root;

	char x, fx;
	while (n--)
	{
		scanf(" %c %c %d", &x, &fx, &flag);
		int i=Find(fx);
		if (flag == 0)data[2 * i] = x;
		else data[2 * i + 1] = x;
	}

	scanf(" %c", &x);
	int i = Find(x);
	printf("%c的父亲为%c\n",x,data[i/2]);
	printf("%c的左孩子为%c\n",x,data[2*i]);
	printf("%c的右孩子为%c\n",x,data[2*i+1]);
}

/*
7
a
b a 0
c a 1
d b 0
e b 1
f e 0
g e 1
*/