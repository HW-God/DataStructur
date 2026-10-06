#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//链栈
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LinkStack;

Node* Init()
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->next = NULL;
	return s;
}

Node* Push(Node* st, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = st->next;
	st->next = s;
	return st;
}

Node* Pop(Node* st)
{
	Node* p = st->next;
	if (p == NULL)
	{
		printf("栈空\n");
	}
	else
	{
		st->next = p->next;
	}
	free(p);
	p = NULL;
	return st;
}

int IsEmpty(Node* st)
{
	if (st->next == NULL)return 1;
	else return 0;
}

int GetTop(Node* st)
{
	if (IsEmpty(st))
	{
		printf("栈空\n");
		return -1;
	}
	else
	{
		return st->next->data;
	}
}

//////////////图/////////////////
//含有n个点m条边的AOE网  n<100 边权小于10000
typedef struct ENode
{
	int data;
	int w;
	struct ENode* next;
}ENode;

struct
{
	char data;
	ENode* first;
}g[105];
int ind[105];
int Topo[105];
int etv[105];
int ltv[105];
int k = 0;
int n, m;


int Find(char x)
{
	int i = 1;
	for (; i <= n; i++)
	{
		if (g[i].data == x)break;
	}
	return i;
}

int maxx(int a, int b) { return a > b ? a : b; }
int minn(int a, int b) { return a < b ? a : b; }


void TopoSort()
{
	LinkStack st = Init();
	int t;//取栈顶元素
	ENode* p = NULL;//遍历邻接点

	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)Push(st, i);
	}

	while (!IsEmpty(st))
	{
		t = GetTop(st);
		Pop(st);
		Topo[++k] = t;
		p = g[t].first;
		while (p != NULL)
		{
			ind[p->data]--;
			if(ind[p->data]==0)Push(st, p->data);
			
			p = p->next;
		}
	}
}

void CriticalPath()
{
	int t;//取topo元素
	ENode* p = NULL;//遍历邻接点

	//每个事件的最早发生时间
	for (int i = 1; i <= n; i++)
	{
		etv[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		t = Topo[i];
		p = g[t].first;
		while (p != NULL)
		{
			int data = p->data;
			etv[data] = maxx(etv[data], etv[t] + p->w);
			p = p->next;
		}
	}
	//每个事件的最晚发生时间
	for (int i = n; i >= 1; i--)
	{
		ltv[i] = etv[n];
	}
	for (int i = n; i >= 1; i--)
	{
		t = Topo[i];
		p = g[t].first;
		while (p != NULL)
		{
			int data = p->data;
			ltv[t] = minn(ltv[t], ltv[data] - p->w);
			p = p->next;
		}
	}


	//枚举所有的活动----》所有的边
	int j;
	printf("所有的关键活动为：\n");
	int ete, lte;
	for (int i = 1; i <= n; i++)//枚举所有的点
	{
		p = g[i].first;
		while (p != NULL)//遍历i点的出边--->也就是遍历i的出边链表
		{
			//p指向的结点对应i的一条出边:i--------》j
			j = p->data;
			ete = etv[i];//活动的最早开始时间等于起点i的最早发生时间
			lte = ltv[j] - (p->w);//活动的最w晚开始时间等于终点j的最晚发生时间-边权
			if (ete == lte)
			{
				printf("%c-->%c\n", g[i].data, g[j].data);
			}
			p = p->next;
		}

	}
}

int main()
{
	scanf("%d %d", &n, &m);
	char x, y;
	int rx, ry, w;

	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &g[i].data);
		g[i].first = NULL;
	}

	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		rx = Find(x);
		ry = Find(y);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->w = w;
		s->data = ry;
		s->next = g[rx].first;
		g[rx].first = s;
		ind[ry]++;
	}
	TopoSort();
	CriticalPath();

}

/*
9 11
ABCDEFGHY
A B 6
A C 4
A D 5
B E 1
C E 1
D F 2
E G 9
E H 7
F H 4
G Y 2
H Y 4
*/
