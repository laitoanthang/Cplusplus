#include <iostream>
using namespace std; 
// BINARY TREE
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* Create_Node(int Data)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "No extra memory\n";
		return nullptr;
	}
	p->data = Data;
	p->left = nullptr;
	p->right = nullptr;
	return p;
}

int main()
{
	Node* root = Create_Node(1);
	root->left = Create_Node(2);
    root->right = Create_Node(3);
    root->left->left = Create_Node(4);
    /* 4 becomes left child of 2
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */

	return 0;
}

