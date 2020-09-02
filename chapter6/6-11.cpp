#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void showa()
    {
        cout << "a =" << a << endl;
    }
};

class B:virtual public A //对类A进行了虚继承
{
public:
    int b;
};

class C:virtual public A //对类A进行了虚继承
{
public:
    int c;
};

class D:public B, public C
//派生类D的两个基类B、C具有共同的基类A,
//采用了虚继承，从而使类D的对象中只包含着类A的一个实例
{
public:
    int d;
};

int main()
{
    D Dobj; //声明派生类D的对象
    Dobj.a = 11; //若不是虚继承，此行会出错，因为D::a具有二义性
    Dobj.b = 22;
    Dobj.showa(); //输出 a = 11
    //若不是虚继承，此行会出错，因为"D::a" 具有二义性
    cout << "Dobj.b =" << Dobj.b << endl; //输出 Dobj.b = 22
}
