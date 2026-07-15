#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct
{
	int* data;
	int h, r;
}Queue;

void Init(Queue *q)
{
	q->data = (int*)malloc(sizeof(int) * MAX);
	q->h = 0;
	q->r = 0;
}

int  IsEmpty(Queue *q)
{
	if (q->h == q->r)return 1;
	else return 0;
}

void Push(Queue *q, int k)
{
	if (q->h == (q->r + 1) % MAX)
	{
		printf("队满，无法插入\n");
	}
	else
	{
		q->data[q->r] = k;
		q->r = (q->r + 1) % MAX;
	}
}

void Pop(Queue *q)
{
	if (IsEmpty(q))printf("出队失败\n");
	else
	{
		printf("%d出队\n", q->data[q->h]);
		q->h = (q->h + 1) % MAX;
	}
}

int main()
{
	Queue q;
	Init(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Pop(&q);
	Pop(&q);
	Pop(&q);
	Pop(&q);

}