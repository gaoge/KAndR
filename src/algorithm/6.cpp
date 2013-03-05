#include <iostream>
#define len 10
using namespace std;
class NumberTB
{
	private:
		int top[len];
		int bottom[len];
		bool success;
	public:
		NumberTB();
		int* getBottom();
		void setNextBottom();
		int getFrequecy(int num);
};

NumberTB::NumberTB()
{
	success = false;
	//format top
	for(int i=0;i<len;i++)
	{
		top[i] = i;
	}
	for(int i=0;i<len;i++)
	{
		bottom[i] = 0;
	}
}
int* NumberTB::getBottom()
{
		int i=0;
		while(!success)
		{	i++;
			setNextBottom();
			
		}
	cout<<"loop "<<i<<" times to get the success result"<<endl;
	return bottom;
}
//set next bottom
void NumberTB::setNextBottom()
{
	bool reB = true;
	for(int i=0;i<len;i++)
	{
		int frequecy = getFrequecy(i);
		cout<<"i is: "<<i<<" frequecy is: "<<frequecy<<endl;
		if(bottom[i] != frequecy)
		{
			cout<<"bottom[i] != frequecy,so we set the frequecy value "<<frequecy<<" to bootom["<<i<<"]"<<endl;
			bottom[i] = frequecy;
			cout<<"now,bootom["<<i<<"] is: "<<bottom[i]<<endl;
			cout<<"*************************************************"<<endl;
			reB = false;
			//break;
		}
	}
	success = reB;
}
//get frequency in bottom
int NumberTB::getFrequecy(int num)
{
	//此处的 num 即指上排的数 i
	int count = 0;
	for(int i=0;i<len;i++)
	{
		if(bottom[i] == num)
		count++;
	}
	return count;
	//cout 即对应 frequecy
}

int main()
{
	NumberTB nTB;
	int* result= nTB.getBottom();
	for(int i=0;i<len;i++)
	{
		cout<<*result++<<endl;
	}
	return 0;
}
