#include<iostream>
using namespace std;
struct ListNode
{
  int m_nKey;
  ListNode* m_pNext;
};

ListNode* head;


ListNode *getReverseKNode(int k)
{
	ListNode *index = head;
	int length = 1;
	while(index->m_pNext != NULL){
		index = index->m_pNext;
		length++;	
	}
	if(k>length) return NULL;
	int m = length-k;
	index = head;
	for(int i=0;i<m;i++){
		index = index->m_pNext;
	}
	return index;
}

void addNode(int key)
{
	ListNode *node = new ListNode();
	node->m_pNext = NULL;
	node->m_nKey = key;
	if(head == NULL){
		head = node;
	}else{
		ListNode *index = head;
		while(index->m_pNext != NULL) index = index->m_pNext;
		index->m_pNext = node;
	}
	
}
void printList()
{
	ListNode *index = head;
	while(index != NULL){
		cout<<index->m_nKey<<"-";
		index = index->m_pNext;
	}
	cout<<endl;
}

main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	for(int i=0;i<8;i++){
		addNode(a[i]);
	}
	printList();
	int k=5;
	ListNode * result = getReverseKNode(k);
	cout<<"k is: "<<k<<",value is: "<<result->m_nKey<<endl;
	
}
