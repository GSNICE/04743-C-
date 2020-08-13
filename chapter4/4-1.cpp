#include <iostream>
using namespace std;
class myComplex
{
private:
	double real, imag;
public:
	myComplex(); //构造函数
	myComplex(double r, double i); //构造函数
	void outCom(); //成员函数
	myComplex operator-(const myComplex &c);
	friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元
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
void myComplex::outCom()
{
	cout << "(" << real << "," << imag << ")";
}
myComplex myComplex::operator-(const myComplex &c)
{
	return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
}
myComplex operator+(const myComplex &c1, const myComplex &c2)
{
	return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
}

int main()
{
	myComplex c1(1,2), c2(3,4), res;
	c1.outCom();
	cout << "operator+";
	c2.outCom();
	cout << "=";
	res = c1 + c2;
	res.outCom();
	cout << endl;

	c1.outCom();
	cout << "operator-";
	c2.outCom();
	cout << "=";
	res = c1-c2;
	res.outCom();
	cout << endl;
	return 0;
}


