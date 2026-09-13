#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
	int data;
	struct BSTNode* l;
	struct BSTNode* r;
}BSTNode,*BSTree;

void Init(BSTree *root, int r)
{
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	s->data = r;
	s->l = s->r = NULL;
	*root = s;
}

void Insert(BSTree root ,int x)
{
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	s->data = x;
	s->l = s->r = NULL;
	BSTNode* p = root;
	BSTNode* pre= NULL;
	while (p != NULL)
	{
		if (x > p->data)
		{
			pre = p;
			p = p->r;
		}
		else
		{
			pre = p;
			p = p->l;
		}
	}
	if (x > pre->data)
	{
		pre->r = s;
	}
	else
	{
		pre->l = s;
	}
}

BSTNode* Insert1(BSTree root, int x)
{
	if (root == NULL )
	{
		BSTNode* p = (BSTNode*)malloc(sizeof(BSTNode));
		p->data = x;
		p->l = p->r = NULL;
		return p;
	}

	if (x > root->data)
	{
		root->r = Insert1(root->r, x);
	}
	else 
	{
		root->l = Insert1(root->l, x);
	}
	return root;
}


void MidOrder(BSTNode* root)
{
	if (root->l != NULL)MidOrder(root->l);
	printf("%d ", root->data);
	if (root->r != NULL)MidOrder(root->r);
}

BSTNode* Find(BSTNode* root, int x)
{
	BSTNode* p = root;
	while (p != NULL && p->data!=x)
	{
		if (x > p->data)
		{
			p = p->r;
		}
		else
		{
			p = p->l;
		}
	}
	return p;
}

BSTNode* Find1(BSTNode* root, int x)
{
	if (root==NULL || root->data==x)return root;
	else if (x > root->data)
	{
		return Find1(root->r, x);
	}
	else if(x<root->data)
	{
		return Find1(root->l, x);
	}
}
	
BSTNode* Del(BSTNode* root, int x)
{
	if (root == NULL)
	{
		printf("树空\n");
		return NULL;
	}
	
	BSTNode* p = root;
	BSTNode* pre = NULL;
	while (p!=NULL && p->data != x)
	{
		if (x > p->data)
		{
			pre = p;
			p = p->r;
		}
		else
		{
			pre = p;
			p = p->l;
		}
	}

	if (p == NULL)return root;

	if (p->l != NULL && p->r != NULL)
	{
		BSTNode* q =p->l;
		BSTNode* qf = p;
		while (q->r != NULL)
		{
			qf = q;
			q = q->r;
		}
		p->data = q->data;

		pre = qf; p = q;
		qf = q = NULL;
	}
	//将度为二的节点删除转化为删除度为0/1的节点了
	BSTNode* kid = NULL;
	if (p->l != NULL)kid = p->l;
	else kid = p->r;

	if (pre == NULL)
	{
		root = kid;
	}
	else
	{
		if (pre->l == p)pre->l = kid;
		else pre->r = kid;
	}
	free(p);
	p = NULL;
	return root;
	
}

BSTNode* Del1(BSTNode* root, int x)
{

	if (root == NULL)
	{
		printf("该数不存在，无法删除\n");
	}
	
	else if (root->data == x)
	{
		BSTNode* pre = NULL;
		BSTNode* p = root;

		if (p->l != NULL && p->r != NULL)
		{
			BSTNode* qf = p;
			BSTNode* q = p->l;
			while (q->r != NULL)
			{
				qf = q;
				q = q->r;
			}
			p->data = q->data;
			pre = qf;
			p = q;
		}
		//将度为二的节点删除转化为删除度为0/1的节点了
		BSTNode* kid = NULL;
		if (p->l != NULL)kid = p->l;
		else kid = p->r;

		if (pre == NULL)
		{
			root = kid;
		}
		else
		{
			if (pre->l == p)pre->l = kid;
			else pre->r = kid;
		}
		free(p);
		p = NULL;
		return root;
	}

	else if (x > root->data)
	{
		root->r = Del1(root->r, x);
	}
	else if (x < root->data)
	{
		root->l = Del1(root->l,x);
	}
	return root;
}


int main()
{
	BSTree root;
	int n,r;
	scanf("%d %d", &n, &r);
	n--;
	Init(&root, r);
	int x;
	while (n--)
	{
		scanf("%d", &x);
		Insert1(root, x);
	}
	MidOrder(root);
	//scanf("%d", &x);
	//BSTNode* p = Find1(root, x);
	//printf("\n");
	//if (p == NULL)printf("%d 不存在", x);
	//else printf("%d 存在", x);

	while (1)
	{
		scanf("%d", &x);
		root=Del1(root, x);
		MidOrder(root);
		printf("\n");
	}

}
/*
9
8 3 10 1 6 14 4 7 13
*/