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
    int count = 0, nbyte = 0;
    ifstream inFile("students.dat", ios::in|ios::binary); //以二进制读方式打开
    if (!inFile) 
    {
        cout << "打开文件失败" << endl;
        return 0;
    }
    cout << "学生学号 姓名\t\t\t 成绩\n" ;
    while(inFile.read((char*)&stu, sizeof(stu)))
    {
        cout << left << setw(10) << stu.id << " " << setw(20) << stu.name << " "<< setw(3) << right << stu.score << endl;
        count++;
        nbyte+=inFile.gcount(); //得到本次read读取的字节数量
    }
    cout << "共有记录数:" << count << ", 字节数:" << nbyte << endl;
    inFile.close();
    return 0;
}
