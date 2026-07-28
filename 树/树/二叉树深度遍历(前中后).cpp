#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode
{
	char data;
	struct BTNode* right;
	struct BTNode* left;
}BTNode,*LinkTree;

void Init(LinkTree *root, char r)
{
	LinkTree p = (BTNode*)malloc(sizeof(BTNode));
	p->data = r;
	p->right = p->left = NULL;
	*root = p;
}

BTNode* Find(LinkTree root, char x)
{
	BTNode* ans = NULL;
	if (root->data == x)return root;
	if (root->left != NULL)
	{
		ans=Find(root->left, x);
		if (ans != nullptr)return ans;
	}

	if (root->right != NULL)
	{
		ans = Find(root->right, x);
		if (ans != NULL)return ans;
	}
	return ans;
}

void Insert(LinkTree root, char x, char fx, int flag)
{
	BTNode* p = Find(root, fx);
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->right = s->left = NULL;
	if (flag == 0)p->left = s;
	else p->right = s;
}


//==========================================================
//前中后序遍历
void PreOrder(BTNode* root)
{
	printf("%c ", root->data);
	if (root->left != nullptr)PreOrder(root->left);
	if (root->right!=nullptr)PreOrder(root->right);
}

void MidOrder(BTNode*root)
{
	if (root == NULL)return;
	if (root->left != nullptr)MidOrder(root->left);
	printf("%c ", root->data);
	if (root->right != nullptr)MidOrder(root->right);
}

void LasOrder(BTNode* root)
{
	if (root == NULL)return;
	if (root->left != NULL)LasOrder(root->left);
	if (root->right != NULL)LasOrder(root->right);
	printf("%c ", root->data);
}
//==========================================================
int main()
{
	LinkTree root=NULL;
	char r;
	int n;
	scanf("%d %c", &n, &r);
	Init(&root, r);
	n--;
	char x, fx;
	int flag;
	while (n--)
	{
		scanf(" %c %c %d", &x, &fx, &flag);
		Insert(root, x, fx, flag);
	}
	LasOrder(root);
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
