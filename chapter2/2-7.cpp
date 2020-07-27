#include <iostream>
#include <string>
using namespace std;
class CEmployee
{
private:
		string szName; //姓名
		int salary; 	//工资
public:
		void setName(string); //设置姓名
		string getName(); //获取姓名
		void setSalary(int); //设置工资
		int getSalary();	//获取工资
		int averageSalary(CEmployee); //计算两人的平均工资
}; 

void CEmployee::setName(string name)
{
		szName = name;
}

string CEmployee::getName()
{
		return szName;
}
void CEmployee::setSalary(int mon)
{
		salary = mon;
}
int CEmployee::getSalary()
{
		return salary;
}
int CEmployee::averageSalary(CEmployee e1)
{
		return(salary + e1.getSalary()/2);
}
int main()
{
		CEmployee eT, eY;
		//eT.szName = "Tom1234567"; //编译错误，不能直接访问私有成员。
		eT.setName("Tom1234567"); 	//需要公有的成员函数访问
		//eT.salary = 5000;	
		eT.setSalary(5000);       //需要通过公有成员函数访问
		cout << eT.getName()<<endl;	
		eY.setName("Yong7654321");
		eY.setSalary(3500);
		cout <<eY.getName()<<endl;
		cout <<"aver="<<eT.averageSalary(eY)<<endl; //输出 aver = 4250
		return 0;
}









