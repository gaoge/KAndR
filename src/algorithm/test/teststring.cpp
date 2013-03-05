#include<iostream>
#include<string>
using namespace std;

void test(string* str)
{
}

void testIntPoi(int *a)
{
}
void testInt(int a)
{
}

main()
{
	string str = "I'm a student.";
	test(&str);
	int i =9;
	testInt(&i);
	testIntPoi(&i);
	//char ch = {'a','b','c'};
	cout<<str<<endl<<str[3]<<endl;
}
