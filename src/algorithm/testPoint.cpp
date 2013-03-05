#include<iostream>

using namespace std;


void max1(int a)
{
	a = 1;
}
void max2(int &a)
{
	a = 2;
}

void max3(int *a)
{
	*a = 3;
}

void max4(int *&a)
{
	*a = 3;
}


main()
{
	int var = 0;
	//max2(var);
	//max3(&var);
	int *ptr = &var;
	//max3(ptr);
	max4(ptr);
	cout<<"var is: "<<var<<endl;
}
