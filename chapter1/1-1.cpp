#include <iostream>
#include <string>
using namespace std;
int main()
{
	int oneInt1, oneInt2;
	char strArray[20];
	string str;
	double oneDouble;
	char oneChar = 'a';
	cout << "输入两个整数值，一个字符，一个字符串和一个浮点值，";
	cout << "以空格、Tab 键或 （Enter) 键分隔：" << endl;
	cin >> oneInt1 >> oneInt2 >> oneChar >> strArray >> oneDouble;
	str = strArray;
	cout << "输入的数据是" << endl; //endl 的作用的换行
	cout <<	"字符串是 :/t/t" << str << endl
		<< "两个整型的值分别是 :\t"<< oneInt1 << "和\t"<< oneInt2 << endl
		<< "字符是：\t\t" << oneChar << "\n"
		<< "浮点值是：\t\t" << oneDouble << endl;
	return 0;
}

