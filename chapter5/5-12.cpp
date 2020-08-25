#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int vBPub;
protected:
	int vBPro;
private:
	int vBPri;
public:
	Base()
	{
		vBPub = 10;
		vBPro = 20;
		vBPri = 30;
	};
	void SetPriValue(int);
	void SetProValue(int, int);
	int GetPriValue();
	int GetProValue();
};

void Base::SetPriValue(int k)
{
	vBPri = k; //直接访问基类的成员变量
}

void Base::SetProValue(int m, int n)
{
	vBPro = m;
	vBPri = n;
}

int Base::GetPriValue()
{
	return vBPri; //直接访问基类成员变量
}

int Base::GetProValue()
{
	return vBPro;  //直接访问基类成员变量
}

class Derived:public Base  //子类，公有继承于 Base 类
{
public:
	int vDPub, vBPub;
protected:
	int vDPro;
private:
	int vDPri;
public: //派生类的公有成员函数
	Derived()
	{
		vDPub = 100;
		vDPro = 200;
		vDPri = 300;
		vBPub = 15;
	}
	void SetPriValue(int);
	void SetProValue(int, int);
	int GetPriValue();
	int GetProValue();
	void PrintValue();
};

void Derived::SetPriValue(int k)
{
	vDPri = k; //直接访问派生类的成员对象
}

void Derived::SetProValue(int m, int n)
{
	vDPro = m;
	vDPri = n;
	Base::vBPro = 2 * m; //可以直接访问从基类继承的保护成员变量
	//Base::vBPri = 2 * n; //不可以直接访问从基类继承的私有成员变量
}

int Derived::GetPriValue()
{
	return vDPri; //直接访问派生类的成员
}

int Derived::GetProValue()
{
	return vDPro; //直接访问派生类的成员变量
}

void Derived::PrintValue()
{
	cout << "在派生类中访问基类" << endl;
	cout << "基类公有变量" << vBPub << endl; //派生类可以访问基类的公有成员变量
	cout << "基类保护变量" << vBPro << endl; //派生类可以访问基类的保护成员变量
	//cout << Base::vPri << endl;  不可以直接访问基类的私有变量 
	cout << "基类私有成员变量" << Base::GetPriValue() << endl; //通过函数访问
	cout << "在派生类中访问派生类" << endl;
	cout << "派生类公有对象:" << vDPub << endl;//可以直接访问
	cout << "派生类保护变量:" << vDPro << endl;//可以直接访问
	cout << "派生类私有变量:" << vDPri << endl;//可以直接访问
	cout << "从基类继承的公有变量" << Base::vBPub << endl;//可以直接访问
	cout << "从基类继承的保护变量" << Base::vBPro << endl; //可以直接访问
	//cout << "从基类继承的私有变量" << Base::vBPri << endl;//不可以直接访问
}

int main()
{
	Base bObj;
	Derived dObj;
	cout << "在主函数中访问基类" << endl;
	cout << "公有成员:" << bObj.vBPub << endl; //类外可以访问基类的公有成员变量
	//cout << "保护成员:" << bObj.vBPro << endl;  //不能直接访问保护成员变量
	cout << "保护成员:" << bObj.GetProValue() << endl; //通过函数访问
	cout << "私有成员:" << bObj.GetPriValue() << endl; //通过函数访问
	cout << "在主函数中访问派生类:" << endl;
	cout << "公有成员:" << dObj.vDPub << endl; //类外可以访问派生类的公有成员变量
	//cout << "保护成员:" << dObj.vDPro << endl; //不能直接访问保护成员变量
	cout << "保护成员" << dObj.GetProValue() << endl; //通过函数访问
	cout << "基类保护成员" << dObj.Base::GetProValue() << endl; //通过函数访问
	cout << "私有成员" << dObj.Base::GetPriValue() << endl; //通过函数访问
	cout << "dObj.vBPub =" << dObj.GetPriValue() << endl;
	cout << "dObj.Base::vBPub=" << dObj.Base::vBPub << endl;
	dObj.PrintValue();

	return 0;
}
	






	

