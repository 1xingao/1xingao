#include<stdio.h>
int f(int p);

int f(int p)
{
	int i,j,n,count=0,m=p;
	
	for(i=0;i<3;i++){
		n=p%10;
		switch(n)
		{
			case 2:
			case 3:
			case 5:
			case 7:count++;
		}
		p/=10;
	}
	if((m>=100&&count==3)||(m<100&&count==2)||(m<10&&count==1))
		return 1;
	else
		return 0;
	
}

int main()
{
	int n,sum=0,i;
	scanf("%d",&n);
	if(n<10||n>500)
		printf("-1");
	else
		for(i=1;i<=n;i++){
			if(f(i)){
				sum+=i;
			}
		}

	printf("%d",sum);
	return 0;

}

