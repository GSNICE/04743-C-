#include <iostream>
using namespace std;
class CTyre	//轮胎类
{
private:
	int radius; //半径
	int width; //宽度
public:
	CTyre():radius(16),width(185)
	{
		cout << "使用CTyre默认构造函数" << "this=" << this << endl;
	}
	~CTyre()
	{
		cout << "使用析构函数" << "this=" << this << endl;
	}
	CTyre(int r, int w):radius(r), width(w){}
	int getRadius()
	{
		return radius;
	}
	int getWidth()
	{
		return width;
	}
};

class CCar
{
private:
	int price; //价格
	CTyre tyre; //成员对象
public:
	CCar();
	CCar(int p, int tr, int tw);
	int getPrice()
	{
		return  price;
	}
	CTyre & getCTyre()
	{
		return tyre;
	}
};
CCar::CCar()
{
	price = 50010;
	CTyre();
};
CCar::CCar(int p, int tr, int tw):price(p), tyre(tr, tw){};	//使用初始化列表

int main()
{
	//CCar car(48900, 17, 225);
	//cout << "price=" << car.getPrice();
	//cout << "\tCTyre.Radius =" << car.getCTyre().getRadius() << "\tCTyre.Width =" << car.getCTyre().getWidth() << endl;
	cout << "main enter" << endl;
	CCar car1;
	cout << "price=" << car1.getPrice();
	cout << "\tCTyre.Radius =" << car1.getCTyre().getRadius() << "\tCTyre.Width =" << car1.getCTyre().getWidth() << endl;
	return 0;
}
