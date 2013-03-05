#include<iostream>
using namespace std;

bool isBackOrderTree(int a[],int length)
{
	int root = a[length-1];
	if(length == 1) return true;

	int index = 0;
	for(;a[index]<root;index++);

	int j = index;
	for(;j<length-1;j++){
		if(a[j]<root) return false;
	}
	
	//left tree node value array
	//a[],index
	bool leftIsTreeNode = isBackOrderTree(a,index);
	//rigth tree node value array
	//a+index,length-1-index
	bool rightIsTreeNode = isBackOrderTree(a+index,length-1-index);

	return leftIsTreeNode && rightIsTreeNode;
}

main()
{
	int a[] = {5,7,6,9,11,10,8};
	int b[] = {7,4,6,5};
	bool flag = isBackOrderTree(a,7);
	//bool flag = isBackOrderTree(b,4);
	cout<<"flag is: " <<flag<<endl;
}
