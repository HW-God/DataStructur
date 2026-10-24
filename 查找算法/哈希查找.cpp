#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define size 15
#define nul -1//因为数据保证都是非负整数，选取-1代表空
//有n个数据 构造长度为m的哈希表，保证n<m,保证数据都是非负整数
//H(key)=key%13
//解决冲突的方法：线性探测法
typedef struct
{
	int* data;//表中的数据
	int m;//表长
}HashTable;

HashTable CreatHash()
{
	HashTable s;
	s.data = (int*)malloc(sizeof(int) * size);
	s.m = size;
	for (int i = 0; i < s.m; i++)s.data[i] = nul;
	return s;
}

int Hash(int k)
{
	return k % 13;
}

int Find(int k,HashTable*H)//按照哈希函数找到k在函数中的位置
{
	int i = Hash(k);
	int newi = i, d = 0;
	while (H->data[newi] != nul)
	{
			d++;
			newi = (i + d)%H->m;
	}
	return newi;
}

void Insert(int k,HashTable *H)
{
	int ind = Find(k,H);
	H->data[ind] = k;
}

void Search(int k,HashTable H)
{
	int i = Hash(k);
	int newi=i,d=0;
	while (H.data[newi]!=nul)
	{
		if (H.data[newi] == k)
		{
			printf("%d的下标为%d\n", k, newi);
			return;
		}
		else
		{
			d++;
			newi = (i + d)%H.m;
		}
	}
	printf("该数不存在\n");
}

int main()
{
	int n,k;
	scanf("%d", &n);
	HashTable H = CreatHash();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		Insert(k, &H);
	}

	scanf("%d", &k);
	Search(k, H);

}

/*
12
19 14 23 1 68 20 84 27 55 11 10 79
0
*/
//i  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14
//     14  1 68 27 55 19 20 84 79  23  11  10  
