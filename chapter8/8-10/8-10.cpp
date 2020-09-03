#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        cout << "使用方法错误。正确使用命令的格式: mycopy SourceFile NewFile" << endl;
        return 0;
    }
    ifstream inFile(argv[1], ios::binary|ios::in); //以二进制读模式打开文件
    if(!inFile)
    {
        cout << "Source file open error." << endl;
        return 0;
    }
    ofstream outFile(argv[2],ios::binary|ios::out); //以二进制写模式打开文件
    if(!outFile)
    {
        cout << "dest file open error." << endl;
        return 0;
    }
    char c;
    while(inFile.get(c)) //每次读取一个字符，文件结束时退出循环
        outFile.put(c);//每次写入一个字符
    outFile.close();
    inFile.close();
    return 0;
}
