#include<stdio.h>
#include<math.h>
int main(void)
{
    int m,i,n=0;
    double k;
    for(m=20;m>=10;m=m-1){
        k=sqrt(m);
        for(i = 2;i<=k;i++){
            if(m%i==0)
                break;

        }
        if(i>k)
            printf("%d",m);break;
    }
    return 0;
}