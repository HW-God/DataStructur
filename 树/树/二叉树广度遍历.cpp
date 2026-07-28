#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* next;
}Node,*LinkNode;

struct Queue
{
	Node* head;
	Node* tail;
};

typedef struct BTNode
{
	char data;
	struct BTNode* left;
	struct BTNode* right;
}NodeTree, * RootTree;


void Init(Queue*q)
{
	LinkNode head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	q->head = head;
	q->tail = head;
}

void Insert(Queue* q,NodeTree *root)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = root->data;
	s->next = nullptr;
	q->tail->next = s;
	q->tail = s;
}

bool IsEmpty(Queue* q)
{
	if (q->head == q->tail)return true;
	return false;
}


char Del(Queue* q)
{
	char x;
	if (IsEmpty(q))
	{
		printf("¶Ó¿Õ£¡\n");
		return ' ';
	}
	Node* s = q->head->next;
	x = s->data;
	if (q->head->next==q->tail)
	{
		q->tail = q->head;
	}
	q->head->next = s->next;
	free(s);
	s = NULL;
	return x;
}

//===========================================
//¶þ²æÊ÷Á´Ê½´æ´¢


void BTInit(RootTree* root ,char r)
{
	RootTree head = (NodeTree*)malloc(sizeof(NodeTree));
	head->data = r;
	head->left = head->right = NULL;
	*root = head;
}

NodeTree* BTFind(NodeTree* root, char fx)
{
	if (root->data == fx)return root;
	NodeTree* ans = NULL;
	if(root->left!=NULL)
	{
		ans = BTFind(root->left, fx);
		if (ans != NULL)return ans;
	}
	if(root->right!=NULL)
	{
		ans = BTFind(root->right, fx);
		if (ans != NULL)return ans;
	}
	return ans;
}

void BTInsert(NodeTree* root, char x, char fx, int flag)
{
	NodeTree* p = BTFind(root, fx);
	NodeTree* s = (NodeTree*)malloc(sizeof(NodeTree));
	s->data = x;
	s->left = s->right = NULL;
	if (flag == 0)p->left=s;
	else p->right=s;
}

void LevelOrder(RootTree root)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	Init(q);
	Insert(q, root);

	char p;
	NodeTree* s = NULL;
	while (!IsEmpty(q))
	{
		p = Del(q);
		if (p == NULL)continue;
		printf("%c ", p);
		s = BTFind(root, p);
		if (s->left != NULL)Insert(q, s->left);
		if (s->right != NULL)Insert(q, s->right);
	}
}


int main()
{
	RootTree root=NULL;
	char r;
	int n;
	scanf("%d", &n);
	n--;

	scanf(" %c", &r);
	BTInit(&root,r);

	char x, fx;
	int flag;
	while (n--)
	{
		scanf(" %c %c %d", &x, &fx,&flag);
		BTInsert(root, x, fx, flag);
	}

	LevelOrder(root);
}
/*
9
A
B A 0
E A 1
C B 1
F E 1
D C 0
G F 0
H G 0
K G 1
*/