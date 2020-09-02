#include<iostream>
#include<string>
using namespace std;

int main()
{
    char ch;
    int sum = 0, count = 0, x;
    cout << "请输入整数（windows控制台按Crtl+Z键, Linux Shell按Crtl+B退出）" << endl;
    do
    {
        while(cin >> x) //使用组合键结束输入
        {
            sum += x;
            count++;
        }

        cout << "确实要退出输入请按 Q";
        cin.clear(); //状态字清零，恢复流状态,可以继续输入。
        cin >> ch;
        
    }while(toupper(ch)!= 'Q');
    
    cout << "sum =" << sum << ",count=" << count << endl;
    return 0;
}
