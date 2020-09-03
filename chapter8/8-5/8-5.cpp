#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    char ch,filename[20];
    int count = 0;
    bool newline = true;
    cout << "请输入文件名:";
    cin >> filename;
    ifstream inFile(filename,ios::in); //以读方式打开文本文件
    if(!inFile)
    {
        cout << "打开文件失败" << endl;
        return 0;
    }
    while((ch = inFile.get()) != EOF)
    {
        if(newline)
        {
            cout << setw(4) << ++count << ':';
            newline = false; //清除新行标志
        }
        if(ch =='\n')
            newline = true;
        cout << ch;
    }
    inFile.close(); //关闭文件
    return 0;
}
