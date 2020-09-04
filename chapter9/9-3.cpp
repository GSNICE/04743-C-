#include <iostream>
using namespace std;

template<typename T>
int myCompare(const T& left, const T& right)
{
    if(left < right)
    {
        return -1;
    }
    else if(right < left)
    {
        return 1;
    }
    else return 0;
}

template<class T> //类类型T
void swap(T &x, T &y)//可以交换类对象
{
    T tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    string arraystring[10] = {"shang", "xia", "zuo", "you", "qian", "hou", "dong", "xi", "nan", "bei"};
    int j;
    string temp;
    for(int i = 1; i < 10; i++)
    {
        j = i;
        while(j > 0 && myCompare<string>(arraystring[j-1],arraystring[j]) > 0)
        {
            swap(arraystring[j], arraystring[j-1]);
            j--;
        }
    }
    for(int i = 0; i < 10; i++)
        cout << arraystring[i] << ",";
}
