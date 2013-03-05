#include<iostream>
using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	int mValue;
	Node(int value);
};

Node::Node(int value){
	mValue = value;
}

class NodeTree{
public:
	Node* head;
	void addNode(Node *&no,Node *node);
	void print(Node *node);
	NodeTree();
};

NodeTree::NodeTree(){
	head = NULL;
}

void NodeTree::addNode(Node *&no,Node *node){
	if(NULL == no){
		no = node;
	}else if(node->mValue < no->mValue){
		addNode(no->left,node);
	}else if(node->mValue > no->mValue){
		addNode(no->right,node);
	}
}

void NodeTree::print(Node *node){
	cout<<node->mValue<<"-";
	if(NULL != node->left) print(node->left);
	if(NULL != node->right) print(node->right);
}

//生成镜像二叉树
main()
{
	NodeTree * nodeTree = new NodeTree();
	int a[] = {8,6,10,5,7,9,11};
	for(int i=0;i<7;i++){
		Node *node = new Node(a[i]);
		nodeTree->addNode(nodeTree->head,node);
	}
	nodeTree->print(nodeTree->head);
	cout<<endl;
}
