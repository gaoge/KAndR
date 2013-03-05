#include<iostream>
#include<string>

using namespace std;

void reverseChar(string *sentence,int begin,int end)
{
	char tmp;
	while(begin < end){
		tmp = sentence->at(begin);
		sentence->at(begin) = sentence->at(end);
		sentence->at(end) = tmp;
		begin++;
		end--;
	}
}

//字符反转
void reverseWholeSentenceChar(string *sentence)
{
	int size = sentence->size();
	reverseChar(sentence,0,size-1);
}

//单词反转
void reverseWord(string *sentence)
{
	int size = sentence->size();
	int begin = -1;
	int end = -1;
	for(int i=0;i<size;i++){
		if(begin == -1){
			begin = i;
		}
		if(sentence->at(i) == ' ' || i==size-1){
			if(i==size -1) end = i;
			else end = i-1;
			reverseChar(sentence,begin,end);
			begin = -1;
			end = -1;
		}
		
	}
}



main()
{
	string s = "You are a student.    ";
	cout<<"before reverse : "<<s<<endl; 
	reverseWholeSentenceChar(&s);
	reverseWord(&s);
	cout<<"after reverse : "<<s<<endl;
}
