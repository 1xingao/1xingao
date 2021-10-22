#include<stdio.h>
class Complex{
    private:
    int c1,c2;
    public:
    Complex(int x,int y):c1(x),c2(y){}//构造函数名字与类名相同
    Complex(int y)
    {
        c1 = 0;
        c2 = y;·    
    }
    int clac();
    void setc1(int data){this->c1 = data;}//提供对象外访问对象私有变量的接口
    int getc1(){return c1;}
    Complex operator+(const Complex &b)//运算符重载再对象里面时候少一个参数
    {
       return Complex( c1+b.c1,c2+b.c2);
    }
    int getc2(){return c2;}
    friend Complex operator-(const Complex &a,const Complex &b);//友元函数，可以直接访问私有变量

};
Complex operator-(const Complex &a,const Complex &b)
{
    return Complex(a.c1+b.c1,a.c2+b.c2);//返回一个临时对象
}
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