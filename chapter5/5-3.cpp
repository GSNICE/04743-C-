#include <iostream>
using namespace std;
class another;
class Base
{
private:
	float x;
public:
	void print(const another &K);
};

class Derived:public Base 	//派生类
{
private:
	float y;
};

class another
{
private:
	int aaa;
public:
	another()
	{
		aaa = 100;
	}
	friend void Base::print(const another &K); //基类的成员函数声明为本类的友元
};
void Base::print(const another &K)
{
	cout << "Base:" << K.aaa << endl; //可以访问私有成员变量
}

int main()
{
	Base a;
	Derived d;
	another ano; // aaa 初始化为100
	a.print(ano); //输出:Base:100
	d.print(ano); //输出:Base:100
	return 0;
}

