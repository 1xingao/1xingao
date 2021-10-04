#include<iostream>
using namespace std;
int* taget(int taget)
{
    int* tem = nullptr;
    int num1[4] {1,2,3};
    int num2[4]{4,5,6};
    int temp;
    for(int i =0 ;i<3;i++){
        temp = taget - num1[i];
        for (int j = 0; j<3; j++){
            if(temp == num2[j]){
                tem = (int*)malloc(sizeof(int)*2);//函数内部直接声明的指针不会被返回，再函数结束时自动销毁
                //所以需要显式申请内存或者将指针声明为static
                tem[0] = i;
                tem[1] = j;
            
                return tem;
            }
        }

    }
    return tem;
}
int main()
{
    int a= 7;
    int* pq = taget(a);
    cout << *pq <<","<<*(pq+1)<< endl;
    free(pq);
    return 0;
}
