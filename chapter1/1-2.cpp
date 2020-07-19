#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	const int *p = &a;
	const int ca = 30;
	int *q;
	cout << "a的地址为：\t" << &a << "\ta的值为: \t" << a << endl;
	cout << "*p指向的地址为：" << p << "\t*p的值为：\t" << *p << endl;
	q = const_cast<int*>(p); //去除p的常量性赋给q
	*q = 20;
	cout << "a的地址为：\t" << &a << "\ta的值为: \t" << a << endl;
	cout << "p指向的地址为: " << p << "\t*p的值为: \t" << *p << endl;
	cout << "q指向的地址为: " << q << "\t*q的值为: \t" << *q << endl;
	cout << "分界线" << endl;
	p = &ca;
	q = const_cast<int*>(p);
	*q = 40;
	cout << "ca的值为：\t" << &ca << "\tca的值为：\t" << ca << endl;
	cout << "p指向的地址为\t" << p << "\t*p的值为: \t" << *p << endl;
	cout << "q指向的地址为\t" << p << "\t*q的值为: \t" << *q << endl;
	return 0;
}


	

