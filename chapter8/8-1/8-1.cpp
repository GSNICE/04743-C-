#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("./test.txt",ios::in); //以读的方式打开文件
    if(inFile) //打开成功inFile的值为true
    {
        cout << "成功打开文件: ./test.txt" << endl;
        inFile.clear();
    }
    else
        cout << "文件打开失败" << endl;

    ofstream outFile; 
    outFile.open("./test1.txt", ios::out); // 以写的方式打开文件
    if(!outFile)
        cout << "error1" << endl;
    else
    {
        cout << "成功打开文件: test1.txt\n" ;
        outFile.clear();
    }

    outFile.open("./test2.txt", ios::out|ios::in); //以读写的方式打开文件
    if(outFile)
    {
        cout << "成功打开文件: test2.txt" << endl;
        outFile.close();
    }
    else
        cout << "error2" << endl;

    fstream ioFile;
    ioFile.open("./test3.txt", ios::in|ios::out|ios::trunc); //以读写的方式创建文件
    if(!ioFile)
        cout << "error3" << endl;
    else
    {
        cout << "成功打开文件./test3.txt" << endl;
        ioFile.close();
    }
    return 0;
}
