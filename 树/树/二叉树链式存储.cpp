#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
	struct Node* fa;
}Node,*BTNode;

void Init(BTNode *root,char r)
{
	BTNode head = (Node*)malloc(sizeof(Node));
	head->data = r;
	head->right = head->left = head->fa = NULL;
	*root = head;
}

Node* Find(BTNode root,char fx)
{
	if (root->data == fx)return root;

	Node* ans = NULL;
	if (root->left != NULL)
	{
		ans = Find(root->left, fx);
		if (ans != NULL)return ans;
	}
	if (root->right != NULL)
	{
		ans = Find(root->right, fx);
		if (ans != NULL)return ans;
	}
	return ans;
}

//flag=0表示左节点，1为右节点
void Insert(BTNode root,char x, char fx, int flag)
{
	Node* p = Find(root,fx);

	Node* s=(Node*)malloc(sizeof(Node));
	s->data = x;
	s->left = s->right = NULL;
	s->fa = p;

	if (flag == 0)p->left = s;
	else p->right = s;
	
}


int main()
{
	BTNode root=NULL;
	int n;
	char r;
	scanf(" %d %c", &n, &r);
	Init(&root,r);
	n--;
	
	char x, fx;
	int flag = 0;
	while (n--)
	{
		scanf(" %c %c %d", &x, &fx, &flag);
		Insert(root,x, fx, flag);
	}


	scanf(" %c", &x);
	Node* p = Find(root,x);
	printf("%c的父亲是%c\n", x, p->fa->data);

	printf("%c的左孩子是%c\n", x, p->left->data);
	printf("%c的右孩子是%c\n", x, p->right->data);
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