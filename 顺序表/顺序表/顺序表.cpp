#include<stdio.h>
#include<stdlib.h>
#define MAX 25
typedef struct ArrayList
{
	int* data;
	int len;
}Array;

void InitArray(Array *a)
{
	a->data = (int*)malloc(sizeof(int)*MAX);
	if (a->data == NULL)
	{
		printf("空间申请失败");
		return;
	}
	a->len = 0;
}

//增
void AddArray(Array* a, int num)
{
	if (a->len == MAX)
	{
		printf("添加失败，表已满！");
		return;
	}
	a->data[a->len] = num;
	a->len++;
}
void InsertArray(Array* a, int i, int num)
{
	if (a->len == MAX)
	{
		printf("添加失败，表已满！\n");
		return;
	}

	if (i > a->len)
	{
		printf("插入失败，请重新插入！\n");
	}

	for (int j = a->len-1; j >= i; j--)
	{
		a->data[j + 1] = a->data[j];
	}
	a->data[i] = num;
	a->len++;
}

//查
int SearchArray(Array *a,int num)
{
	for (int i = 0; i < a->len; i++)
	{
		if (a->data[i] == num)return i;
	}
	printf("无法查找，该数不存在！\n");
	return -1;
}
//删
void DeleteArray(Array* a, int num)
{
	int mark;
	mark = SearchArray(a, num);
	if (mark == -1)
	{
		printf("无法删除，该数不存在!\n");
		return;
	}

	for (int i = mark; i < a->len-1; i++)
	{
		a->data[i] = a->data[i + 1];
	}
	a->len--;
}


//改
void ModifyArray(Array* a, int i, int num)
{
	if (i >= a->len)
	{
		printf("修改失败，请重新修改！\n");
	}
	a->data[i] = num;
}

//展示
void ShowArray(Array *a)
{
	for (int i = 0; i < a->len; i++)
		printf("%d ", a->data[i]);
	printf("\n");
}

int main()
{
	Array a;
	InitArray(&a);
	AddArray(&a, 1);
	AddArray(&a, 3);
	AddArray(&a, 5);
	ShowArray(&a);
	InsertArray(&a, 1, 9);
	ShowArray(&a);
	DeleteArray(&a,1);
	ShowArray(&a);
	int i = SearchArray(&a, 5);
	printf("%d\n", i);
	ModifyArray(&a, 1, 8);
	ShowArray(&a);

}