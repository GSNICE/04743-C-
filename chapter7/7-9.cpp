#include <iostream>
using namespace std;
int main()
{
    double values[] = {1.23, 20.3456, 300.4567, 4000.56789, 50000.1234567};
    cout.fill('*'); //设置填充字符为星号*
    for(int i = 0; i<sizeof(values)/sizeof(double); i++)
    {
        cout << "values[" << i << "]=(";
        cout.width(10); //设置输出宽度
        cout << values[i] << ")" << endl;
    }
    cout.fill(' '); //设置填充字符为空格
    for(int i = 0; i<sizeof(values)/sizeof(double); i++)
    {
        cout << "values[" << i << "]=(" ;
        cout.width(10); //设置输出宽度
        cout.precision(i+3);    //设置保留有效数字
        cout << values[i] << ")" << endl;
    }
    return 0;
}
