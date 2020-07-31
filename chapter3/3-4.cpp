#include <iostream>
using namespace std;

class classA
{
	public:
		double x, y;
		static int num; //公有静态成员变量，供所有的对象共享
		//用于记录通过构造函数已经生成的对象的个数
		classA()
		{		
			x = 0;
			y = 0;
			num++;
		}
		classA(double x0, double y0)
		{
			x = x0;
			y = y0;
			num++;
		}
		static void staticFun()
		{
			cout << "current_num=" << num << endl;	
			//cout << "x=" << x << endl; //错误 在静态函数中不可以访问非静态成员
		}
};
int classA::num = 0; //必须在类体外（使用类名限定初始化静态成员变量


int main()
{
	classA obj(1.2, 3.4),*p;
	cout << "classA::num=" << classA::num << endl; //使用类名做限定符
	classA::staticFun();
	cout << "obj.num =" << obj.num << endl; //使用对象名称限定符
	obj.staticFun();
	cout << endl;
	classA A[3]; //调用三次构造函数
	cout << "class A::num=" << classA::num << endl;
	classA::staticFun();
	cout << endl;
	p = new classA(5.6, 7.8);
	cout << "classA::num=" << classA::num << endl;
	classA::staticFun();
	cout << "p->num =" << p->num << endl;
	p->staticFun();
	return 0;
}

	
