#include <iostream>
using namespace std;
// khai báo danh sách liên kết đơn gồm các bước
// khởi tạo linkedlist,  tạo node, 
// thêm đầu, thêm cuối, nhập, xuất, giải phóng ds
struct Node
{
	int data;
	Node* pNext;
};

struct Linked_List
{
	Node* pHead;
	Node* pTail;
};

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

void initialize(Linked_List& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

bool isEmpty(Linked_List l)
{
	if (l.pHead == nullptr)
		return 1;
	else return 0;
}

void Del_Linked_List(Linked_List& l)
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
	/*
	Node* pNode;
	while (l.pHead != NULL)
	{
		pNode = l.pHead;
		l.pHead = l.pHead->pNext;
		delete pNode;
	} 
	l.pHead = nullptr;
	l.pTail = nullptr;
	*/
}

void OutLinked_List(Linked_List l)
{
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		cout << i->data << "\t";
	}
	cout << "\n";
	system("pause");
}

bool addFirst(Linked_List& l, int x)
{
	Node* temp = Create_Node(x);
	if (temp == nullptr)
	{
		cout << "Cannot create this node\n";
		return false;
	}
	if (isEmpty(l))
		l.pHead = l.pTail = temp;
	else {
		temp->pNext = l.pHead;
		l.pHead = temp;
	}
	return true;
}

void addLast(Linked_List& l, int x)
{
	Node* temp = Create_Node(x);
	if (l.pHead == nullptr)
	{
		l.pHead = l.pTail = temp;
	}
	else {
		l.pTail->pNext = temp;
		l.pTail = temp;
	}
}

void addAfter(Linked_List& l, int val1, int val2) //add a value2 after value1 in linked list
{
	int count = 0;
	for (Node* i = l.pHead; i != nullptr; i = i->pNext)
	{
		if (i->data == val1)
		{
			Node* temp = Create_Node(val2);
			temp->pNext = i->pNext;
			i->pNext = temp;
			count++;
		}
	}
	if (count == 0) cout << "Error, can not find the number you want\n";
}

void Del_First(Linked_List& l)
{
	if (l.pHead != nullptr)
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == nullptr)
		{
			l.pHead = l.pTail = nullptr;
		}
	}
}

void Del_Last(Linked_List& l)
{
	if (l.pTail)
	{
		if (l.pHead == l.pTail) Del_First(l);
		else {
			Node* pCur = l.pHead;
			Node* pDel = l.pTail;
			//duyet den thang ke cuoi cua list
			while (pCur->pNext != l.pTail)
			{
				pCur = pCur->pNext;
			}
			delete pDel; //xoa thang cuoi
			l.pTail = pCur; //update lai thang Tail
			l.pTail->pNext = nullptr; //fix loi, update sau tail
		}
	}
}

void DelAfter_ValueK(Linked_List& l, int x)
{
	if (isEmpty(l)) {
		cout << "Linked List is empty\n";
		return;
	}
	if (l.pHead->data == x)
	{
		Del_First(l);
	}
	if (l.pTail->data == x)
	{
		Del_Last(l);
	}
	for (Node* i = l.pHead; i->pNext != NULL; i = i->pNext)
	{
		while (i->pNext->data == x)
		{
			Node* pDel = i->pNext;
			i->pNext = pDel->pNext;
			delete pDel;
		}
	}
}

void Find_Node(Linked_List l, int x)
{
	int count = 1;
	for (Node* i = l.pHead; i != nullptr; i = i->pNext)
	{
		if (i->data == x)
		{
			cout << "Node " << count << " is containing the value x\n";
		}
		count++;
	}
	system("pause");
}

void Match_2list(Linked_List l, Linked_List new_list)
{
	l.pTail->pNext = new_list.pHead;
	cout << "After matching:\n";
	OutLinked_List(l);

}

