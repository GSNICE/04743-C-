#include <iostream>
#include <string>
using namespace std;
class CStudent //基类
{
private:
	string name; //姓名
	string id; //学号
	char gender; //性别 F代表女生，M代表男生
	int age; //年龄
public:
	void PrintInfo();
	void SetInfo(const string &, const string &, int, char);
	void SetName(string);
	string GetName();
	void SetId(string);
	string GetId();
};

void CStudent::PrintInfo()
{
	cout << "姓名:\t" << name << endl;
	cout << "学号:\t" << id << endl;
	cout << "年龄:\t" << age << endl;
	cout << "性别:\t" << gender << endl;
}

void CStudent::SetInfo(const string & name_, const string & id_, int age_, char gender_)
{
	name = name_;
	id = id_;
	age = age_;
	gender = gender_;
}

void CStudent::SetName(string name)
{
	this->name = name;
}

string CStudent::GetName()
{
	return name;
}

void CStudent::SetId(string id)
{
	this->id = id;
}

string CStudent::GetId()
{
	return id;
}


class CUndergraduateStudent:public CStudent //本科生类，继承于类 CStudent
{
private:
	string department; //学生所属的系名
public:
	void PrintInfo();
	void SetInfo(const string &, const string &, int, char, const string &);
};

void CUndergraduateStudent::SetInfo(const string & name_, const string & id_, int age_, char gender_, const string & department_)
{
	CStudent::SetInfo(name_, id_, age_, gender_); //调用基类的公有 SetInfo 函数
	department = department_; //访问的是本派生类中的成员变量
}

void CUndergraduateStudent::PrintInfo()
{
	CStudent::PrintInfo(); //调用基类的公有PrintInfo函数
	cout << "院系:\t" << department << endl << endl; //访问是本派生类的成员变量
}

class CGraduatedStudent:public CStudent  //研究生类，继承于类 CStudent
{
private:
	string department; //学生所属的系名
	string advisor; //导师
public:
	void PrintInfo();
	void SetInfo(const string & name_, const string & id_, int age_, char gender_, const string & department_, const string &advisor_);
};

void CGraduatedStudent::PrintInfo()
{
	CStudent::PrintInfo();				//调用基类的公有 PrintInfo 函数
	cout << "院系:\t" << department << endl;        //访问本派生类中的成员变量
	cout << "导师:\t" << advisor << endl << endl;	//访问本派生类中的成员变量
}


void CGraduatedStudent::SetInfo(const string & name_, const string & id_, int age_, char gender_, const string & department_, const string & advisor_)
{
	CStudent::SetInfo(name_, id_, age_, gender_); //调用基类的公有SetInfo函数
	department = department_; //访问本派生类中的成员变量
	advisor = advisor_;  //访问本派生类中的成员变量
}

int main()
{
	CStudent s1; //基类对象
	CUndergraduateStudent s2; //派生类对象
	CGraduatedStudent s3; //派生类对象
	s2.SetInfo("小张", "2018-6-2-4", 19, 'M', "数学系");
	s3.SetInfo("小李", "M2017-9", 23,'F', "计算机学院", "孟教授");
	s2.PrintInfo(); //调用派生类函数
	s3.PrintInfo(); //调用派生类函数
	//cout << s2.name << endl; //错误，不能直接访问基类的私有成员变量
	//s2.name = "张一" //错误,name 是基类中的私有成员变量
	cout << s2.GetName() << endl; //可以通过基类的公有成员函数访问
	s2.SetName("张一"); //SetName()是基类的公有成员函数
	s2.PrintInfo(); //PrintInfo()是本类的公有成员函数
	cout << s2.GetName() << "," << s2.GetId() << endl; //GetName()是基类的公有成员函数
	return 0;
};
