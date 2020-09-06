#include <iostream>
using namespace std;

template<int i>
class TestClass
{
public:
	int buffer[i];
	//使buffer的大小可变化，但其大小固定为int
	int getData(int j);
};

template<int i>
int TestClass<i>::getData(int j)
{
	return *(buffer+j);
}

int main()
{
	TestClass<6>ClassInstF;
	int i;
	double fArr[6] = {12.1, 23.2, 34.3, 45.4, 56.5, 67.6};
	for(i = 0; i < 6; i++)
		ClassInstF.buffer[i] = fArr[i] - 10;	

	for(i = 0; i < 6; i++)
	{
		double res = ClassInstF.getData(i);
		cout << res << " ";
	}	
	cout << endl;
}
