#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

struct Stack
{
	Node* pStack;
};

struct Queue
{
	Node* pQueue;
};

void initStack(Node* &pStack)
{
	pStack = nullptr;
}

void initQueue(Node* &pQueue)
{
	pQueue = nullptr;
}

Node* Create_Node(int x)
{
	Node* p = nullptr;
	p = new Node;
	if (p == nullptr)
		return NULL;
	p->data = x;
	p->pNext = nullptr;
	return p;
}

bool addHead(Node* &pHead, int x)
{
	Node* temp = Create_Node(x);
	if (temp == NULL)
		return false;
	if (pHead == nullptr)
	{
		pHead = temp;
	}
	else {
		temp->pNext = pHead;
		pHead = temp;
	}
	return true;
}

Node* RemoveHead(Node* &pHead)
{
	if(pHead == NULL)
		return NULL;
	Node* pResult = pHead;
	pHead = pHead->pNext;
	return pResult;
} // remove and return the head Node that have just removed

Node* RemoveTail(Node* &pHead)
{
	Node *pNode;
	if(pHead == NULL) // empty -> return false
		return NULL;
	else if (pHead->pNext == NULL)
	{
		pNode = pHead;
		pHead = NULL;
		return pNode; // one element -> remove and return it.
	}
	pNode = pHead; // more than one element
	while (pNode->pNext->pNext != NULL) 
		pNode = pNode->pNext; // check head down to heel
	Node* pResult = pNode->pNext;
	pNode->pNext = NULL; // remove and return Node tail
	return pResult;
}

//-------STACK :
//----PUSH is to do the same things as AddHead
//----POP is to do the same things as RemoveHead
bool PushStack(Node* &pStack, int Data)
{
	return addHead(pStack, Data);
}

Node* PopStack(Node* &pStack)
{
	return RemoveHead(pStack);
}

//--------QUEUE :
//----ENQUEUE is to the same thing as AddHead
//----DEQUEUE is to the same thing as RemoveTail
bool EnQueue(Node* &pQueue, int Data)
{
	return addHead(pQueue, Data);
}
Node* DeQueue(Node* &pQueue)
{
	return RemoveTail(pQueue);
}
// ---------------------------------

void PrintStack(Node* pStack)
{
	Node* pNode = pStack;
	while (pNode!=NULL)
	{
		cout << pNode->data << "\t";
		pNode = pNode->pNext;
	}
	cout << endl;
}

void PrintQueue(Node* pQueue)
{
	Node* pNode = pQueue;
	while (pNode!=NULL)
	{
		cout << pNode->data << "\t";
		pNode = pNode->pNext;
	}
	cout << endl;
}


int main()
{
	Stack s;
	
	//Node* pStack = NULL;
	initStack(s.pStack);
	//Node* pQueue = NULL;
	Queue q;
	initQueue(q.pQueue);
	int n = 10;
	cout << "Input n = ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		PushStack(s.pStack, i+1);
		EnQueue(q.pQueue, i+1);
	}
	PrintStack(s.pStack);
	PrintQueue(q.pQueue);
	Node* pNode2 = PopStack(s.pStack);
	if(pNode2 != NULL)
		printf("\nGia tri phan tu (Stack) : %d\n", pNode2->data);
	else
		printf("\nNULL\n");
	Node* pNode = DeQueue(q.pQueue);
	if(pNode != NULL) 
		printf("\nGia tri phan tu (Queue) : %d\n", pNode->data);
	else
		printf("\nNULL\n");
	

	PrintStack(s.pStack);
	PrintQueue(q.pQueue);
	return 0;
}

