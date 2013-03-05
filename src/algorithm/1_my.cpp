#include<iostream>

struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int value;
};

TreeNode * mRoot = NULL;
typedef TreeNode DoubleList;
DoubleList * head = NULL;
DoubleList * curListIndex = NULL;


//TreeNode * head = NULL;
//TheeNode * curListIndex = NULL;

//构建二叉树
void addNode(TreeNode *& node ,int valueP)
{
	if(NULL == node){
		TreeNode * newNode = new TreeNode();
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->value = valueP;
		node = newNode;
	}
	else{
		if(valueP < node->value)
		{
			addNode(node->left,valueP);
		}
		else if(valueP > node->value)
		{
			addNode(node->right,valueP);
		}
	}	
}

//向链表中添加节点
void addNodeToList(TreeNode * node)
{
	node->left = curListIndex;
	if(curListIndex == NULL)
	{
		head = node;
	}
	else
	{
		curListIndex->right = node;
	}
	curListIndex = node;
	std::cout<<node->value<<std::endl;
}

//中序遍历，也叫中根遍历，顺序是 左子树，根，右子树 
void printNodeTreeMiddle(TreeNode * node)
{
	if(NULL != node->left){
		printNodeTreeMiddle(node->left);
	}
	std::cout<<node->value<<"=";
	if(NULL != node->right){
		printNodeTreeMiddle(node->right);
	}
}

//前序遍历，也叫先根遍历，遍历的顺序是，根，左子树，右子树 
void printNodeTreeFront(TreeNode * node)
{
	std::cout<<node->value<<"=";
	if(NULL != node->left){
		printNodeTreeFront(node->left);
	}
	
	if(NULL != node->right){
		printNodeTreeFront(node->right);
	}
}

//后序遍历，也叫后根遍历，遍历顺序，左子树，右子树，根 
void printNodeTreeBack(TreeNode * node)
{
	if(NULL != node->left){
		printNodeTreeBack(node->left);
	}
	if(NULL != node->right){
		printNodeTreeBack(node->right);
	}
	std::cout<<node->value<<"=";
	
}

//将二叉树转换成双向链表
void convertToList(TreeNode * node)
{
	if(NULL == node) return;
	if(NULL != node->left)
	{
		convertToList(node->left);
	}
	addNodeToList(node);
	if(NULL != node->right)
	{
		convertToList(node->right);	
	}
	
}


main()
{
	addNode(mRoot,10);
	addNode(mRoot,6);
	addNode(mRoot,4);
	
	addNode(mRoot,8);
	addNode(mRoot,14);
	addNode(mRoot,12);
	
	//addNode(mRoot,15);
	addNode(mRoot,16);
	printNodeTreeFront(mRoot);
	std::cout<<std::endl;
	printNodeTreeMiddle(mRoot);
	std::cout<<std::endl;
	printNodeTreeBack(mRoot);
	//std::cout<<"aaaaaaa"<<std::endl;
	convertToList(mRoot);
	//printNodeTree(mRoot);
}
