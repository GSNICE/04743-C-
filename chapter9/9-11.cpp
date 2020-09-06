#include <iostream>
using namespace std;

template<class T> //类模板，基类
class TBase
{
	T data;
public:
	void print()
	{
		cout << data << endl;
	}
};

class Derived:public TBase<int>
{
};

int main()
{
	Derived d;
	d.print();
	return 0;
}
