#include <iostream>
using namespace std;
class myComplex
{
	private:
		double real, imag; //复数的实部和虚部
	public:
		myComplex();
		myComplex(double r, double i);
		myComplex addCom( myComplex c); //成员函数,调用者对象与参数对象 C 相加
		void outCom();			//成员函数，输出调用者对象的有关数据
};
myComplex::myComplex()
{
	real = 0;
	imag = 0;
}
myComplex::myComplex(double r, double i)
{
	real = r;
	imag = i;
}
myComplex myComplex::addCom(myComplex c)
{
	return myComplex( real + c.real, imag + c.imag);
}
void myComplex::outCom()
{
	cout << "(" << real << "," << imag << ")";
}
int main()
{
	myComplex c1(1, 2), c2(3, 4), res;
	res = c1.addCom(c2); 	//调用成员函数必须通过类对象
	c1.outCom();
	cout << "+";
	c2.outCom();
	cout << "=";
	res.outCom();
	cout << endl;
	return 0;
}


