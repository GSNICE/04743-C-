#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string Months[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; //西文格式月份

int main()
{
    char ch;
    int year, month, day;
    while((ch=cin.peek())!=EOF) //取输入流的第一个字符查看
    {
        if(ch>='A' && ch<'Z')
        {
            string sMonth;
            cin >> sMonth >> day >> year; //接收: 月、日、年
            //查找月份完整转换
            for(month=0; month<12 && sMonth!=Months[month]; ++month){}
        }
        else{
            cin >> year; //中文格式
            cin.ignore() >> month; 
            cin.ignore() >> day;
        }            
        cin.ignore();
        cout << setfill('0') << setw(2) << month;
        cout << "-" << setw(2) << day << "-" << setw(4) << year << endl;
    }
    return 0;
}
