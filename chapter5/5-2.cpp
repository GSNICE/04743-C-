#include <iostream>
using namespace std;
class BaseClass
{
	int v1, v2;
	char v4;
public:
	int temp1(){};
};

class DerivedClass:public BaseClass
{
	int v3;
	int *p;
public:
	int temp(){}
};

int main()
{
	cout << "Base =" << sizeof(BaseClass) << endl;
	cout << "Derived=" << sizeof(DerivedClass) << endl;
	return 0;
}
