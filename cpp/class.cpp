#include<stdio.h>
#include<iostream>
using namespace std;

class Complex{
    private:
    int c1,c2;
    public:
    Complex(int x,int y):c1(x),c2(y){}//构造函数名字与类名相同
    Complex(int y)
    {
        c1 = 0;
        c2 = y;
    }
    int clac();
    void setc1(int data){c1 = data;}//提供对象外访问对象私有变量的接口
    int getc1(){return c1;}
    Complex operator+(const Complex &b)//运算符重载再对象里面时候少一个参数
    {
       return Complex( c1+b.c1,c2+b.c2);
    }
    int getc2(){return c2;}
    void returncha();
    //friend class letter;
    friend Complex operator-(const Complex &a,const Complex &b);//友元函数，可以直接访问私有变量

};
Complex operator-(const Complex &a,const Complex &b)
{
    return Complex(a.c1+b.c1,a.c2+b.c2);//返回一个临时对象
}
void Complex::returncha()
{
    cout << "基类输出" << endl;
}
int Complex:: clac()
{
    return c1+c2;
}
class Com:public Complex    //继承方法
{
    private:
    int c3;
    public:
    Com(int x1,int x2,int x3):Complex(x1,x2),c3(x3){}//初始化函数
    void returnchar()//覆盖基类的函数
    {
        Complex::returncha(); //调用基类方法
        cout << "继承类输出" << endl;
    }

};
/*
class letter
{
    public:
    Com* lis[2];
    //lis[1] = new Com;
    void test_ptr()
    {
        cout << lis[1]->c1 << endl;
    }

};
*/
int main()
{
    Complex d1{1,2};Complex e1{2,4};Complex e2{6};
    int re = d1.clac();
    printf("%d\n",re);
    d1.setc1(5);
    printf("%d\n",d1.getc1());
    cout << "继承方法测试"<<endl;
    d1.returncha();//基类
    cout <<"声明派生类后的调用" << endl;
    Com c1{1,2,3};
    c1.returnchar();//派生类
    //letter l1;
    //l1.lis[1]->setc1(1);
    //l1.test_ptr();
    
    return 0;
}