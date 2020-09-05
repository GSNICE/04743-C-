#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class CStudent
{
public:
    char id[11]; 
    char name[21];
    int score;
};

int main()
{
    CStudent stu;
    int count = 0,nbyte = 0;
    ifstream inFile("students.dat", ios::in|ios::binary); //以二进制写方式打开文件
    if(!inFile) //条件成立，则说明文件打开出错。
    {
        cout << "创建文件失败" << endl;
        return 0;
    }
    else
    {
        cout << "打开文件时位置指针:" << inFile.tellg() << endl;
        cout << "   每个记录大小:" << sizeof(CStudent) << endl;
    }
    cout << "学生学号   姓名\t\t\t 成绩\t 流指针\n";
    while(inFile.read((char*)&stu, sizeof(CStudent)))// 读取一个记录
    {
        cout << left << setw(10) << stu.id << " " 
            << setw(20) << stu.name << " " << setw(3) << right << stu.score << "\t" << inFile.tellg() << endl; 
        count++;
        nbyte += inFile.gcount();
    }
    cout << "读取文件结束时位置指针:" << inFile.tellg() << endl;
    cout << "共有记录数:" << count << ",字节数" << nbyte << endl;
    inFile.clear(); //将流恢复为正常状态。必不可少
    inFile.seekg(0); //将文件读指针移动到文件起始位置
    cout << "位置指针" << inFile.tellg() << endl;
    inFile.read((char*)&stu, sizeof(stu));
    cout << left << setw(10) << stu.id << " " << setw(20) << stu.name << " " << setw(3) << right << stu.score << endl;
    inFile.seekg(0, ios::end); //将文件指针移动到最后位置
    cout << "位置指针" << inFile.tellg() << endl;
    inFile.close();
    return 0;
}
