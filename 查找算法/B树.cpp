#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define m 4//B树的阶
typedef struct Node
{
	int data[m + 1];
	struct Node* ch[m+1];
	struct Node* fa;
	int num;
}BNode,*BTree;

typedef struct r
{
	BNode* z;//k应该插入的位置的节点的地址
	int i;//该节点下的第i个位置为应该插入的位置
	int mark;//标记是否找到了点k,1 找到了
}Result;

Result Search(BTree root, int k)
{
	Result r;
	BNode* p = root;
	BNode* pre = NULL;
	int i = 1;
	while (p!=NULL)
	{
		for (i = 1; i <= p->num; i++)
		{
			if (k <= p->data[i])
			{
				if (k == p->data[i])
				{
					r.mark = 1;
					r.i = i;
					r.z = p;
					return r;
				}
				break;
			}
		}
		pre = p;
		p = p->ch[i - 1];
	}
	if (p == NULL)
	{
		r.z = pre;
		r.i = i;
		r.mark = 0;
	}
	return r;
}

void CreateRoot(BTree& root,int k, BTree p, BTree ap)
{
	BNode*s = (BNode*)malloc(sizeof(BNode));
	s->num = 1;
	s->data[s->num] = k;
	s->ch[s->num - 1] = p;
	s->ch[s->num ] = ap;
	if (p != NULL)p->fa = s;
	if (ap != NULL)ap->fa = s;
	s->fa = NULL;
	root = s;
}

void InsertBNode(int k, int i, BNode* z,BNode*&ap)
{
	for (int j = z->num; j >= i; j--)
	{
		z->data[j + 1] = z->data[j];
		z->ch[j + 1] = z->ch[j];
	}
	z->data[i] = k;
	z->ch[i] = ap;
	z->num++;
	if (ap != NULL)ap->fa = z;
}

void Split(BNode*z,int s,BNode*&ap)
{
	ap->ch[0] = z->ch[s];
	if (ap->ch[0] != NULL)ap->ch[0]->fa = ap;
	for (int i = s+1; i <= z->num; i++)
	{
		ap->data[i - s] = z->data[i];
		ap->ch[i - s] = z->ch[i];
		if (z->ch[i] != NULL)z->ch[i]->fa = ap;
	}
	ap->num = z->num - s;
	z->num = s - 1;
}

void InsertKey(BTree& root,int k,int i,BNode*z)
{
	if (root == NULL)
	{
		CreateRoot(root, k, NULL, NULL);
		return ;
	}
	BNode* ap = NULL;
	int s = 0;//分裂位置
	while (1)
	{
		InsertBNode(k,i,z,ap);
		if (z->num <= m-1)
		{
			break;
		}
		else
		{
			s = (m + 1) / 2;
			ap = (BNode*)malloc(sizeof(BNode));
			Split(z,s,ap);
			int up = z->data[s];
			BNode* p = z;
			if (z->fa != NULL)
			{
				z = z->fa;
				int pos = 1;
				while (z->ch[pos - 1] != p)pos++;
				k = up;
				i = pos;
			}
			else
			{
				CreateRoot(root, up, p, ap);
				break;
			}
		}
	}

}

void PrintfBTree(BTree root,int tab)
{
	if (root == NULL)return;
	int i = 0;
	for (i = 1; i <= tab; i++)
	{
		printf("	");
	}
	//输出根结点中的数据
	for (i = 1; i <= root->num; i++)
	{
		printf("%d ", root->data[i]);
	}
	printf("\n");
	//打印根结点的每棵子树
	for (i = 0; i <= root->num; i++)
	{
		PrintfBTree(root->ch[i], tab + 1);
	}
}

void InsertKeyOperation(BTree &root)
{
	int k;
	while (1)
	{
		printf("请给出插入的数据：\n");
		scanf("%d", &k);
		Result r=Search(root, k);
		if (r.mark == 1)printf(" 该数据已经存在/n");
		else
		{
			InsertKey(root,k,r.i,r.z);
			printf("插入成功，B树如下:\n");
			printf("--------------------------------------------------\n");

			PrintfBTree(root, 1);

			printf("--------------------------------------------------\n");
		}
	}
}


int main()
{
	BTree root=NULL;
	InsertKeyOperation(root);
}