#include <iostream>
using namespace std;
class Demo
{
	int id;
	string position;
public:
	Demo(int i, string pos)
	{
		id = i;
		position = pos;
		cout << "生成对象" << this << ",id=" << id << "位置:" << position << endl;
	}
	Demo(int i):position("temp") 	//类型转换构造函数
	{
		id = i;
		cout << "生成对象" << this << ", id" << id << "位置:" << position << endl;
	}
	~Demo()
	{
		cout << "消亡对象" << this << ", id" << id << "位置:" << position << endl;
	}
};

Demo d1(1, "全局");
void Func()
{
	cout << "enter func" << endl;
	static Demo d2(2, "函数fun内,静态的");  //函数内定义，静态局部
	Demo d3(3, "函数 Func内");		//函数内定义，局部的
	cout << "exit func" << endl;
}
int main()
{
	cout << "enter main" << endl;
	Demo d4(4, "主函数内");
	d4 = 7;
	cout << "enter block" << endl;
	{
		Demo d5(5, "主函数块内");
	}
	cout << "exit block" << endl;
	static Demo d6(6, "主函数内，静态的"); 	//主函数内定义，静态的
	Func();
	cout << "main ends" << endl;
	return 0;
}
