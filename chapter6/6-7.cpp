#include <iostream>
using namespace std;

class A
{
public:
    virtual void hello()
    {
        cout << "A::hello" << endl;
    }
    virtual void bye()
    {
        cout << "A::bye" << endl;
    }
};

class B:public A
{
public:
    virtual void hello()
    {
        cout << "B::hello" << endl;
    }
    B()
    {
        hello(); //调用虚函数，但不是多态
    }
    ~B()
    {
        bye(); //调用虚函数，但不是多态
    }
};

class C:public B //派生类
{
public:
    virtual void hello() //虚函数
    {
        cout << "C::hello" << endl;
    }
};

int main()
{
    C obj;
    return 0;
}
