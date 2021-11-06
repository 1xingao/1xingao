#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> //包含sort函数
#include <stdlib.h>
using namespace std;

typedef const int conint;
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
T maxelement(T a[], int size)
{
    T tempmax = a[0];
    for (int i = 0; i < size; ++i)
    {
        if (tempmax < a[i]) tempmax = a[i];
    }
    return tempmax;
}
template <class T, class Pref>
void Map(T s, T e, T x, Pref op) // op是函数名也是一个函数指针
{
    for (; s != e; ++s, ++x)
    {
        *x = op(*s);
    }
}
int sqre(int c)
{
    return c * c * c;
}
double sqre_double(double d)
{
    return d * d;
}
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
    int array[]{1, 2, 4, 5, 6, 78, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int max_array = maxelement(array, size);
    // maxelement<int>(array,size);这样直接给定T的替换类型
    cout << max_array << endl;
    int arra[5]{1, 2, 3, 4, 5}, b[5];
    double araa_dou[5]{1.2, 1.31, 1.3, 1.4, 1.11}, b_dou[5];
    Map(arra, arra + 5, b, sqre);
    cout << b[4] << endl;
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
class class_function
{
    //private:
    //int i1,i2,i3;
    public:
    //class_function(int x1,int x2,int x3):i1(x1),i2(x2),i3(x3){}
    //double operator()()
    //{
    //    return (double)(i1+i2+i3)/3;
    //}
    double operator()(conint i1,conint i2,conint i3)
    {
        return (double)(i1+i2+i3)/3;
    }
};
void stl_fun()
{
    class_function arrag;
    cout<<arrag(1,2,3)<<endl;
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
template <class T1, class T2>
class pair_re
{
public:
    T1 key;
    T2 value;
    pair_re(T1 k, T2 v) : key(k), value(v){};
    pair_re(){};
    bool operator<(const pair_re<T1, T2> &p) const { return key < p.key; };
};
template <class t1,class t2>
class pair_re_1: public pair_re<t2,t1>
//此时也可以直接给定基类模板的类型，实例化的时候就不会参照派生模板实例化
{
    public:
    t1 key_1;
    t2 value_1;
};
void class_template()
{
    pair_re<string, int> student("tom", 19); //类模板的实例化
    cout << student.key << endl;
    pair_re<int, double> student1(1, 1.1);
    cout << student1.key << endl;
    pair_re_1<int ,double>obj1;//此时是由类模板派生类模板，但是实例化的两个对象t1,t2的类型是相反的
    //分别是pair_re<double,int>和pair_re_1<int,double>
    
}
void string_te()
{
    string str1("string");
    int len = str1.length();
    string bjec;
    //cin >> bjec;//getline(cin,s);
    string str2;
    str2 = str1; 
    //str2.assign(str1);复制str2.assign(str1,1,3);
    //从第一个下标复制三个字符到str2
    str2[1] = str1[2];
    //单独复制,at(i)函数用于访问每一个元素
    string str3;
    str3 = str1 +str2;//将str2拼接
    //str3.apprnd(str1,3,str11.size());后两个参数可选
    int reture_bool = str3.compare(1,2,str2,2,3);
    string str4 = str2.substr(1,5);
    //返回一个字符串从1开始的五个字符
    //str2.find("str");str2.rfind("str");后者是从后往前找
    str3.erase(2);//删除下标2后边的字符
    str2.replace(2,3,"1234");
    //将str2下标2开始3个字符换成123
    str1.insert(2,"qwe");
    cout << str1 <<" "<<str2<<" " <<" "<< str3<< endl;
    cout << str4 << endl;
    cout << reture_bool << endl;
    //c_str()函数可以返回一个char*类型

}
int main()
{
    /*
    object_practice();   // object test function
    fileio_practice();   // file test function
    function_template(); // function template test function
    class_template();    // class template test function
    */
    string_te();
    stl_fun();
    return 0;
}