#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//定义左端指针指向真正数据，右端指针指向真正数据的下一个

typedef struct
{
	int* data;
	int r, l;
	int sum;

}Deque;

void Init(Deque *q)
{
	q->data = (int*)malloc(sizeof(int) * MAX);
	q->sum = 0;
	q->l = q->r = 0;
}

void LInsert(Deque *q,int k)
{
	if (q->sum == MAX)
	{
		printf("队满，无法插入！\n");
		return;
	}
	q-> l= (q->l - 1 + MAX) % MAX;
	q->data[q->l] = k;
	q->sum++;
}

void RInsert(Deque* q, int k)
{
	if (q->sum == MAX)
	{
		printf("队满，无法插入！\n");
		return;
	}
	q->data[q->r] = k;
	q->r = (q->r + 1) % MAX;
	q->sum++;
}

void LDelete(Deque* q)
{
	if (q->sum == 0)
	{
		printf("队空，无法删除\n");
		return;
	}
	printf("%d出队\n",q->data[q->l]);
	q->l = (q->l + 1) % MAX;
	q->sum--; 
}

void RDelete(Deque* q)
{
	if (q->sum == 0)
	{
		printf("队空，无法删除\n");
		return;
	}
	q->r = (q->r - 1 + MAX) % MAX;
	printf("%d出队\n", q->data[q->r]);
	q->sum--;
}

int main()
{
	Deque q;
	Init(&q);
	LInsert(&q, 1);
	LInsert(&q, 2);
	LInsert(&q, 3);
	RInsert(&q, 4);
	RInsert(&q, 5);
	RInsert(&q, 6);
	RInsert(&q, 7);
	RInsert(&q, 8);
	RInsert(&q, 9);
	RInsert(&q, 10);
	RInsert(&q, 11);

	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);

	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);

}