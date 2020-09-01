#include <iostream>
using namespace std;
class BaseClass1
{
protected:
    int v1,v2;
public:
    BaseClass1();
    BaseClass1(int, int);
    ~BaseClass1();
};

BaseClass1::BaseClass1()
{
    cout << "BaseClass1 无参构造函数" << endl;
}

BaseClass1::BaseClass1(int m, int n):v1(m),v2(n)
{
    cout << "BaseClass1 带二个参数构造函数" << endl;
}

BaseClass1::~BaseClass1()
{
    cout << "BaseClass1 的析构函数" << endl;
}


class BaseClass2:public BaseClass1
{
protected:
    int v3;
public:
    BaseClass2();
    BaseClass2(int);
    BaseClass2(int, int, int);
    ~BaseClass2();
};

BaseClass2::BaseClass2()
{
    cout << "BaseClass2 无参构造函数" << endl;
}

BaseClass2::BaseClass2(int m):v3(m)
{
    cout << "BaseClass2 带一个参数的构造函数" << endl;
}

BaseClass2::BaseClass2(int m, int n, int k):BaseClass1(m, n),v3(k)
{
    cout << "BaseClass2 带三个参数的构造函数" << endl;
}

BaseClass2::~BaseClass2()
{
    cout << "BaseClass2 析构函数" << endl; 
}

class DerivedClass:public BaseClass2
{
public:
    int v4;
public:
    DerivedClass();
    DerivedClass(int);
    DerivedClass(int, int, int, int);
    ~DerivedClass();
};

DerivedClass::DerivedClass()
{
    cout << "DerivedClass 无参构造函数" << endl;
}

DerivedClass::DerivedClass(int k):v4(k)
{
    cout << "DerivedClass 带1个参数的构造函数" << endl;
}

DerivedClass::DerivedClass(int m, int n, int k, int t):BaseClass2(m, n, k),v4(t)
{
    cout << "DerivedClass 带4个参数的构造函数" << endl;
}

DerivedClass::~DerivedClass()
{
    cout << "DerivedClass 析构函数" << endl;
}

int main()
{
    cout << "无参对象创建" << endl;
    DerivedClass derivedCla;
    return 0;
}


