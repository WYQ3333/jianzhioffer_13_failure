#include<iostream>

#include<string>
#include<assert.h>

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
	CreateBinaryTree(const DataType data){
		_root->_data = data;
		_root->_left = nullptr;
		_root->_right = nullptr;
	}


	BinaryTree* BuyNewNode(DataType data){
		BinaryTree* NewNode = new BinaryTree(data);

	}

	//析构函数
	~CreateBinaryTree(){

	}
private:
	BinaryTree * _root;
};


void TestFunc(){

}

int main(){
	TestFunc();
	system("pause");
	return 0;
}