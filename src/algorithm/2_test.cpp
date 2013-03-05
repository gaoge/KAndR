#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename T>
class StackSuppliedMin{
public:
vector<T> datas;
vector<size_t> minStack;

void push(T data){
   datas.push_back(data);
   if (minStack.empty() || data < datas[minStack.back()])
    minStack.push_back(datas.size()-1);
}

void pop(){
   assert(!datas.empty());
   if (datas.back() == datas[minStack.back()])
    minStack.pop_back();
   datas.pop_back();
}

T min(){
   assert(!datas.empty() && !minStack.empty());
   return datas[minStack.back()];
}

void display();
};

template<typename T>
void StackSuppliedMin<T>::display(){
cout << "datas = ";
for (int i = 0; i < datas.size(); i ++)
   cout << datas[i] << " ";
cout << endl;
cout << "minStack = ";
for (int i = 0; i < minStack.size(); i ++)
   cout << datas[minStack[i]] << " ";
cout << endl;
cout << "min = " << datas[minStack.back()] << endl << endl;
}

main(){
StackSuppliedMin<int> s;
s.push(9);
	s.push(10);
	s.push(8);
	s.push(7);
	s.push(7);
	s.pop();
	s.display();
}
