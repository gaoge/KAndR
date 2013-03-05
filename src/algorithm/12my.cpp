#include<iostream>
using namespace std;

class Temp{
public:
	Temp(){
		n++;	
		sum += n;
	}
	
	static int getSum(){return sum;}

private:
	static int n;
	static int sum;

};
int Temp::n = 0;
int Temp::sum = 0;

int calcuSum(int n)
{
	Temp *tmp = new Temp[n];
	return Temp::getSum();
}
main()
{
	cout<<"the sum is: "<<calcuSum(100)<<endl;	
	
}
