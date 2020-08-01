#include <iostream>
using namespace std;
int fvalue = 10;
class CDemo
{
public:
	const int num; 	//常量型成员变量
	const int& ref; //常引用型成员变量
	int value;
public:
	CDemo(int n):num(n), ref(value), value(4){}
};

int main()
{
	cout << sizeof(CDemo) << endl;
	CDemo f(100);
	//f.ref = f.value; //错误
	cout << "f.num =" << f.num << "\tf.ref=" << f.ref << "\tf.value =" << f.value << endl;
}

