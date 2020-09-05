#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Pair
{
public:
    T1 first; //第一个值
    T2 second; //第二个值
    Pair(T1 k, T2 v):first(k),second(v){}
    bool operator<(const Pair<T1, T2>&p)const //Pair的成员函数operator<
    {
        //比较第一个成员变量的大小
        return first < p.first;
    }
};

int main()
{
    Pair<string, int>student1("Tom", 19);
    //实例化一个类Pair<string, int>,同时声明一个对象student1
    Pair<string, int>student2("jim", 21);
    //实例化一个类Pair<string,int>,同时声明一个对象student2
    Pair<string, string>dic("word", "单词"); //实例化一个字典项
    cout << "学生：" << student1.first << " " << student1.second << endl;
    cout << "学生：" << student2.first << " " << student2.second << endl;
    cout << "字典项：" << dic.first << " " << dic.second << endl;
    bool a = student1 < student2;
    if(a == 0) cout << student1.first << "位于" << student2.first << "之后" << endl;
    else cout << student1.first << "位于" << student2.first << "之前" << endl;
    return 0;
}
