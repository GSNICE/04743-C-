#include <iostream>
using namespace std;

class BaseClass
{
public:
	int v1, v2; //公有访问权限
	BaseClass():v1(1), v2(1){}
	int temp1(){} //公有访问权限
};

class DerivedClass:public BaseClass
{
	int v1; //改为私有访问权限
	int temp1(){} //改为私有访问权限
public:
	DerivedClass():v1(10){}
	void printv()
	{
		cout << "v1=" << v1 << endl; //输出派生类中的值 v1=10
		cout << "Base.v1=" << BaseClass::v1 << endl; //输出继承基类中的值 Base.v1=1
	}
};

int main()
{
	BaseClass bc;
	DerivedClass dc;
	dc.printv();
	return 0;
}
