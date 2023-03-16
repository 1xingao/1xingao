#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T,i,j,k;
	int *arr1;
	scanf("%d",&T);
	arr1=(int*)calloc(T,sizeof(int));
	for(i=0;i<T;i++)
	{
		scanf("%d",arr1[i]);
	}
	for(i=0;i<T;i++)
	{
		int *arr2;
		arr2=(int*)calloc(arr1[i],sizeof(int));
		for(j=0;j<arr1[i];j++)
		{
			printf("输入数据\n") ;
			scanf("%d",arr2[j]);
		}
		for(k=0;k<arr1[i];k++)
		{
			if(arr2[k]==k){
				printf("%d",k);
				break;
			}
			else printf("-1");
		}
		free(arr2);
	}
	free(arr1);
	return 0;
}
