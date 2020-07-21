#include <iostream>
using namespace std;
void SwapValue(int a, int b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void SwapRef(int& a, int& b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void SwapPointer(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int main()
{
	int a = 10 ,b = 20;
	cout << "数据交换前：\t\ta=" << a << ",b=" << b << endl;
	SwapValue(a, b);
	cout << "调用SwapValue()后：\t\ta=" << a << ",b=" << b << endl;
	a = 10;
	b = 20;
	SwapRef(a, b);
	cout << "调用SwapRef()后：\t\ta=" << a << ",b=" << b << endl;
	return 0;
}



