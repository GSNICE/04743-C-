#include <iostream>
using namespace std;
class myComplex
{
private:
	double real, imag;
public:
	myComplex();
	myComplex(double r, double i);
	~myComplex(){}
	myComplex addCom(myComplex c1); //成员函数，调用对象与参数对象c1相加
	void outCom(); //成员函数
	void outCom(string s); //成员函数
	void changeReal(double r); //成员函数
	friend myComplex operator+(const myComplex &c1, const myComplex &c2); //c1+c2
	friend myComplex operator+(const myComplex &c1, double r);	//c1 + r
	friend myComplex operator+(double r, const myComplex &c1);	//r + c1
	friend myComplex operator-(const myComplex &c1, const myComplex &c2); //c1 - c2
	friend myComplex operator-(const myComplex &c1, double r);  // c1 - r
	friend myComplex operator-(double r, const myComplex &c1);  // r = c1
	myComplex &operator=(const myComplex &c); //成员函数
	myComplex &operator=(double);		//成员函数
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

myComplex myComplex::addCom(myComplex c1)
{
	return myComplex(this->real + c1.real, this->imag + c1.imag);
}

void myComplex::outCom(string s)
{
	cout << s << "=(" << real << "," << imag << ")" << endl;
}

void myComplex::changeReal(double r)
{
	this->real = r;
}
myComplex operator+(const myComplex &c1, const myComplex &c2) //c1 + c2
{
	return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
}
myComplex operator+(const myComplex &c1, double r) //c1 + r
{
	return myComplex(c1.real + r, c1.imag);
}
myComplex operator+(double r, const myComplex &c1)
{
	return myComplex(r + c1.real, c1.imag);
}
myComplex operator-(const myComplex &c1, const myComplex &c2) //c1 - c2
{
	return myComplex(c1.real - c2.real, c1.imag - c2.imag);
}
myComplex operator-(const myComplex &c1, double r)
{
	return myComplex(c1.real - r, c1.imag);
}
myComplex &myComplex::operator=(const myComplex &c1)
{
	this->real = c1.real;
	this->imag = c1.imag;
	return *this;
}
myComplex &myComplex::operator=(double r)
{
	this->real = r;
	this->imag = 0;
	return *this;
}

int main()
{
	myComplex c1(1, 2), c2(3, 4), res;
	c1.outCom("\t\t\tc1");
	c2.outCom("\t\t\tc2");
	res = c1 + c2;
	res.outCom("执行 res = c1 + c2->\tres");
	res = c1.addCom(c2);
	res.outCom("执行 res = c1.addCom(c2)->\tres");
	res = c1 + 5;
	res.outCom("执行 res = c1 + 5->\tres");
	res = 5 + c1;
	res.outCom("执行 res = 5 + c1->\tres");
	res = c1;
	c1.outCom("\t\t\tc1");
	res.outCom("执行res = c1->\tres");
	c1.changeReal(-3);
	c1.outCom("执行 c1.changeReal(-3)->\tc1");
	res = c1;
	res.outCom("执行 res = c1->\tres");
	res = 7;
	res.outCom("执行 res = 7->\tres");
	res = 7 + 8;
	res.outCom("执行 res = (7+8)->\tres");
	res = c1 = c2;
	c1.outCom("\t\t\tc1");
	c2.outCom("\t\t\tc2");
	res.outCom("执行 res = c1 = c2->\tres");
	return 0;
}

