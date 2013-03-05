#include<iostream>
#include<string>
using namespace std;
class ReverseWords{
public:
	ReverseWords(string* wo):words(wo){}
	void reverse_()
	{
		int length=words->size();
		int begin=-1,end=-1;
		for(int i=0;i<length;++i){
			if(begin==-1&&words->at(i)==' ')
				continue;
			if(begin==-1)
			{
				begin=i;
				continue;
			}
			if(words->at(i)==' ')
				end=i-1;
			else if(i==length-1)
				end=i;
			else
				continue;
			reverse__(begin,end);//2.单词翻转
			begin=-1,end=-1;
		}
		reverse__(0,length-1);//1.字母翻转


	}
	private:
	void reverse__(int begin,int end)
	{
	while(begin<end)
	{
		char t=words->at(begin);
		words->at(begin)=words->at(end);
		words->at(end)=t;
		++begin;
		--end;
	}
}
	string* words;
};

int main(){
	string s="I am a student.";
	ReverseWords r(&s);
	r.reverse_();
	cout<<s<<endl;
	return 0;
}
