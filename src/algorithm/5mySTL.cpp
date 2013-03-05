#include<iostream>
#include<set>
#include<vector>

using namespace std;
typedef multiset<int,greater<int> > maxHeap;

void findLeastNumbers(vector<int> &data,maxHeap & leastNum,int k)
{
	vector<int>::iterator iter = data.begin();
	leastNum.clear();

	if(k == 0 || data.size() <0) return;

	for(;iter != data.end();iter++){
		if(k > leastNum.size()){
			leastNum.insert(*iter);
		}else{
			maxHeap::iterator iter2 = leastNum.begin();
			if(*iter < *iter2)
			{
				leastNum.erase(iter2);
				leastNum.insert(*iter);
			}
		}
	}

}

void display(maxHeap & leastNum)
{
	maxHeap::iterator iter2 = leastNum.begin();
	for(;iter2 != leastNum.end();iter2++)
	{
		cout<<*iter2<<" ";
		cout<<endl;
	}
}

main()
{
	maxHeap leastNum;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	findLeastNumbers(v,leastNum,4);
	display(leastNum);
}


