#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x = 1234567.89, y = 1.23456789;
	//1)无格式控制时
	cout << "无格式控制: \t\t 1)x=(" << x << "), y = (" << y << ")\n";
	//2)保留五位有效数字
	cout << "保留五位有效数字： \t 2) x=(" << setprecision(5) << x << "), y=(" << y << ")\n";
	//3)保留小数点以后五位
	cout << "保留小数点后五位有效数字： \t 2) x=(" << fixed << setprecision(5) << x << "), y=(" << y << ")\n";
	//4)科学计数法，且保留小数点以后五位
	cout << "科学计数法，且保留小数点以后五位数字: \t 2) x=(" << scientific << setprecision(5) << x << "), y=(" << y << ")\n";
	//5)非复数显示正号，输出宽度为12字符，宽度不足时用'*'填补
	cout << "5)" << showpos << fixed << setw(12) << setfill('*') << y << endl;
	//6)非复数不显示正号，输出宽度为12字符，宽度不足时右边用填充字符填充
	cout << "6)" << noshowpos << setw(12) << left << y << endl;
	//7)输出宽度为12字符，宽度不足时左边用填充字符填充
	cout << "7)" << setw(12) << right << y << endl;
	//8)宽度不足时，符号和数值分列左右，中间用填充字符填充
	cout << "8)" << setw(12) << internal << -y << endl;
	return 0;
	
}
