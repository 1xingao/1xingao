#include<stdio.h>
void swap(int* a, int* b);
void swap(int* a, int* b)//数据交换
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
   
}

int main()
{
    int i, j, k, t = 1, m[11];
    for (i = 0; i < 10; i++)//输入数组元素
        scanf("%d", (m + i));
    while (t)//无交换时排序完成
    {
        t = 0;
        for (i = 0; i < 9; i++)//冒泡
            if (*(m + i) > *(m + i + 1)) 
				{ t = 1;swap(m+i,m+i+1); }
    }
    for (i = 0; i < 10; i++)
		printf("%d ",*(m+i));
	return 0;
}