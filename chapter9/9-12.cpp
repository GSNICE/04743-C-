#include <iostream>
using namespace std;

class TBase// 基类，普通类
{
	int k;
public:
	void print()
	{
		cout << "TBase::" << k << endl;
	}
};

template<class T>
class TDerived:public TBase //派生类，类模板
{
	T data;
public:
	void setData(T x)
	{
		data = x;
	}
	void print()
	{
		TBase::print();
		cout << "TDerived::" << data << endl;
	}
};

int main()
{
	TDerived<string> d; //类模板实例化，并声明对象d
	d.setData("2019");
	d.print();
}
