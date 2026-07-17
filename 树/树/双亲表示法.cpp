#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct Node
{
	char data;
	int fa;
}t[MAX];

int sum = 0;

void Init(char head)
{
	sum++;
	t[sum].data = head;
	t[sum].fa = -1;
}

//默认所有给的数据均能被找到
int Find(char c)
{
	for (int i = 1; i <= sum; i++)
	{
		if (t[i].data == c)return i;
	}
}

//通过Find函数找到所存储的父亲节点的位置而不是直接存父亲的
void Insert(char data, char fa)
{
	if (sum == MAX - 1)
	{
		printf("树满，无法插入!\n");
		return;
	}
	sum++;
	int i = Find(fa);

	t[sum].data = data;
	t[sum].fa = i;
}


int main()
{
	int n;
	scanf("%d",&n);

	char head;
	scanf(" %c",&head);
	Init(head);
	n--;

	char data,fa;
	while (n--)
	{
		scanf(" %c %c", &data, &fa);
		Insert(data, fa);
	}


	char temp;
	scanf(" %c", &temp);

	if ((t[Find(temp)].fa) == -1)printf("该节点为根节点\n");
	else 
		printf("%c的父亲是%c\n", temp, t[t[Find(temp)].fa].data);

	for (int i = 1; i <= sum; i++)
	{
		if (t[i].fa == Find(temp))
		{
			printf("%c的儿子是%c\n",temp,t[i].data);
		}
	}
}

/*
13
A
B A
C A
D A
E B
F B
G C
H D
I D
J D
K E
L E
M H
*/
