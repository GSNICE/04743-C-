#include <iostream>
using namespace std;

class CBase
{
public:
    void func1()
    {
        cout << "CBase::func1()" << endl;
        func2();
        func3();
    }
    virtual void func2() //虚函数
    {
        cout << "CBase::func2()" << endl;
    }
    void func3() //虚函数
    {
        cout << "CBase::func3()" << endl;
    }
};

class CDerived:public CBase //派生类
{
public:
    virtual void func2() //虚函数
    {
        cout << "CDerived::func2()" << endl;
    }
    void func3()
    {
        cout << "CDerived::func3()" << endl;
    }

};

int main()
{
    CDerived d;
    d.func1();
    return 0;
}
