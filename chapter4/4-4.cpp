#include <iostream>
using namespace std;
class pointer
{
	public:
		int a;
		int *p; //指向整型数的指针
		pointer() //构造函数
		{
			a = 100;
			p = new int(10);
		}
		pointer(const pointer &tempp) //复制构造函数
		{
			if(this != &tempp)
			{
				a = tempp.a;
				p = new int();
				*p = *tempp.p;
			}
		}
		~pointer()
		{
			if(p != NULL)delete p;
		}
		pointer &operator=(const pointer &c) //成员函数
		{
			if(this == &c)return *this; //避免 a=a 这样的赋值
			delete this->p; 		//释放原来的空间
			this->p = new int(*c.p);	//申请新的空间保存值
			return *this;
		}
};


int main()
{
	pointer p1; //使用默认构造函数
	pointer p2(p1);//使用拷贝构造函数
	pointer p3;
	p1 = p1; //用来测试
	p3 = p1; //使用赋值构造函数
	cout << "\n初始化后，各对象的值以及内存地址" << endl;
	cout << "对象名\t对象地址	a的值	p中的值	p指向的值	p的地址" << endl;
	cout << "p1:\t" << &p1 << ", " << p1.a << ", " << p1.p << ", " << *p1.p << ", " << &p1.p << endl;
	cout << "p2:\t" << &p2 << ", " << p2.a << ", " << p2.p << ", " << *p2.p << ", " << &p2.p << endl;
	cout << "p3:\t" << &p3 << ", " << p3.a << ", " << p3.p << ", " << *p3.p << ", " << &p3.p << endl;
	*p1.p = 20;
	p2.a = 300;
	cout << "\n修改后，各对象的值及内存地址" << endl;
	cout << "对象名\t对象地址	a的值	p中的值	p指向的值	p的地址" << endl;
	cout << "p1:\t" << &p1 << ", " << p1.a << ", " << p1.p << ", " << *p1.p << ", " << &p1.p << endl;
	cout << "p2:\t" << &p2 << ", " << p2.a << ", " << p2.p << ", " << *p2.p << ", " << &p2.p << endl;
	cout << "p3:\t" << &p3 << ", " << p3.a << ", " << p3.p << ", " << *p3.p << ", " << &p3.p << endl;
	return 0;
}	



