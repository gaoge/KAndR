#include<iostream>
using namespace std;

class Node{
public:
	Node(){next=NULL;}
	int mValue;	
	Node *next;
};

class List{
public:
	List(){head = NULL;}
	int size;
	Node * head;
	void add(int value);
	void addHead(Node *node);
	void print();
	
};

void List::add(int value)
{
	Node *insert = new Node();
	insert->mValue = value;
	insert->next = NULL;
	if(head == NULL){
		head = insert;
	}else{
		Node * curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}		
		curr->next = insert;
	}
	
}

void List::addHead(Node *node)
{
	if(head == NULL){
		head = node;
	}
}

void List::print()
{
	Node * curr = head;
	while(curr != NULL)
	{
		cout<<curr->mValue<<"->";
		curr = curr->next;
	}
	cout<<endl;
	
}

//判断列表是否有环
bool isListLoop(List* list)
{
	Node *head = list->head;
	bool flag = false;
	if(!head) return flag;

	Node *low = head;
	Node * fast = head->next;

	while(low != NULL &&  fast != NULL && fast->next != NULL){
		low = low->next;
		fast = fast->next->next;
		if(low == fast){
			flag = true;
			return flag;
		}
	}

	return flag;
	
}

//找到环的入口点
Node * getLoopEntry(List *l)
{
	if(!isListLoop){
		return NULL;
	}
	else{
		Node* fast = l->head;
		Node* low = l->head;
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			low = low->next;
			if(fast == low){
				fast = l->head;
				while(fast != low)
				{
					fast = fast->next;
					low = low->next;
				}
				return fast;
			}
		}
	}
}

//构建一个有欢的链表
List * makeLoopList()
{
	Node *node1 = new Node();
	node1->mValue = 1;
	Node *node2 = new Node();
	node2->mValue = 2;
	Node *node3 = new Node();
	node3->mValue = 3;
	Node *node4 = new Node();
	node4->mValue = 4;
	Node *node5 = new Node();
	node5->mValue = 5;
	Node *node6 = new Node();
	node6->mValue = 6;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	node6->next = node3;
	
	List *l = new List();;
	l->addHead(node1);
	return l;


}

bool isCanOneLoopFind(Node *entry1,Node* entry2)
{
	bool flag = false;
	Node * startNode = entry1;
	Node *nextNode = entry1->next;

	while(nextNode != startNode){
		if(nextNode == entry2){
			flag = true;
			return flag;
		}
		nextNode = nextNode->next;
	}
	return false;
}

//判断两个无环链表是否相交
bool isTwoNoLoopInter(List* l1,List *l2)
{
	bool flag = false;
	Node* node1 = l1->head;
	Node* node2 = l2->head;
	while(node1->next != NULL) {
		//cout<<"node1->value is:"<<node1->mValue<<endl;
		node1=node1->next;
		
	}
	cout<<"isTwoNoLoopInter:node1->value is:"<<node1->mValue<<endl;
	while(node2->next != NULL) {
		//cout<<"node2->value is:"<<node2->mValue<<endl;
		node2=node2->next;
		
	}
	cout<<"isTwoNoLoopInter:node2->value is:"<<node2->mValue<<endl;

	if(node1 == node2) flag = true;
	return flag;
}



//判断两个链表是否相交
bool isTwoListIntersect(List* l1,List *l2)
{
	bool flag = false;
	//一个有环，一个无环，肯定不相交
	if( isListLoop(l1) ^ isListLoop(l2) ){
		return flag;
	}

	//两个都无环
	if(!isListLoop(l1) && !isListLoop(l2)){
		flag = isTwoNoLoopInter(l1,l2);
	}

	//两个都有环
	if(isListLoop(l1) && isListLoop(l2)){
		Node *entry1 = getLoopEntry(l1);	
		Node *entry2 = getLoopEntry(l2);
		//如果两个环入口点相同
		if(entry1 == entry2){
			flag = true;
			return flag;
		}
		//如果两个环入口点不相同
		else{
			flag = isCanOneLoopFind(entry1,entry2);
		}
	}
	return flag;
}






void testisTwoNoLoopInter()
{
	Node *node1 = new Node();
	node1->mValue = 1;
	Node *node2 = new Node();
	node2->mValue = 2;
	Node *node3 = new Node();
	node3->mValue = 3;
	Node *node4 = new Node();
	node4->mValue = 4;
	Node *node5 = new Node();
	node5->mValue = 5;
	Node *node6 = new Node();
	node6->mValue = 6;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	
	List *l1 = new List();;
	l1->addHead(node1);

	Node *node7 = new Node();
	node7->mValue = 7;
	Node *node8 = new Node();
	node8->mValue = 8;
	Node *node9 = new Node();
	node9->mValue = 9;

	node7->next = node8;
	node8->next = node9;
	
	node9->next = node3;

	List *l2 = new List();
	l2->addHead(node7);

	bool flag = isTwoNoLoopInter(l1,l2);
	cout<<"isTwoNoLoopInter(l1,l2) ?  "<<flag<<endl;

}

main(){
	
	List *l = new List();
	int a[] = {0,1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<=10;i++){
		l->add(a[i]);
	}
	///l->print();
	//cout<<"list is loop ? "<<isListLoop(l)<<endl;

	//List *loopList = makeLoopList(); 
	//cout<<"list is loop ? "<<isListLoop(loopList)<<",and the loop entry node value is: " <<getLoopEntry(loopList)->mValue<< endl;

	//testisTwoNoLoopInter();

	Node *node1 = new Node();
	node1->mValue = 1;
	Node *node2 = new Node();
	node2->mValue = 2;
	Node *node3 = new Node();
	node3->mValue = 3;
	Node *node4 = new Node();
	node4->mValue = 4;
	Node *node5 = new Node();
	node5->mValue = 5;
	Node *node6 = new Node();
	node6->mValue = 6;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	
	List *l1 = new List();;
	l1->addHead(node1);

	Node *node7 = new Node();
	node7->mValue = 7;
	Node *node8 = new Node();
	node8->mValue = 8;
	Node *node9 = new Node();
	node9->mValue = 9;

	node7->next = node8;
	node8->next = node9;
	
	node9->next = node3;

	List *l2 = new List();
	l2->addHead(node7);

	bool flag = isTwoNoLoopInter(l1,l2);
	cout<<"in main,isTwoListIntersect(l1,l2) ?  "<<isTwoListIntersect(l1,l2)<<endl;


}
