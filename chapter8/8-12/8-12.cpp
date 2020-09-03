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
    int count = 0, maxScore, minScore, maxNo, minNo;
    maxScore = INT32_MIN;
    minScore = INT32_MAX;
    maxNo = minNo = 0;
    ifstream inFile("students.dat", ios::in|ios::binary);//以二进制形式打开
    if(!inFile)
    {
        cout << "打开文件失败" << endl;
        return 0;
    }
    while(inFile.read((char*)&stu, sizeof(CStudent))) //顺序读取文件中的记录
    {
        if(stu.score > maxScore) //查找最高分
        {
            maxScore = stu.score; //记录当前最高分
            maxNo = count; //记录当前最高分记录号
        }
        else if(stu.score < minScore) //查找最低分学生
        {
            minScore = stu.score;
            minNo = count;
        }
        count++;
    }
    inFile.clear(); //将流恢复为正常状态
    inFile.seekg(sizeof(CStudent)*maxNo, ios::beg); //文件指针移动到最高分记录
    inFile.read((char*)&stu, sizeof(CStudent)); //读入最高分记录
    cout << "最高分记录:"
        << maxNo << ":" << stu.id << "," << stu.name << "," << stu.score << endl;
    
    inFile.seekg(sizeof(CStudent)*minNo, ios::beg); //文件指针移动到最低分记录
    inFile.read((char*)&stu, sizeof(CStudent)); //读入低分记录
    cout << "最低分记录:"
        << minNo << ":" << stu.id << "," << stu.name << "," << stu.score << endl;
    inFile.close();
    return 0;
}
