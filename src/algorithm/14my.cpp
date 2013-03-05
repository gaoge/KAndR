#include<iostream>
using namespace std;
void getTwoValue(int *arr,int len,int & num1,int & num2,int sum)
{
	int begin = 0;
	int end = len-1;
	bool found = false;
	while(!found){
		int curSum = arr[begin] + arr[end];
		if(curSum == sum){
			num1 = arr[begin];
			num2 = arr[end];
			found = true;
		}else if(curSum >sum) end--;
		else if(curSum<sum) begin++;
		if(begin == end){
			num1 = -1;
			num2 = -1;
			break;
		}
	}
}
main()
{
	int a[] = {1,2,4,7,11,15};
	int sum = 36;
	int num1 =0;
	int num2 = 0;
	getTwoValue(a,6,num1,num2,sum);
	cout<<"num1 is: "<<num1 <<",num2 is: "<<num2<<endl;
	
}
