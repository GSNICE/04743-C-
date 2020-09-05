#include <iostream>
using namespace std;
template<typename T>
class Test
{
public:
	Test(T num)
	{
		k += num;
	}
	Test()
	{
		k += 1;
	}
	static void incrementK()
	{
		k += 1;
	}
	static T k; //类模板中的静态成员变量
};

template<typename T>
T Test<T>::k = 0; //静态成员变量的初始化

int main()
{
	//static Field
	Test<int>a;
	Test<double>b(4);
	cout << "Test<int>::\tk=" << a.k << endl;	
	cout << "Test<double>::\tk" << b.k << endl;
	
	Test<int>v;
	Test<double>m;
	cout << "Test<int>::\tk= " << Test<int>::k << endl;
	cout << "Test<double>::\tk="<< Test<double>::k << endl; 
	//static Function
	cout << endl;
	Test<int>::incrementK();
	cout << "调用Test<int>::incrementK() Test<int>::k =" << Test<int>::k << endl;
	Test<double>::incrementK();
	cout << "调用Test<double>::incrementK() Test<double>::k =" << Test<double>::k << endl;
	return 0;
}
