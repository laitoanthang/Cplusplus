#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

struct SList
{
	Node* pHead;
	Node* pTail;
};

Node* Create_Node(int x)
{
	Node* p = nullptr;
	p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->pNext = nullptr;
	return p;
}

void initialize(SList& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

bool isEmpty(SList l)
{
	if (l.pHead == nullptr)
		return 1;
	else return 0;
}

void Print_SList(SList l)
{
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
		cout << i->data << "\t";
	cout << "\n";
}

void Remove_SList(SList& l)
{
	if (isEmpty(l)) return;
	Node* curr = l.pHead;
	Node* next = nullptr;
	while (curr != nullptr)
	{
		next = curr->pNext;
		delete curr;
		curr = next;
	}
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void addFirst(SList& l, Node* temp)
{
	if (isEmpty(l)) {
		l.pHead = temp;
		l.pTail = temp;
	}
	else {
		temp->pNext = l.pHead;
		l.pHead = temp;
	}
}


void addLast(SList& l, Node* temp)
{
	if (l.pHead == nullptr)
	{
		l.pHead = temp;
		l.pTail = temp;
	}
	else {
		l.pTail->pNext = temp;
		l.pTail = temp;
	}
}

void addAt(SList &l, int value, int position){
   	Node* val = Create_Node(value);
    if(position == 0 || l.pHead == NULL){
        addFirst(l, val); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }else{
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        Node* p = l.pHead;
        while(p != NULL && k != position){
            p = p->pNext;
            ++k;
        }
 
        if(k != position){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định chèn cuối
            // Nếu bạn không muốn chèn, hãy thông báo vị trí chèn không hợp lệ
            addLast(l, val);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            Node* temp = Create_Node(value);
            temp->pNext = p->pNext;
            p->pNext = temp;
        }
    }
    
}


int main()
{
	SList l;
	initialize(l);
	int n = 0;
	cout << "Input n = ";
	cin >> n;
	int a[n] ={1,2,3,4,2,6,7,2};
	for (int i = 0; i < n; i++)
	{
		Node* temp = Create_Node(a[i]);
		addLast(l, temp);
	}
	Print_SList(l);
	int value = 0;
	cout << "Input value = ";
	cin >> value;
	// Node* t = Create_Node(2);
	// Node* add = Create_Node(10);
	int index = 1;
	// add node 10 after node->data = value => index = 1
	// add node 10 before node->data = value => index = 0
	for (Node* i = l.pHead; i != nullptr; i = i->pNext)
	{
		if (i->data == value)
		{
			addAt(l, 10, index);
			index++;
		}
		index++;
	}

	
	Print_SList(l);
	return 0;
}

