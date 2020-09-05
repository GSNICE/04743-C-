#include <iostream>
using namespace std;

int main()
{
    char buf[10];
    int i = 0;
    while(cin.getline(buf, 10)) //若输入流的一行超过9个字符，则会出错
        cout << ++i << ":" << buf << endl;

    cout << "last:" << buf << endl;
    return 0;
}
