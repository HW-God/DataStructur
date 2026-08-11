#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
	char data;
	int Lflag;
	int Rflag;
	struct BTNode* left;
	struct BTNode* right;
}BTNode, * BTLink;

typedef struct Stack
{
	BTNode* node;
	struct Stack* next;
}Stack, * Linkstack;

BTNode* pre = NULL;

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
		printf("栈空，栈顶不存在");
		return NULL;
	}
	return s->next->node;
}

BTNode* Del(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("栈空，无法删除");
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
	head->Lflag = head->Rflag = 0;
	*root = head;
}

BTNode* Find(BTNode* root, char fx)
{
	if (root == NULL)
	{
		printf("树空");
		return 0;
	}

	BTNode* ans = NULL;
	if (root->data == fx)return root;

	if (root->left != NULL && root->Lflag==0)
	{
		ans = Find(root->left, fx);
		if (ans != NULL)return ans;
	}

	if (root->right != NULL && root->Rflag==0)
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
	s->Lflag = s->Rflag = 0;
	if (flag == 0)
	{
		p->left = s;
	}
	else p->right = s;

}

void Visit(BTNode* p)
{
	if (p->left == NULL)
	{
		p->left = pre;
		p->Lflag = 1;
	}
	if (pre!=NULL && pre->right == NULL)
	{
		pre->right = p;
		pre->Rflag = 1;
	}
	pre = p;
	
}

void PreOrder(BTNode* root)
{
	printf("%c ", root->data);
	if (root->left != nullptr)PreOrder(root->left);
	if (root->right != nullptr)PreOrder(root->right);
}

void MidOrder(BTLink root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->Lflag != 1)
	{
		MidOrder(root->left);
	}
	
	Visit(root);
	
	if (root->Rflag != 1)
	{
		MidOrder(root->right);
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
	MidOrder(root);

	getchar();
	scanf(" %c", &x);
	//找x的中序遍历的前驱和后继
	BTNode* p = Find(root, x);//先找到x所在的结点
	//先找前驱
	if (p->left == NULL)printf("没前驱\n");
	else
	{
		if (p->Lflag == 1)printf("前驱是%c\n", p->left->data);
		else
		{//如果p有左孩子 那么其前驱 一定是左子树中最靠右的结点
			BTNode* q = p->left;//先指向左孩子
			while (q->right != NULL && q->Rflag == 0)
			{
				q = q->right;
			}
			//此时q就是p的前驱
			printf("前驱是%c\n", q->data);
		}
	}
	//找后继
	if (p->right == NULL)printf("没后继\n");
	else
	{
		if (p->Rflag == 1)printf("后继是%c\n", p->right->data);
		else
		{
			//如果p有右孩子 那么其后继 一定是右子树中最靠左的结点
			BTNode* q = p->right;//先指向右孩子
			while (q->left != NULL && q->Lflag == 0)
			{
				q = q->left;
			}
			//此时q就是p的后继
			printf("后继是%c\n", q->data);
		}
	}

}


/*
9
A
B A 0
E A 1
C B 1
D C 0
F E 1
G F 0
H G 0
K G 1
*/