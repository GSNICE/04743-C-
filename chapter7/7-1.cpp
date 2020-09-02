#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >>y;
    freopen("test.txt", "w", stdout); //将标准输出重定向到文件 test.txt
    if (y == 0)
        cerr << "error." << endl;
    else
        cout << x << "/" << y << "=" << x/y << endl;
    return 0;
}
