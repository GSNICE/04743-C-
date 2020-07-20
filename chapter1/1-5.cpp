#include <iostream>
using namespace std;
int main()
{
	const int cInt = 30;
	int oneInt = 50;
	int & ref = oneInt;	
	const int & rc1 = cInt;	//T& <- T 
	const int & rc2 = oneInt; //CT& <- CT, CT&表示类型T的常用
	const int & rc3 = ref; //CT&< <- T&

	int dInt = ref; //T <- T&
	int eInt = cInt;//T <- CT
	int fInt = rc1; //T <- CT&
	const int gInt = oneInt;

	const int hInt = ref;
	const int jInt = cInt;
	const int mInt = rc1;
	const int nInt = rc2;
	
	cout<<"OK"<<endl;
	int&r2=(int&)rc1;
	int&r3=(int&)cInt;

	return 0;	
}


	
	
		

