#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	Node* next;
}Node;

typedef struct Deque
{
	Node* head;
	Node* rear;
}Deque;

void Init(Deque *q)
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	q->head = L;
	q->rear = L;
}

void Push(Deque *q, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}

void Pop(Deque* q)
{
	if (q->head == q->rear)
	{
		printf("队空，出队失败\n");
		return;

	}
	if (q->head->next == q->rear)
	{
		q->rear = q->head;

	}
	Node* s = q->head->next;
	printf("%d出队\n", s->data);

	q->head->next = s->next;
		free(s);
		s = NULL;
}



int main()
{
	Deque q;
	Init(&q);
	Pop(&q);

	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Pop(&q);
	Pop(&q);
	Pop(&q);
	Pop(&q);


}