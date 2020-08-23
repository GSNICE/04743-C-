#include <iostream>
using namespace std;
class BaseClass
{
protected:
	int v1, v2; //保护成员
public:
	void SetValue(int m, int n)
	{
		v1 = m;
		v2 = m;
	}
	void PrintValue();
};

void BaseClass::PrintValue()
{
	cout << "v1 =" << v1 << "\tv2 =" << v2; //直接访问
}

class DerivedClass:public BaseClass
{
	int v3;
public:
	void SetValue(int m, int n, int k)
	{
		v1 = m; //派生类中可以访问基类中的保护成员变量
		v2 = n;
		v3 = k; //本类中的成员变量
	}
	void SetValue(int m, int n)
	{
		v1 = m; //派生类中可以访问基类中的保护成员变量
		v2 = n; 
	}
	void PrintValue();
};

void DerivedClass::PrintValue()
{
	cout << endl;
	BaseClass::PrintValue();
	cout << "\tv3=" << v3 << endl;
}

int main()
{
	BaseClass baseCla;
	DerivedClass derivedCla;
	cout << "初始时的随机值: " << endl;
	baseCla.PrintValue();
	derivedCla.PrintValue();
	cout << "从派生类修改成基类继承的值后" << endl;
	derivedCla.SetValue(10, 20);
	baseCla.PrintValue();
	derivedCla.PrintValue();
	cout << "从派生类修改从基类继承的值及本类继承的值" << endl;
	derivedCla.SetValue(100, 200, 300);
	baseCla.PrintValue();
	derivedCla.PrintValue();
	return 0;
}


