#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//==================================================
//Á´Õ»,¶þ²æÊ÷

typedef struct BTNode
{
	char data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode,*BTLink;


typedef struct Stack
{
	BTNode* node;
	struct Stack* next;
}Stack,*Linkstack;

void StackInit(Linkstack* s)
{
	Linkstack head = (Stack*)malloc(sizeof(Stack));
	head->next = NULL;
	head->node = NULL;
	*s = head;
}

void Push(Linkstack s, BTNode* p)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->node = p;
	temp->next = s->next;
	s->next = temp;
}

bool IsEmpty(Stack* s)
{
	if (s->next == NULL)return true;
	return false;
}

BTNode* Get(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("Õ»¿Õ£¬Õ»¶¥²»´æÔÚ");
		return NULL;
	}
	return s->next->node;
}

BTNode* Del(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("Õ»¿Õ£¬ÎÞ·¨É¾³ý");
		return NULL;
	}
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p = s->next->node;
	s->next = s->next->next;
	return p;
}


//============================================
void Init(BTLink* root, char r)
{
	BTLink head = (BTNode*)malloc(sizeof(BTNode));
	head->data = r;
	head->right = head->left = NULL;
	*root = head;
}

BTNode* Find(BTNode* root, char fx)
{
	if (root == NULL)
	{
		printf("Ê÷¿Õ");
		return 0;
	}
	
	BTNode* ans = NULL;
	if (root->data == fx)return root;

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


void Insert(BTLink root, char x, char fx, int flag)
{
	BTNode* p = Find(root, fx);
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->right = s->left = NULL;
	if (flag == 0)
	{
		p->left = s;
	}
	else p->right = s;
}

void Visit(BTNode* s)
{
	printf("%c ", s->data);
}

//ÏÈÐò±éÀú
void PreOrder(BTNode* root)
{
	Linkstack s;
	StackInit(&s);
	BTNode* p = root;
	BTNode* f = NULL;

	while (p!=NULL || !IsEmpty(s))
	{
		if (p != NULL)
		{
			Visit(p);
			Push(s, p);
			p = p->left;
		}
		else
		{
			f = Del(s);
			p = f->right;
			
		}
	}
}
//ÖÐÐò±éÀú
void MidOrder(BTNode* root)
{
	Linkstack s;
	StackInit(&s);
	BTNode* p = root;
	BTNode* f = NULL;

	while (p != NULL || !IsEmpty(s))
	{
		if (p != NULL)
		{
			Push(s, p);
			p = p->left;
		}
		else
		{
			f = Del(s);
			Visit(f);
			p = f->right;
		}
	}
}

//ºóÐò±éÀú
void LasOrder(BTNode* root)
{
	Linkstack s;
	StackInit(&s);
	BTNode* p = root;
	BTNode* pre = NULL;
	BTNode* f = NULL;
	while (p != NULL || !IsEmpty(s))
	{
		if (p != NULL)
		{
			Push(s, p);
			p = p->left;
		}
		else
		{
			f = Get(s);
			if (f->right != NULL && f->right != pre)
			{
				p = f->right;
			}
			else
			{
				f = Del(s);
				Visit(f);
				pre = f;
			}
		}
	}
}

int main()
{
	BTLink root;
	int n;
	char r;
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