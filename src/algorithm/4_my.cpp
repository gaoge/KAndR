#include<iostream>
#include<vector>
#include<cassert>

struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int value;
};
TreeNode * mRoot = NULL;

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



//中序遍历，也叫中根遍历，顺序是 左子树，根，右子树 
void printNodeTreeMiddle(TreeNode * node)
{
	if(NULL != node->left){
		printNodeTreeMiddle(node->left);
	}
	std::cout<<node->value<<"-";
	if(NULL != node->right){
		printNodeTreeMiddle(node->right);
	}
}

//查找所有路径
void findPath(TreeNode *treeNode,int expectedSum,std::vector<int> & path,int &currentSum){
	assert(treeNode);
	currentSum += treeNode->value;
	path.push_back(treeNode->value);

	bool isLeaf = (!treeNode->left && !treeNode->right);
	if(isLeaf && currentSum == expectedSum){
		std::vector<int>::iterator iter = path.begin();
		for(;iter != path.end();iter++){
			std::cout<<*iter<<"-";
		}
			std::cout<<std::endl;
	}
	if(treeNode->left){
		findPath(treeNode->left,expectedSum,path,currentSum);
	}
	if(treeNode->right){
		findPath(treeNode->right,expectedSum,path,currentSum);
	}

	currentSum -= treeNode->value;
	path.pop_back();
	
}

main()
{
	addNode(mRoot,10);
	addNode(mRoot,5);
	addNode(mRoot,4);
	addNode(mRoot,7);
	addNode(mRoot,12);
	//printNodeTreeMiddle(mRoot);
	int expectedSum = 22;
	int currentSum = 0;
	std::vector<int> path;
	findPath(mRoot,expectedSum,path,currentSum);
	std::cout<<std::endl;
}
