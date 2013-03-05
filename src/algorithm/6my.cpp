#include<iostream>
#define len 10

using namespace std;

int top[len] = {0,1,42,23,4,45,6,17,78,99};
int bottom[len] = {0,0,0,0,0,0,0,0,0,0};
bool success = false;

int getFrequence(int topValue)
{
	int count = 0;
	for(int i=0;i<len;i++){
		if(bottom[i] == topValue) count++;
	}
	return count;
}
void makeBottom()
{
	success = true;
	for(int i=0;i<len;i++){
		int frequnce = getFrequence(top[i]);
		if(bottom[i] != frequnce){
			bottom[i] = frequnce;
			success = false;
		}
	}
}

void display()
{
	for(int i=0;i<len;i++){
		cout<<bottom[i]<<"-";
		
	}
	cout<<endl;
}

main()
{
	while(!success){
		makeBottom();
	}
	display();
	
}
