#include <iostream>
using namespace std;
class pointer
{
	public:
		int a;
		int *p;
		pointer()
		{
			a = 100;
			p = new int(10);
		}
		pointer(const pointer &tempp)//复制构造函数
		{
			if(this != &tempp)//避免a=a这样的赋值
			{
				a = tempp.a;
				p = tempp.p;
			}
		}
};

int main()
{
	pointer p1; //使用默认构造函数
	pointer p2(p1); //使用复制构造函数
	pointer p3 = p1; //使用复制构造函数
	cout << "\n初始化后，各对象的值及内存地址" << endl;
	cout << "对象名\t对象地址 a的值 p中的值 p指向的值 p的地址" << endl;
	cout << "p1:\t" << &p1 << ", " << p1.a << ", " << p1.p << ",	"<< *p1.p <<",	"<< &p1.p << endl;
	cout << "p2:\t" << &p2 << ", " << p2.a << ", " << p2.p << ",	"<< *p2.p <<",	"<< &p2.p << endl;
	cout << "p3:\t" << &p3 << ", " << p3.a << ", " << p3.p << ",	"<< *p3.p <<",	"<< &p3.p << endl;
	*p1.p = 20;
	p2.a = 300;
	cout << "\n 修改后，各对象的值及内存中的地址" << endl;
	cout << "对象名\t对象地址 a的值 p中的值 p指向的值 p的地址" << endl;
	cout << "p1:\t" << &p1 << ", " << p1.a << ", " << p1.p << ",	"<< *p1.p <<",	"<< &p1.p << endl;
	cout << "p2:\t" << &p2 << ", " << p2.a << ", " << p2.p << ",	"<< *p2.p <<",	"<< &p2.p << endl;
	cout << "p3:\t" << &p3 << ", " << p3.a << ", " << p3.p << ",	"<< *p3.p <<",	"<< &p3.p << endl;
	return 0;
}


