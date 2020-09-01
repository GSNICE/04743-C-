#include <iostream>
using namespace std;

class CBase
{
protected:
	int n;
public:
	CBase(int i):n(i){}
	void Print()
	{
		cout << "CBase:n=" << n << endl;
	}
};

class CDerived:public CBase
{
public:
	int v;
	CDerived(int i):CBase(i),v(2*i){}
	void Func(){}
	void Print()
	{
		cout << "CDerived:n=" << n << endl;
		cout << "CDerived:v=" << v << endl;
	}
};

int main()
{
	CDerived objDerived(3);
	CBase objBase(5);
	CBase *pBase = &objDerived; //使用基类指针指向派生类对象

	CDerived *pDerived;
	pDerived = &objDerived;
	cout << "使用派生类指针调用函数" << endl;
	pDerived->Print(); //调用的是派生类中的函数
	pBase = pDerived; //基类指针等于派生类指针，正确
	cout << "使用基类指针调用函数" << endl;
	pBase->Print(); //调用的是基类中的函数
	//pBase->Func(); //错误，通过基类指针不能调用派生类函数
	//pDerived = pBase; //错误，基类指针不能直接赋值给派生类指针
	pDerived = (CDerived*)pBase; //强制类型转换，派生类指针 = 基类指针
	cout << "使用派生类指针调用函数" << endl;
	pDerived->Print(); //调用的是派生类中的函数
	return 0;
}

