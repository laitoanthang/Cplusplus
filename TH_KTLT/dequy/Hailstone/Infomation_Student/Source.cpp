#include <iostream>
using namespace std;

struct student
{
	int mssv;
	char* hovaten;
	int namsinh;
	char* lophoc;
	float dtb;
};

struct Node
{
	student data;
	Node* pNext;
};

struct Linked_List
{
	Node* pHead;
	Node* pTail;
};

void Init_LinkedList(Linked_List& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

Node* Create_Node(student sv)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "No extra memory\n";
		return 0;
	}
	else {
		p->data = sv;
		p->pNext = nullptr;
	}
	return p;
}

void Input_1Student(student& sv)
{
	sv.hovaten = new char[50];
	sv.lophoc = new char[20];
	cout << "MSSV: ";
	cin >> sv.mssv;
	cin.ignore();
	cout << "Ho va ten: ";
	cin.getline(sv.hovaten, 51);
	cout << "Nam sinh: ";
	cin >> sv.namsinh;
	cin.ignore();
	cout << "Lop hoc: ";
	cin.getline(sv.lophoc, 21);
	cout << "Diem trung binh: ";
	cin >> sv.dtb;
}

void Print_1Student(student sv)
{
	cout << "-------------------\n";
	cout << sv.mssv << "\n" << sv.hovaten << endl << sv.namsinh << endl << sv.lophoc << endl << sv.dtb << endl;
}

int main()
{
	Linked_List l;
	Init_LinkedList(l);
	student sv;
	Input_1Student(sv);
	Print_1Student(sv);
	system("pause");
	return 0;
}