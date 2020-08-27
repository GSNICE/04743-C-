#include <iostream>
using namespace std;
class BaseClass
{
protected:
	int v1, v2;
public:
	BaseClass();
	BaseClass(int, int);
	~BaseClass();
};

BaseClass::BaseClass()
{
	cout << "BaseClass 无参构造函数" << endl;
}

BaseClass::BaseClass(int m, int n)
{
	v1 = m;
	v2 = n;
	cout << "BaseClass 2 个参数构造函数" << endl;
}

BaseClass::~BaseClass()
{
	cout << "BaseClass 析构函数" << endl;
}


class DerivedClass:public BaseClass //公有继承的派生类
{
	int v3;
public:
	DerivedClass();
	DerivedClass(int);
	DerivedClass(int, int, int);
	~DerivedClass();
};

DerivedClass::DerivedClass()
{
	cout << "DerivedClass 无参构造函数" << endl;
}

DerivedClass::DerivedClass(int k):v3(k)
{
	cout << "DerivedClass 带 1 个参数的构造函数" << endl;
}

DerivedClass::DerivedClass(int m, int n, int k):BaseClass(m, n),v3(k)
{
	cout << "DerivedClass 带 3 个参数的构造函数" << endl;
}

DerivedClass::~DerivedClass()
{
	cout << "DerivedClass 析构函数" << endl;
}

int main()
{
	cout << "带参数对象的创建" << endl;
	BaseClass baseCla1(10, 20);
	DerivedClass derivedCla1(30);
	return 0;
}

