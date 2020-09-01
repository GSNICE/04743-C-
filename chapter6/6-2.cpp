#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	void put_name(string s)
	{
		name = s;
	}
	virtual void print_name()const
	{
		cout << "A::" << name << "\n";
	}
	string name;
};

class B:public A
{
public:
	void put_name(string s)
	{
		put_name(s);
	}
	virtual void print_name()const
	{
		cout << "B::" << name << "," << A::name << "\n";
	}
	void put_phone(string num)
	{
		phone_num = num;
	}
	void print_phone()const
	{
		cout << phone_num << "\n";
	}
	
	string phone_num; //派生类中的成员变量
};

int main()
{
	A *A_p;
	A A_obj;
	B B_obj;
	A_p = &A_obj; //基类指针指向基类对象
	A_p->put_name("多态示例_名字"); 
	cout << "A_p->put_name()的输出内容:\t";
	A_p->print_name();			//使用指针输出	
	cout << "A_obj.print_name()的输出内容:\t";
	A_obj.print_name(); 			//使用对象输出

	A_p = &B_obj; //基类指针指向派生类对象
	A_p->put_name("另一个名字"); //多态，赋给派生类对象
	cout << "A_obj->print_name()的输出内容:\t";
	A_p->print_name();
	cout << "B_obj->print_name()的输出内容:\t";
	B_obj.print_name(); 
	B_obj.put_phone("电话号码999");

	cout <<"((B*)A_p)->print_phone()的输出内容跟:\t";
	((B*)A_p)->print_phone(); //强制转换基类指针,输出的是派生类中对象的值
	cout << "B_obj.print_phone()的输出内容:\t\t";
	B_obj.print_phone(); //输出的是派生类中对象的值
	return 0;
}




