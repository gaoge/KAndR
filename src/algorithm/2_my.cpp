#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

template<typename T>
class MinStack{
public:
vector<T> datas;
vector<size_t> minVector;

void push(T value){
	datas.push_back(value);
	if(minVector.empty() || value <= datas[minVector[minVector.size()-1]])
	{
		minVector.push_back(datas.size() -1 );
	}
	
}

void pop(){
	assert(!datas.empty());
	if(datas.back() == datas[minVector[minVector.size()-1]]){
		minVector.pop_back();
	}
	datas.pop_back();
}

T min(){
	assert(!datas.empty());
	return datas[minVector[minVector.size()-1]];
}

void display(){
	cout<<"datas = ";
	for(int i=0;i<datas.size();i++){
		cout<<datas[i]<<" ";
	}
	cout<<endl;
	cout<<"minVector = ";
	for(int i=0;i<minVector.size();i++){
		cout<<minVector[i]<<" ";
	}
	cout<<endl;
	cout<<"min is: "<<min()<<endl;
	
}

};


main()
{
	MinStack<int> s;
	s.push(9);
	s.push(10);
	s.push(8);
	s.push(7);
	s.push(7);
	s.pop();
	s.display();
}
