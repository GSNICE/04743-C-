#include <iostream>
#include <fstream>
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
    ofstream outFile("students.dat", ios::out|ios::binary); //以二进制写方式打开文件
    if(!outFile) //条件成立，则说明文件打开出错。
    {
        cout << "创建文件失败" << endl;
        return 0;
    }
    cout << "请输入: 学号 姓名 成绩(以Ctrl+Z结束输入)\n";
    while(cin >> stu.id >> stu.name >> stu.score)
        outFile.write((char*)&stu, sizeof(stu)); //向文件中写入数据

    outFile.close(); //关闭文件
    return 0;
}
