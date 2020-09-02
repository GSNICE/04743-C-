#include <iostream>
using namespace std;
int main()
{
    int x, count, sum = 0;
    freopen("input.dat", "r", stdin); //将标准输入重定向到文件 input.dat
    for (count = 0; count < 10; count++) //从输入流中读入10个整数进行处理
    {
        cin >> x;
        sum += x;
    }
    cout << "前10个整数的平均值" << 1.0*sum/10 << endl;
    return 0;
}
