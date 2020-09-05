#include <iostream>
using namespace std;
template<class T> //类类型T
void Swap(T &x, T &y) //可以交换类对象
{
    T tmp = x;
    x = y;
    y = tmp;
}

class myDate
{
public:
    myDate();
    myDate(int, int, int);
    void printDate()const;
private:
    int year, month, day;
};

myDate::myDate()
{
    year = 1970;
    month = 1;
    day = 1;
}

myDate::myDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void myDate::printDate()const
{
    cout << year << "/" << month << "/" << day;
    return;
}

int main()
{
    int n = 1, m = 2;
    Swap(n, m);             //编译器自动生成void Swap(int &, int &)函数
    double f = 1.2, g = 2.3;
    Swap(f, g);             //编译器自动生成void Swap(double &, double &)函数
    myDate d1, d2(2000,1,1);
    Swap(d1, d2);           //编译器自动生成void Swap(myDate &, myDate &)函数
    return 0;
}




