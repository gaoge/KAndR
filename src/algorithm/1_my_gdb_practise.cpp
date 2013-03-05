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

//遍历打印二叉树
void printNodeTree(TreeNode * node)
{
	if(NULL != node->left){
		printNodeTree(node->left);
	}
	std::cout<<node->value<<std::endl;
	if(NULL != node->right){
		printNodeTree(node->right);
	}
}

//将二叉树转换成双向链表
void convertToList(TreeNode * node)
{
	if(NULL == node) return;
	if(NULL != node->left)
	{
		addNodeToList(node->left);
	}
	addNodeToList(node);
	if(NULL != node->right)
	{
		addNodeToList(node->right);	
	}
	
}


main()
{
	addNode(mRoot,10);
	addNode(mRoot,4);
	addNode(mRoot,6);
	addNode(mRoot,8);
	addNode(mRoot,12);
	addNode(mRoot,14);
	addNode(mRoot,15);
	addNode(mRoot,16);
	
	convertToList(mRoot);
	//printNodeTree(mRoot);
}
