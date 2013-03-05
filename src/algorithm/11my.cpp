#include<iostream>
using namespace std;

class Node{
public:
	Node(int val);
	int mValue;
	int maxLeft;
	int maxRight;
	Node* left;
	Node* right;
};

	Node::Node(int val){
	mValue = val;
	left = NULL;
	right = NULL;
	maxLeft = 0;
	maxRight = 0;
}

class NodeTree{
public:
	NodeTree();

	void addNode(Node *& no,Node *node);
	void printFrontNode(Node *no);
	Node *head;
	int maxLevel;
	int curLevel;
	void calcuMaxLevel(Node *node);
	int getMaxLevel();
	int maxDis;
	int getMaxDis(Node *node);
};

	NodeTree::NodeTree(){
	head = NULL;
	maxLevel = 0;
	curLevel = 0;
	maxDis = 0;
}

//找到两点间的最大距离
int NodeTree::getMaxDis(Node *node)
{
	if(node->left == NULL) node->maxLeft = 0;
	if(node ->right == NULL) node->maxRight = 0;
	if(node->left != NULL) getMaxDis(node->left);
	if(node->right != NULL) getMaxDis(node->right);

	if(node->left != NULL){
		if(node->left->maxLeft > node->left->maxRight){
			node->maxLeft = node->left->maxLeft+1;
		}else{
			node->maxLeft = node->left->maxRight + 1;
		}
	}
	if(node->right != NULL){
		if(node->right->maxLeft > node->right->maxRight){
			node->maxRight = node->right->maxLeft + 1;
		}else{
			node->maxRight = node->right->maxRight + 1;
		}
	}
	if(node->maxLeft + node->maxRight > maxDis) maxDis = node->maxLeft + node->maxRight;
	
}
//添加节点
void NodeTree::addNode(Node *& no,Node *node){
	if(NULL == no){
		no = node;
	}
	else{
		if(node->mValue < no->mValue) addNode(no->left,node);
		else addNode(no->right,node);
	}
}

//先根打印
void NodeTree::printFrontNode(Node *no){
	cout<<no->mValue<<"-";
	if(no->left != NULL) printFrontNode(no->left);
	if(no->right != NULL) printFrontNode(no->right);
}

//计算二叉树最深层次
void NodeTree::calcuMaxLevel(Node *node){
	curLevel++;
	if(curLevel > maxLevel) maxLevel = curLevel;
	if(node->left != NULL){
		calcuMaxLevel(node->left);
	}
	if(node->right != NULL){
		calcuMaxLevel(node->right);
	}
	curLevel--;
	
}
//返回最深层次
int NodeTree::getMaxLevel(){
	calcuMaxLevel(head);
	return maxLevel;
}


main(){
	int a[] = {8,7,9,5,10,6,3,14,2,1};
	NodeTree *nodeTree= new NodeTree();
	
	for(int i=0;i<10;i++)
	{
		Node *node = new Node(a[i]);
		nodeTree->addNode(nodeTree->head,node);
		
	}
	nodeTree->printFrontNode(nodeTree->head);
	
	cout<<endl;
	cout<<"The Tree max level is: " <<nodeTree->getMaxLevel()<<endl;
	nodeTree->getMaxDis(nodeTree->head);
	cout<<"The Tree max distance is: " <<nodeTree->maxDis<<endl;
}