// idea:
// Gán con trỏ Cur bằng head, prev và next thì nullptr
// Khi cur mà khác nullptr
// thì di chuyển anh next bằng next của Cur
// chuyển ngược liên kêt
// di chuyển 2 con trỏ còn lại (cur và prev) lên 1 đv
// head = anh prev (vì khi đấy, next = nullptr trước
// sau đó đến anh cur cũng dính vào)
void reverse(Linked_List& l)
{
	Node* prev = nullptr;
	Node* pCur = l.pHead;
	Node* next = nullptr;
	while (pCur != nullptr)
	{
		next = pCur->pNext;
		pCur->pNext = prev;
		prev = pCur;
		pCur = next;
	}
	l.pHead = prev;
}

void PrintList(Linked_List l)
{
	Node* pNode;
	pNode = l.pHead;
	while (pNode != NULL)
	{
		cout << pNode->data;
		pNode = pNode->pNext; // Move pointer to next node
	}
}

void Menu(Linked_List& l)
{
	int x = 0;
	int choice = 0;
	
	while (choice >= 0)
	{
		system("cls");
		cout << "What operation do you want to perform? Select Option Number. Enter 0 to Exit\n";
		cout << "1. InitLinked_List\n";
		cout << "2. IsEmpty\n";
		cout << "3. DeleteLinked_List\n";
		cout << "4. Append a number to the head of the Linked_List\n";
		cout << "5. Append a number to the tail of the Linked_List\n";
		cout << "6. Delete a number at the head of the Linked_List\n";
		cout << "7. Delete a number at the tail of the Linked_List\n";
		cout << "8. Print the Linked_List\n";
		cout << "9. Find node containing the value x \n";
		cout << "10. Add a number 'y' after 'x'. \n";
		cout << "11. Delete node after number 'x'\n";
		cout << "12. Match 2 lists\n";
		cout << "13. Reverse the linked list\n";
		cout << "Enter Proper Option Number\n";
		cin >> choice;
		if (choice == 0) {
			cout << "__exit__\n";
			return;
		}
		if (choice == 1) initialize(l);
		if (choice == 2)
		{
			if (isEmpty(l)) cout << "Linked_List is empty\n";
			else cout << "Linked_List is not empty\n";
			system("pause");
		}
		if (choice == 3) Del_Linked_List(l);
		if (choice == 4) {
			cout << "Enter a number\n";
			cin >> x;
			addFirst(l, x);
		}
		if (choice == 5) {
			cout << "Enter a number\n";
			cin >> x;
			addLast(l, x);
		}
		if (choice == 6) {
			if (isEmpty(l))
			{
				cout << "Linked list is empty\n";
				system("pause");
				return;
			}
			Del_First(l);
		}
		if (choice == 7)
		{
			if (isEmpty(l))
			{
				cout << "Linked list is empty\n";
				system("pause");
				return;
			}
			Del_Last(l);
		}
		if (choice == 8)
		{
			OutLinked_List(l);
		}
		if (choice == 9)
		{
			cout << "Input x=";
			cin >> x;
			Find_Node(l, x);
		}
		if (choice == 10)
		{
			int y = 0;
			cout << "\nInput x=";
			cin >> x;
			cout << "\nInput y=";
			cin >> y;
			addAfter(l, x, y);
		}
		if (choice == 11)
		{
			int k = 0;
			cout << "Input k=";
			cin >> k;
			DelAfter_ValueK(l, k);
		}
		if (choice == 12)
		{
			Linked_List new_list;
			initialize(new_list);
			cout << "Input one more list\n";
			int n = 0;
			cout << "n=";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Append number x=";
				cin >> x;
				addLast(new_list, x);
			}
			OutLinked_List(new_list);
			cout << "Match 2 list\n";
			Match_2list(l, new_list);
			Del_Linked_List(new_list);
		}
		if (choice == 13)
		{
			reverse(l);
		}
	}
}

int main()
{
	Linked_List l;
	initialize(l);
	Menu(l);
	Del_Linked_List(l);
	system("pause");
	return 0;
}