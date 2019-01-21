#include<iostream>

#include<string>
#include<assert.h>
#include<vector>

using namespace std;

typedef int DataType;

struct BinaryTree{
	DataType _data;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
	BinaryTree(DataType data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

class CreateBinaryTree{
public:
	//构造函数
	CreateBinaryTree()
		:_root(nullptr)
	{}

	CreateBinaryTree(const DataType data){
		_root->_data = data;
		_root->_left = nullptr;
		_root->_right = nullptr;
	}

	//购买新节点
	BinaryTree* BuyNewNode(DataType data){
		BinaryTree* NewNode = new BinaryTree(data);
		if (NewNode == nullptr){
			assert(NewNode);
			return nullptr;
		}
		return NewNode;
	}

	BinaryTree* Rebulid_Binary_Tree(DataType* Start_Preorder,DataType* End_Preorder,
		DataType* Start_Inorder,DataType* End_Inorder){
		_root = BuyNewNode(Start_Preorder[0]);
		if (_root == nullptr){
			assert(_root);
			//购买新节点失败
			return nullptr;
		}
		//在中序遍历中查找根节点
		if (Start_Preorder == End_Preorder){
			if (Start_Preorder == End_Preorder
				&&*Start_Preorder == *Start_Inorder){
				return _root;
			}
			else{
				throw std::exception("Inbalid input");
			}
		}

		DataType* cur = Start_Inorder;
		while (cur <= End_Inorder&&*cur != _root->_data){
			++cur;
		}
		if (cur == End_Inorder&&*cur != _root->_data){
			assert(0);
			perror("can't rebulid binarytree\n");
			return nullptr;
		}
		int leftlength = cur - Start_Inorder;
		if (leftlength > 0){
			_root->_left = Rebulid_Binary_Tree(Start_Preorder + 1, End_Preorder,
				Start_Inorder, cur - 1);
		}
		if (leftlength < End_Preorder - Start_Preorder){
			_root->_right = Rebulid_Binary_Tree(Start_Preorder + 1, End_Preorder,
				cur+1, End_Inorder);
		}
		return _root;
	}

	BinaryTree* Create_Binary_Tree(DataType* Preorder, DataType* Inorder, int length){
		if (nullptr == Preorder || Inorder == nullptr || length == 0){
			return nullptr;
		}
		return Rebulid_Binary_Tree(Preorder, Preorder + length - 1,
			Inorder, Inorder + length - 1);
	}

	//前序遍历
	void PReorder(BinaryTree * pRoot){
		if (pRoot == nullptr){
			return;
		}
		cout << pRoot->_data << " ";
		PReorder(pRoot->_left);
		PReorder(pRoot->_right);
	}

	//后序遍历
	void INeorder(BinaryTree * pRoot){
		if (pRoot == nullptr){
			return;
		}

		INeorder(pRoot->_left);
		cout << pRoot->_data << " ";
		INeorder(pRoot->_right);
	}

	//析构函数
	~CreateBinaryTree(){

	}
public:
	BinaryTree * _root;
};


void TestFunc(){
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int Inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int length = 8;
	CreateBinaryTree T1;
	T1.Create_Binary_Tree(Preorder, Inorder, length);
	T1.PReorder(T1._root);
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}


#if 0
#include<iostream>

using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
	int *startInorder, int *endInorder){
	int rootvalue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootvalue;
	root->left = root->right = nullptr;

	if (startPreorder == endPreorder){
		if (startInorder == endInorder
			&&*startPreorder == *startInorder){
			return root;
		}
		else{
			throw std::exception("Inbalid input");
		}
	}
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootvalue){
		++rootInorder;
	}
	if (rootInorder == endInorder&&*rootInorder != rootvalue){
		throw std::exception("Invalid input");
	}
	int leftlength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftlength;
	if (leftlength > 0){
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	if (leftlength < endPreorder - startPreorder){
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1,
			endInorder);
	}
	return root;
}


BinaryTreeNode * Construct(int *preorder, int *inorder, int length){
	if (preorder == nullptr || inorder == nullptr || length < 0){
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
//前序遍历
void PReorder(BinaryTreeNode * pRoot){
	if (pRoot == nullptr){
		return;
	}
	cout << pRoot->value << " ";
	PReorder(pRoot->left);
	PReorder(pRoot->right);
}

//后序遍历
void INeorder(BinaryTreeNode * pRoot){
	if (pRoot == nullptr){
		return;
	}

	INeorder(pRoot->left);
	cout << pRoot->value << " ";
	INeorder(pRoot->right);
}
int main(){
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int Inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int length = 8;
	BinaryTreeNode * root = Construct(Preorder, Inorder, length);
	PReorder(root);
	cout << endl;
	INeorder(root);
	system("pause");
	return 0;
}

#endif