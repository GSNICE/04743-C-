#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x = 12.34;
	cout << x << endl;
	cout << "1)" << setiosflags(ios::scientific|ios::showpos) << x << endl;
	cout << "2)" << resetiosflags(ios::scientific|ios::showpos) << setiosflags(ios::fixed) << x << endl;
	cout << "3)" << resetiosflags(ios::fixed) 
		<< setiosflags(ios::scientific|ios::showpos) << x << endl;
	cout << "4)" << resetiosflags(ios::showpos) << x << endl; //清除要输出的正号标志
	return 0;
}
