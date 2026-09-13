#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct AVLNode
{
	int data;
	struct AVLNode* l;
	struct AVLNode* r;
	int h;
}AVLNode,*AVLTree;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int GetH(AVLNode* x)
{
	if (x == NULL)return 0;
	else return x->h;
}

AVLTree Right(AVLNode* x)
{
//指针y指向x的左孩子
	AVLNode* y = x->l;
	x->l = y->r;
	y->r = x;
	x->h = Max(GetH(x->l), GetH(x->r)) + 1;
	y->h = Max(GetH(y->l), GetH(y->r)) + 1;
	return y;
}

AVLTree Left(AVLNode* x)
{
	//指针y指向x的左孩子
	AVLNode* y = x->r;
	x->r = y->l;
	y->l = x;
	x->h = Max(GetH(x->l), GetH(x->r)) + 1;
	y->h = Max(GetH(y->l), GetH(y->r)) + 1;
	return y;
}

AVLTree CreatNode(int k)
{
	AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
	s->data = k;
	s->r = s->l = NULL;
	s->h = 1;
	return s;
}

AVLTree Insert(int k, AVLNode* root)
{
	//所有数据不会重复
	if (root == NULL)
	{
		root = CreatNode(k);
		return root;
	}
	if (root->data > k)
	{
		root->l=Insert(k, root->l);
		if (GetH(root->l) - GetH(root->r) >= 2)
		{
			AVLNode* le = root->l;
			if(k<le->data)
			root = Right(root);
			else
			{
				root->l = Left(root->l);
				root = Right(root);
			}
		}
	}
	else
	{
		root->r = Insert(k, root->r);
		if (GetH(root->r) - GetH(root->l) >= 2)
		{
			AVLNode* ri = root->r;
			if (k > ri->data)
			{
				root = Left(root);
			}
			else
			{
				root->r = Right(root->r);
				root = Left(root);

			}
		}
	}

	root->h = Max(GetH(root->l), GetH(root->r)) + 1;
	return root;
}

AVLNode* Del(AVLTree root, int k)
{
	if (root == NULL)
	{
		printf("该数据不存在，无法删除\n");
		return root;
	}
	if (root->data == k)
	{
		if (root->l != NULL && root->r != NULL)
		{
			AVLNode* p = root->r;
			while (p->l != NULL)
			{
				p = p->l;
			}
			root->data = p->data;
			root->r= Del(root->r, p->data);
			if (GetH(root->l) - GetH(root->r) >= 2)
			{
				AVLNode* le = root->l;
				if(GetH(le->l)>GetH(le->r))
					root = Right(root);
				else
				{
					root->l = Left(root->l);
					root = Right(root);
				}
			}

		}
		else
		{
			AVLNode* p = root;
			if (root->l != NULL)root = root->l;
			else root = root->r;
			free(p);
			return root;
		}
	}
	else if (k > root->data)
	{
		root->r=Del(root->r, k);
		if (GetH(root->l) - GetH(root->r) >= 2)
		{
			AVLNode* le = root->l;
			if (GetH(le->l) > GetH(le->r))
				root = Right(root);
			else
			{
				root->l = Left(root->l);
				root = Right(root);
			}
		}
	}
	else
	{
		root->l=Del(root->l, k);
		if (GetH(root->r) - GetH(root->l) >= 2)
		{
			AVLNode* ri = root->r;
			if (GetH(ri->r)>GetH(ri->l))
			{
				root = Left(root);
			}
			else
			{
				root->r = Right(root->r);
				root = Left(root);

			}
		}
	}

	if(root!=NULL)root->h = Max(GetH(root->l), GetH(root->r)) + 1;
	return root;
}


void InOrder(AVLNode* root)
{
	if (root == NULL)return;
	InOrder(root->l);
	printf("%d  %d\n", root->data, GetH(root->r)-GetH(root->l));
	InOrder(root->r);
}

int main()
{
	AVLTree root=NULL;
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		root=Insert(k, root);
	}
	InOrder(root);
	while (scanf("%d", &k))
	{

		root=Del(root, k);
		InOrder(root);
		printf("\n");
	}
}