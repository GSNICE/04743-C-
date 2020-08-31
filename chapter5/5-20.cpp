#include <iostream>
#include <string>
using namespace std;

class myDate
{
public:
	myDate();
	myDate(int);
	myDate(int, int);
	myDate(int, int, int);
	myDate(const myDate &d);
	~myDate();
	void setDate(int, int, int);
	void setDate(myDate);
	myDate getDate();
	void setYear(int);
	int getMonth();
	void printDate()const;
private:
	int year, month, day;
};

myDate::myDate()
{
	year = 1970;
	month = 1;
	day = 1;
	cout << "myDate 默认构造函数" << endl;
}

myDate::myDate(int y)
{
	year = y;
	month = 1;
	day = 1;
	cout << "myDate 带一个参数的构造函数" << endl;
}

myDate::myDate(int y, int m)
{
	year = y;
	month = m;
	day = 1;
	cout << "myDate 带二个参数的构造函数" << endl;
}

myDate::myDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	cout << "myDate带三个参数的构造函数" << endl;
}

myDate::myDate(const myDate &d)
{
	year = d.year;
	month = d.month;
	day = d.day;
	cout << "myDate_COPY 构造函数" << endl;
}

myDate::~myDate()
{
	cout << "myDate 析构函数" << endl;
}

void myDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	return;
}

void myDate::setDate(myDate oneD)
{
	year = oneD.year;
	month = oneD.month;
	day = oneD.day;
	return;
}

myDate myDate::getDate()
{
	myDate d;
	d.year = year;
	d.month = month;
	d.day = day;
	return d;
}

void myDate::setYear(int y)
{
	year = y;
	return;
}

int myDate::getMonth()
{
	return month;
}

void myDate::printDate()const
{
	cout << year << "/" << month << "/" << day;
	return;
}

class CStudent
{
public:
	CStudent();
	CStudent(string, myDate);
	~CStudent();
	void setStudent(string, myDate);
	void setName(string);
	string getName();
	void setBirthday(myDate);
	myDate getBirthday();
	void printInfo()const;
private:
	string name; //姓名
	myDate birthday; //生日
};

CStudent::CStudent():name("Noname"), birthday(myDate())
{
	cout << "CStudent 默认构造函数" << endl;
}

CStudent::CStudent(string str, myDate d):name(str),birthday(d)
{
	cout << "CStudent 析构函数" << endl;
}

CStudent::~CStudent()
{
	cout << "CStudent 析构函数" << endl;
}
void CStudent::setStudent(string s, myDate d)
{
	name = s;
	birthday.setDate(d);
	return;
}

void CStudent::setName(string n)
{
	name = n;
	return;
}

string CStudent::getName()
{
	return name;
}

void CStudent::setBirthday(myDate d)
{
	birthday.setDate(d);
	return;
}

myDate CStudent::getBirthday()
{
	return birthday;
} 
void CStudent::printInfo()const 
{ 
	cout << "姓名：" << name << "\t 生日:";
	birthday.printDate(); //调用类myDate的成员函数
	cout << endl;
}

class CUndergraduateStudent:public CStudent // 本科生类，继承于CStudent类
{
private:
	string department; //学生所属的系名
public:
	CUndergraduateStudent();
	CUndergraduateStudent(string, myDate);
	~CUndergraduateStudent();
	void setDep(string);
	void printInfo();
};

CUndergraduateStudent::CUndergraduateStudent()
{
	cout << "CUndergraduateStudent 默认构造函数" << endl;
}

CUndergraduateStudent::CUndergraduateStudent(string str, myDate d):CStudent(str, d)
{
	cout << "CUndergraduateStudent 有参构造函数" << endl;
}

CUndergraduateStudent::~CUndergraduateStudent()
{
	cout << "CUndergraduateStudent 析构函数" << endl;
}

void CUndergraduateStudent::setDep(string dep)
{
	department = dep;
}

void CUndergraduateStudent::printInfo()
{
	CStudent::printInfo();
	cout << "院系:\t" << department << endl << endl;
}

int main()
{
	CUndergraduateStudent s2("小张", myDate());
	return 0;
}
