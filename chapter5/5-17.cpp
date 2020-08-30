#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		i = 100;
		cout << "类 A 默认构造函数" << endl;
	}
	A(const A &s)
	{
		i = s.i;
		cout << "类 A 复制构造函数" << endl;
	} 
	int getValue(); //取值
	void setValue(int); //设置值
private:
	int i;
};

int A::getValue()
{
	return i;
}

void A::setValue(int k)
{
	i = k;
}

class B:public A
{
private:
	float f;
public:
	B()
	{
		f = 20.1;
		cout << "类 B 默认构造函数" << endl;
	}
	
	B(const B &v):A::A(v),f(v.f)
	{
		cout << "类B 复制构造函数" << endl;
	}
	
	float getValue();
	int getValue1()
	{
		return A::getValue();
	}
};

float B::getValue()
{
	return f;
}

int main()
{
	A a;
	B b;
	B bb(b);
	return 0;
}


