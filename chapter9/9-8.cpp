#include <iostream>
#include <string>
using namespace std;
template<class T1, class T2>
class Pair
{
public:
	T1 first; //关键字
	T2 second; //值
	Pair(T1 k, T2 v):first(k),second(v){}
	bool operator<(const Pair<T1,T2>&p)const;
	template<class T> //成员函数模板
	void print(T x)
	{
		cout << x << endl;
	}
};

template<class T1, class T2> //在类模板外定义成员函数
bool Pair<T1,T2>::operator<(const Pair<T1,T2> &p)const //Pair 的成员函数
{
	//仅比较第一个数值的大小
	return first < p.first;	
}

int main()
{
	Pair<string, int> student1("Tom", 19);
	//实例化一个类Pair<string,int>，同事声明一个对象 student1
	Pair<string, int> student2("Jim", 21);
	
	Pair<int,int>coordinate(10,20); //实例化一个点的左边(10,20)
	Pair<string,string>dic("word","单词"); //实例化一个字典项
	cout << "学生" << student1.first << " " << student1.second << endl;
	cout << "学生" << student2.first << " " << student2.second << endl;
	cout << "坐标:" << coordinate.first << " " << coordinate.second << endl;
	cout << "字典项:" << dic.first << " " << dic.second << endl;
	bool a = student1 < student2;
	if(a == 0) cout << student1.first << "位于" << student2.first << "之后" << endl;
	else cout << student1.first << "位于" << student2.first << "之前" << endl;
	student1.print<string>(student1.first); //调用函数模板 print
	coordinate.print<int>(coordinate.first);
	return 0;
}

