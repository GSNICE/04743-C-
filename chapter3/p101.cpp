#include <iostream>
#include <string>
using namespace std;


class myDate
{
public:
    myDate();                                       //构造函数
    myDate(int, int, int);          //构造函数
    void setDate(int, int, int);//设置日期
    void setDate(myDate);           //设置日期
    myDate getDate();                       //获取日期
    void setYear(int);                      //设置年
    int getMonth();                         //获取年
    void printDate()const;          //打印日期
private:
    int year, month, day;           //成员变量,表示年，月，日
};
//在类外定义成员函数
myDate::myDate()
{
    year = 1970; month = 1; day = 1;
}

myDate::myDate(int y, int m, int d)
{
    year = y; month = m; day = d;
}

void myDate::setDate(int y, int m, int d)
{
    year = y; month = m; day = d;
    return;
}

void myDate::setDate(myDate oneD)
{
    year = oneD.year; month = oneD.month; day = oneD.day;
    return;
}

myDate myDate::getDate()
{
    return *this;
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


class Student
{
public:
	Student();
	Student(string);
	void setStudent(string, myDate);
	void setStudent(string);
	void setName(string);
	string getName();
	void setBirthday(myDate);
	myDate getBirthday();
	void printStudent()const;
private:
	string name;
	myDate birthday;
};

Student::Student():name("Noname"),birthday(myDate()){}
Student::Student(string n):name(n),birthday(myDate()){}
void Student::setStudent(string s, myDate d)
{
	name = s;
	birthday.setDate(d);
	return;
}
void Student::setStudent(string s)
{
	name = s;
	myDate d;
	birthday.setDate(d);
	return;
}
void Student::setName(string n)
{
	name = n;
	return;
}
string Student::getName()
{
	return name;
}
void Student::setBirthday(myDate d)
{
	birthday.setDate(d);
	return;
}
myDate Student::getBirthday()
{
	return birthday;
}
void Student::printStudent()const
{
	cout <<"姓名:"<<name<<"\t生日:";
	birthday.printDate(); //调用myDate的成员函数
	cout << endl;
}


int main()
{
	Student stud;
	stud.printStudent(); //输出默认值 姓名: Noname 生日：1970/1/1
	stud.setName("111"); //姓名改为"111"，生日不变
	stud.printStudent(); //输出更改后的姓名
	Student *spointer[2] = {new Student(), &stud}; //初始化
	Student sy[2] = {Student(), stud}; //初始化
	for(int i = 0; i < 2; i++)
		spointer[i]->printStudent(); //使用指针的形式输出各指针指向的值

	for(int i = 0; i < 2; i++)
		spointer[i]->printStudent(); //使用.运算符输出各对象的值

	stud.setName("222"); //姓名改为222	
	for(int i = 0; i < 2; i++)
		spointer[i]->printStudent(); //sp[1]指向的对象的值发生改变了

	spointer[0]->setName("333");
	spointer[1]->setName("444");
	for (int i = 0; i < 2; i++)
		spointer[i]->printStudent(); //spointer 指向的对象的值发生改变了
	stud.printStudent(); 	//stud的值发生改变了

	for (int i = 0; i < 2; i++)
		sy[i].printStudent();	//值没有发生改变
	return 0;
}
