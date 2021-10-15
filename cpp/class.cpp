#include<stdio.h>
class Complex{
    private:
    int c1,c2;
    public:
    Complex(int x,int y)//构造函数名字与类名相同
    {
        c1 = x;
        c2 = y;
    }
    Complex(int y)
    {
        c2 = y;
    }
    int clac();
    void setc1(int data){this ->c1 = data;}
    int getc1(){return c1;}
    int getc2(){return c2;}

};
int Complex:: clac()
{
    return c1+c2;
}
int main()
{
    Complex d1{1,2};Complex e1{2,4};Complex e2{6};
    int re = d1.clac();
    printf("%d\n",re);
    printf("%d",d1.getc1());
    return 0;
}