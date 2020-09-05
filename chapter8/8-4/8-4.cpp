#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    char id[11],name[21];
    int score;
    ifstream inFile;
    inFile.open("score.txt", ios::in); //以读的方式打开文件
    if(!inFile)
    {
        cout << "打开文件失败" << endl;
        return 0;
    }
    cout << "学生学号    姓名\t\t\t 成绩\n";
    while(inFile >> id >> name >> score) //读入文件
        cout << left << setw(10) << id << " " << setw(20) << name << " " << setw(3) << right << score << endl;
    inFile.close();
}
