#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Huffman
{
	int w;//权值
	int fi;//父亲节点下标
	int l, r;//左右孩子的下标
}HuffmanNode;

void Find(HuffmanNode* Tree,int x, int* s1, int* s2)
{
	int Min=1000000000;
	for (int i = 0; i <= x; i++)
	{
		if (Tree[i].fi == -1)
		{
			Min = i;
			break;
		}

	}
	for (int i = 0; i <= x; i++)
	{
		if (Tree[i].fi == -1 && Tree[i].w<Tree[Min].w)
		{
			Min = i;
		}

	}
	(*s1) = Min;
	//找第二小的数
	for (int i = 0; i <= x; i++)
	{
		if (Tree[i].fi == -1 && i != (*s1))
		{
			Min = i;
			break;
		}

	}
	for (int i = 0; i <= x; i++)
	{
		if (Tree[i].fi == -1 && Tree[i].w < Tree[Min].w && i != (*s1))
		{
			Min = i;
		}

	}
	(*s2) = Min;
}

Huffman* CreatHuffman(int n, int w[])
{
	int m = 2 * n - 1;
	HuffmanNode* Tree = (HuffmanNode*)malloc(sizeof(HuffmanNode) * m);
	for (int i = 0; i < n; i++)
	{
		Tree[i].w = w[i];
		Tree[i].fi = -1;
		Tree[i].r = -1;
		Tree[i].l = -1;
	}
	int s1, s2;//保存权值最小两个的下标
	for (int i = n; i < m; i++)
	{
		Find(Tree,i-1, &s1, &s2);
		Tree[i].w = Tree[s1].w + Tree[s2].w;
		Tree[i].fi = -1;
		Tree[i].l = s1;
		Tree[i].r = s2;
		Tree[s1].fi = Tree[s2].fi = i;
	}
	return Tree;
}

char** CreatCode(Huffman* Tree,int n)
{
	char* t = (char*)malloc(sizeof(char) * n);//临时存放单个编码
	char** code = (char**)malloc(sizeof(char*) * n);//二维指针模拟开二位数组，保存n个编码
	for (int i = 0; i < n; i++)
	{
		code[i] = NULL;
	}
	int start = 0;
	int p, pre;
	for (int i = 0; i < n; i++)
	{
		start = n - 1;
		t[start] = '\0';
		p = i;
		pre = Tree[i].fi;
		while (pre!=-1)
		{
			start--;
			if (Tree[pre].l == p)t[start] = '1';
			else t[start] = '0';
			p = pre;
			pre = Tree[p].fi;
		}
		code[i] = (char*)malloc(sizeof(char) * (n - start));
		strcpy(code[i], &t[start]);
	}
	return code;
}

int main()
{
	int n;//对n个字符进行编码，n<=100
	char a[105];//保存字符
	int w[105];//保存每个字符出现的次数
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)scanf("%c", &a[i]);
	for (int i = 0; i < n; i++)scanf("%d", &w[i]);

	HuffmanNode* Tree = CreatHuffman(n, w);
	char** code = CreatCode(Tree,n);
	for (int i = 0; i < n; i++)
	{
		printf("%c: %s\n", a[i], code[i]);
	}
}
/*
9
agmteh is
1 1 1 1 2 2 3 3 5
*/