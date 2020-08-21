#include <iostream>
using namespace std;
class Base
{
private:
	float x;
public:
	static int staV;
	Base()
	{
		staV++;
	}
};

int Base::staV = 0;
class Derived:public Base //派生类
{
private:
	float y;
public:
	Derived()
	{
		staV++;
	}
};

int main()
{
	Base a;
	cout << a.staV << endl; //输出1
	Derived d;
	cout << d.staV << endl; //输出3
	return 0;
}
