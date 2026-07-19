#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node
{
	int child;//孩子的下标
	struct Node* next;
}Node;

//定义结构体数组存 数据及其孩子链表
struct 
{
	char data;
	Node* chi;
}t[MAX];
int sum = 0;

void Init(char root)
{
	sum++;
	t[sum].data = root;
	t[sum].chi = NULL;
}

int Find(char fa)
{
	for (int i = 1; i <= sum; i++)
	{
		if (t[i].data == fa)
		{
			return i;
		}
	}
	return -1;
}

void Insert(char x, char fa)
{
	if (sum == MAX - 1)
	{
		printf("树满,无法插入\n");
		return;
	}
	sum++;
	t[sum].data = x;
	t[sum].chi = NULL;

	int i = Find(fa);
	//if（i==-1） .....

	Node* p = (Node*)malloc(sizeof(Node));
	p->child = sum;
	p->next = t[i].chi;
	t[i].chi = p;
}

int main()
{
	int n;//数据个数
	scanf("%d", &n);

	char root;
	scanf(" %c", &root);
	Init(root);
	n--;

	char x, fa;
	while (n--)
	{
		scanf(" %c %c", &x, &fa);
		Insert(x, fa);
	}
	
	//找temp的父亲和儿子
	char temp;
	scanf(" %c", &temp);
	
	int f = Find(temp);
	Node* p;
	p = t[f].chi;

	if (p==NULL)printf("该节点为叶子节点\n");
	else
	{
		printf("该节点的孩子有:");
		while (p != NULL)
		{
			printf("%c ", t[p->child].data);
			p = p->next;
		}
		printf("\n");
	}
	if (t[1].data == temp)printf("该节点为根节点\n");
	else 
	for (int i = 1; i <= sum; i++)
	{
		p = t[i].chi;
		while (p != NULL)
		{
			if (p->child == f)
			{
				printf(" %c的父亲是%c\n", temp, t[i].data);
				return 0;
			}
			p = p->next;
		}
	}

}