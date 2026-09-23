#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//队列（采用头插尾出，）
typedef struct Node
{
	int data;//存储数据的下标
	struct Node* next;
}Node,*LinkNode;

typedef struct Queue
{
	Node* f;
	Node* r;
}Queue;

Queue* Init(Queue* q)
{
	q = (Queue*)malloc(sizeof(Queue));
	LinkNode s = (Node*)malloc(sizeof(Node));
	s->next = NULL;
	q->f = q->r = s;
	return q;
}

Queue* Push(Queue* q, int x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = x;
	if (q->f->next == NULL)//如果插入时队列为空，让尾节点指向最后一个
	{
		q->r = s;
	}

	s->next = q->f->next;
	q->f->next = s;
	return q;
}

int Pop(Queue* q)
{
	if (q->r == q->f)
	{
		printf("队列为空无法删除\n");
		return -1;
	}
	//printf("%d出队\n", q->r->data);

	Node* p = q->f;
	int num;
	while (p->next != q->r)
	{
		p = p->next;
	}
	q->r = p;//改变尾节点指向

	p = p->next;//删除原来尾节点
	num = p->data;
	free(p);
	p = NULL;
	if (q->r == q->f)q->f->next = NULL;
	return num;
}

int IsEmpty(Queue*q)
{
	if (q->r == q->f)return 1;
	else return 0;
}

//==============================================
//图的邻接点存储
//n（<100）个点 m条边的无权无向图 n个点的数据是字母
//BFS时间复杂度:邻接表存图O(n+m). 邻矩阵存图O(n^2)
typedef struct ENode
{
	int data;
	struct ENode* next;
}ENode;

struct Graph
{
	char data;
	ENode* first;
}g[105];
int mark[105] = { 0 };//标记已经输出过的节点

int Find(int n, char x)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (g[i].data == x)break;
	}
	return i;
}

void BFS(int i)
{
	Queue* q = NULL;
	q=Init(q);
	q = Push(q, i);
	mark[i] = 1;
	while (IsEmpty(q)==0)
	{
		int temp;

		int top = Pop(q);//队首出队为top
		printf("%c ", g[top].data);

		ENode* s = g[top].first;
		while (s != NULL)
		{
			temp = s->data;
			if (mark[temp] == 0)
			{
				mark[temp] = 1;
				q = Push(q, temp);
			}
			s = s->next;
		}
	}


}



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	char x, y;
	int xi, yi;

	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &g[i].data);
		g[i].first = NULL;
	}

	for (int i = 0; i < m; i++)
	{
		scanf(" %c %c", &x, &y);
		xi = Find(n, x);
		yi = Find(n, y);
		ENode* s1 = (ENode*)malloc(sizeof(ENode));
		s1->data = xi;
		s1->next = g[yi].first;
		g[yi].first = s1;

		ENode* s2 = (ENode*)malloc(sizeof(ENode));
		s2->data = yi;
		s2->next = g[xi].first;
		g[xi].first = s2;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (mark[i] == 0)BFS(i);
	}

}
/*
9 16
ABCDEFGHI
A B
A F
B G
G F
B C
B I
C I
C D
I D
D G
D H
D E
G H
H E
E F
F G
*/