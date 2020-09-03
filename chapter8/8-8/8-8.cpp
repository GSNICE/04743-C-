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
    char ch;
    cout << "确实要向文件中追加新的数据吗(Y/N)?" << endl;
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        CStudent stu;
        ofstream outFile("students.dat",ios::app|ios::binary);
        if(!outFile)
        {
            cout << "以追加的方式打开文件失败" << endl;
            return 0;
        }
        cout << "请输入: 学号 姓名 成绩 (以 Ctrl+Z 结束输入)\n";
        while(cin >> stu.id >> stu.name >> stu.score)
            outFile.write((char*)&stu, sizeof(stu)); //向文件中写入数据
        outFile.close(); //关闭文件
    }
    return 0;
}
