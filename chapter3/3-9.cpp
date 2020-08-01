#include <iostream>
using namespace std;
class constClass
{
	const int conMbr; //类中的常量成员变量
	int Mbr; 	//普通成员变量
public:
	constClass():conMbr(0),Mbr(100){}
	constClass(int i):conMbr(i)
	{
		Mbr = 200;
	}
	void printConst()
	{
		cout << "conMbr=" << conMbr << ",Mbr=" << Mbr << endl;
	}
	int getConst()
	{
		cout << "调用非常量函数" << endl;
		return conMbr;
	}
	int getConst()const
	{
		cout << "调用常量函数" << endl;
		return conMbr;
	}
	int getValue()
	{
		return Mbr;
	}
	void processConst()
	{
		cout <<"--在 processConst 函数中 非常量--" << endl;
		int x = 2 * conMbr + 1; 
		cout <<"x = 2 * conMbr + 1 = " << x << endl;
		Mbr++;
		cout << "Mbr =" << Mbr << endl;
	}
	void processConst()const
	{
		cout << "--在 processConst 函数中 常量--" << endl;
		int x = conMbr + 1;
		cout << "x = conMbr + 1" << x << endl; //可以读取conMbr;
		//conMbr++;
		//Mbr++;
		cout << "Mbr =" << Mbr << endl;
	}	
};


int main()
{
	constClass ob1(123),ob2;
	ob1.printConst();
	cout << "ob2.getConst()=" << ob2.getConst() << endl;
	ob2.processConst();
	const constClass ob3(20);
	cout << "ob3.getConst()=" << ob3.getConst() << endl;
	ob3.processConst();
	return 0;
}





