#include <iostream>
using namespace std;
class A
{
public:
    int i;
    virtual void func(){} //虚函数
    virtual void func2(){}//虚函数
};

class B:public A
{
    int j;
    void func(){}
};

int main()
{
    cout << sizeof(A) << "," << sizeof(B); //输出类的大小
    return 0;
}
