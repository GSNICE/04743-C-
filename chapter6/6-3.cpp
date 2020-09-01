#include <iostream>
using namespace std;
class A
{
public:
	virtual void Print()
	{
		cout << "A::Print" << endl;
	}
};


class B : public A
{
public:
	virtual void Print()
	{
		cout << "B::Print" << endl;
	}
};

void PrintInfo(A &r)
{
	r.Print();
}

int main()
{
	A a;
	B b;
	PrintInfo(a); //使用基类对象
	PrintInfo(b); //使用派生类对象
	return 0;
}
