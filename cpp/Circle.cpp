#include<iostream>
using namespace std;
class Circle
{
public:
    double cr;
    Circle()
    {
        cr = 1.0;
    }
    Circle(double r)
    {
        cr = r;
    }
    double getarea()
    {
        return 3.14 * cr * cr;
    }
};
int main()
{
    double c;
    Circle c1{2.0};
    Circle c2;
    cout << c1.getarea() << endl;
    cin>>c;
    cout << c2.getarea() << endl;
    Circle c3{c};
    cout <<c3.getarea() << endl;
    return 0;
}