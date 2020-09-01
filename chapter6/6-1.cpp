#include <iostream>
using namespace std;
class A
{
public:
	virtual void Print() //虚函数
	{
		cout << "A::Print" << endl;
	}
};

class B:public A //公有继承
{
public:
	virtual void Print() //虚函数
	{
		cout << "B::Print" << endl;
	}

};

class D:public A
{
public:
	virtual void Print() 
	{
		cout << "D::Print" << endl;
	}
};

class E:public B
{
public:
	virtual void Print()
	{
		cout << "E::Print" << endl;
	}
};

int main()
{
	A a; B b; D d; E e;
	A *pa = &a;
	B *pb = &b;
	pa->Print(); //多态，目前指向基类对象
	pa = pb;
	pa->Print(); //多态，目前指向派生类对象
	pa = &d;
	pa->Print(); //多态，目前指向派生类对象
	pa = &e;
	pa->Print(); //多态，目前指向派生类对象
	return 0;
}
