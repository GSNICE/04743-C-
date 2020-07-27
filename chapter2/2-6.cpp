#include <iostream>
using namespace std;
class Box
{
	public:
		double length;
		void setWidth(double wid);
		double getWidth();
	private:
		double width;
};
//类体外定义成员函数
double Box::getWidth()
{
	return width;
}
void Box::setWidth(double wid)
{
	width = wid;
}
int main()
{
	Box box;//声明一个对象
	//不使用成员函数设置长度
	box.length = 10.0;
	cout <<"Length of box:" << box.length<< endl;//输出 length 是公有的
	//不使用成员函数设置宽度
	//box.width = 10; //错误 因为width是私有
	box.setWidth(10.0);	//必须使用成员函数设置宽度
	cout << "Width of box:" << box.getWidth() << endl; //输出 Width of box = 10;
	return 0;
}

	

