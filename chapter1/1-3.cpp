#include <iostream>
using namespace std;
void func(int a = 11, int b = 22, int c = 33) //为参数设置默认值
{
	cout<< "a="<< a << ",b="<< b << ",c=" << c << endl;
}
int main()
{
	func();
	func(55);			//调用时缺少了3个实参，将使用定义中的后两个参数默认值。
	func(77, 99); 		//调用时缺少了2个实参，将使用定义中的最后一个参数默认值。
	func(8, 88, 888);
	return 0;
} 
