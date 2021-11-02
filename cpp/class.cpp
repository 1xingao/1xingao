#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //包含sort函数
#include<stdlib.h>
using namespace std;

class Base
{
public:
    virtual void funA() = 0;
    virtual ~Base() { cout << "基类析构" << endl; }
};
class Test : public Base
{
private:
    int t1, t2;
    void funA() { cout << "派生类输出" << endl; } //多态
    ~Test() { cout << "派生类析构" << endl; }     //派生类使用基类的虚函数的时候不需要再次声明
};
class Complex
{
private:
    int c1, c2;

public:
    Complex(int x, int y) : c1(x), c2(y) {} //构造函数名字与类名相同
    Complex(int y)
    {
        c1 = 0;
        c2 = y;
    }
    int clac();
    void setc1(int data) { c1 = data; } //提供对象外访问对象私有变量的接口
    int getc1() { return c1; }
    Complex operator+(const Complex &b) //运算符重载再对象里面时候少一个参数
    {
        return Complex(c1 + b.c1, c2 + b.c2);
    }
    int getc2() { return c2; }
    void returncha();
    // friend class letter;
    friend Complex operator-(const Complex &a, const Complex &b); //友元函数，可以直接访问私有变量
};
Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.c1 - b.c1, a.c2 - b.c2); //返回一个临时对象
}
void Complex::returncha()
{
    cout << "基类输出" << endl;
}
int Complex::clac()
{
    return c1 + c2;
}
//函数模板
template <class T>
T maxelement(T a[],int size)
{
    T tempmax = a[0];
    for (int i = 0;i<size;++i){
        if (tempmax <a[i])
            tempmax = a[i];
    
    }
    return tempmax;
}
template<class T,class Pref>

void Map(T s,T e,T x,Pref op)//op是函数名也是一个函数指针
{
    for(;s!=e;++s,++x){
        *x = op(*s);
    }
}
int sqre(int c){return c*c*c;}
double sqre_double(double d){return d*d;}
class Com : public Complex //继承方法
{
private:
    int c3;

public:
    Com(int x1, int x2, int x3) : Complex(x1, x2), c3(x3) {} //初始化函数
    void returnchar()                                        //覆盖基类的函数
    {
        Complex::returncha(); //调用基类方法
        cout << "继承类输出" << endl;
    }
};
/*
class Letter
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
void function_template()
{
    int array[] {1,2,4,5,6,78,9};
    int size = sizeof(array)/sizeof(array[0]);
    int max_array = maxelement(array,size);
    //maxelement<int>(array,size);这样直接给定T的替换类型
    cout << max_array << endl;
    int arra[5] {1,2,3,4,5},b[5];
    double araa_dou[5] {1.2,1.31,1.3,1.4,1.11},b_dou[5];
    Map(arra,arra+5,b,sqre);
    cout << b[4] <<endl;
}
void object_practice()
{
    Complex d1{1, 2};
    Complex e1{2, 4};
    Complex e2{6};
    int re = d1.clac();
    printf("%d\n", re);
    d1.setc1(5); //调用接口改变私有变量的值
    printf("%d\n", d1.getc1());
    cout << "继承方法测试" << endl;
    d1.returncha(); //基类
    cout << "声明派生类后的调用" << endl;
    Com c1{1, 2, 3};
    c1.returnchar(); //派生类
    // letter l1;
    // l1.lis[1]->setc1(1);
    // l1.test_ptr();
    cout << (d1 + e2).getc1() << endl;
    cout << (d1 - e1).getc2() << endl;
    Base *p1 = new Test; //基类指针可以指向派生类
    p1->funA();
    delete p1;
}
void fileio_practice()
{
    //文件读写
    vector<int> v;
    ifstream srcfile("in.txt", ios::in);
    ofstream dirfile("out.txt", ios::out);
    int x;
    while (srcfile >> x)
    {
        v.push_back(x);
    }
    // vector <int> cpt;
    // cpt.push_back(1);
    // cpt.push_back(2);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        dirfile << v[i] << " ";
        // cout <<"2";
        // cout << v[i];
    }
    srcfile.close();
    dirfile.close();
}
//类模板
template<class T1,class T2>
class pair_re
{
    public:
    T1 key;
    T2 value;
    pair_re(T1 k,T2 v):key(k),value(v){};
    bool operator < (const pair_re<T1,T2> &p) const{return key <p.key;};
};

void class_template()
{
    pair_re<string,int> student("tom",19);//类模板的实例化
    cout<<student.key<<endl;
    pair_re<int,double> student1(1,1.1);
    cout<<student1.key <<endl;
}
int main()
{
    object_practice(); // object test function
    fileio_practice(); // file test function
    function_template();//function template test function
    class_template(); //class template test function
    return 0;
}