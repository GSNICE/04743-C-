#include <iostream>
using namespace std;

template<class T>
class TestClass
{
public:
	T buffer[10];  //T类型的数据成员 buffer 数组大小固定为10
	T getData(int j); //获取T类型buffer(数组)的第j个分量
};


template<class T>
T TestClass<T>::getData(int j)
{
	return *(buffer+j);
}

int main()
{
	TestClass<char>ClassInstA; //char 取代 T, 从而实例化为一个具体的类
	int i;
	char cArr[6] = "abcde";
	for(int i = 0; i < 5; i++)
		ClassInstA.buffer[i] = cArr[i];

	for(i = 0; i < 5; i++)
	{
		char res = ClassInstA.getData(i);
		cout << res << " ";
	}
	cout << endl;
	
	TestClass<double>ClassInstF; //实例化为另外一个具体的类
	double fArr[6] = {12.1, 23.2, 34.3, 45.4, 56.5, 67.6};
	for(i = 0; i < 6; i++)
		ClassInstF.buffer[i] = fArr[i];

	for(i = 0; i < 6; i++)
	{
		double res = ClassInstF.getData(i);
		cout << res << " ";
	}
	cout << endl;
	return 0;
}
