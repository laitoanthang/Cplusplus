#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
	Node* head;
};

Node* Create_Node(int x)
{
	Node* p = nullptr;
	p = new Node;
	p->data = x;
	p->next = nullptr;
	return p;
}


void addFirst(List& l, int x)
{
	Node* temp = Create_Node(x);
	if (l.head == nullptr)
	{
		l.head = temp;
	}
	else {
		temp->next = l.head;
		l.head = temp;
	}
}


int CountOccurences(List ls, int num)
{
	int count = 0;
	Node* pCur = ls.head;
	while (pCur != nullptr)
	{
		if (num == pCur->data)
			count++;
		pCur = pCur->next;
	}
	return count;

}

void OutLinked_List(List l)
{
	for (Node* i = l.head; i != NULL; i = i->next)
	{
		cout << i->data << "\t";
	}
	cout << "\n";
	system("pause");
}

bool IsPermutation(List ls1, List ls2)
{
	Node* pCur = ls1.head;
	while (pCur != nullptr)
	{
		cout << CountOccurences(ls1, pCur->data);
		cout << CountOccurences(ls2, pCur->data);

		if (CountOccurences(ls1, pCur->data) != CountOccurences(ls2, pCur->data))
			return false;
		pCur = pCur->next;
		if (pCur == nullptr)
		{
			return 1;
		}
	}
}

int main()
{
	List l;
	l.head = nullptr;
	addFirst(l, 5);
	addFirst(l, 10);
	addFirst(l, 12);
	addFirst(l, 7);
	OutLinked_List(l);

	List ls2;
	ls2.head = nullptr;
	addFirst(ls2, 12);
	addFirst(ls2, 10);
	addFirst(ls2, 7);
	addFirst(ls2, 5);
	cout << endl;
	OutLinked_List(ls2);

	cout << IsPermutation(l, ls2);
	cout << endl;
	

	return 0;

}