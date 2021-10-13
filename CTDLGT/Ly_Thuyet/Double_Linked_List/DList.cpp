#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
	Node* pPrev;
};

struct DList
{
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(int data)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "Can not create this node\n";
		return nullptr;
	}
	p->data = data;
	p->pNext = nullptr;
	p->pPrev = nullptr;
}

int main()
{


	return 0;
}