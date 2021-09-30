
// Câu 5: Xét một ds lkđơn với mỗi NODE là một
// HOCSINH (mã, tên, địa chỉ, điểm trung bình)
// Hãy khao báo ds lkđ này và viết hàm cho phép xoá tất
// cả các hs có điểm tb dưới 5

#include <iostream>
using namespace std;

struct HOCSINH
{
	int ma;
	char* ten;
	char* diachi;
	float diemtb;
};

struct Node
{
	HOCSINH data;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

void initialize_List(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void Input_1hs(HOCSINH& hs)
{
	hs.ten = new char[50];
	hs.diachi = new char[50];
	cout << "Input ma hs: ";
	cin >> hs.ma;
	cin.ignore();
	cout << "Input ten: ";
	cin.getline(hs.ten, 51);
	cout << "Input dia chi: ";
	cin.getline(hs.diachi, 51);
	cout << "Input diem trung binh: ";
	cin >> hs.diemtb;
	cout << "------------------------\n";
}

Node* Create_Node()
{
	HOCSINH hs;
	Input_1hs(hs);
	Node* p = NULL;
	p = new Node;
	if (p == NULL)
		return nullptr;
	p->data = hs;
	p->next = NULL;
	return p;
}

// void delete_Under5(List& l)
// {
// 	while (l.head->data.diemtb < 5)
// 	{
// 		Node* p = l.head;
// 		l.head = l.head->next;
// 		delete p;
// 		if (l.head = NULL) {
// 			l.head = l.tail = NULL;
// 		}
// 	}
// 	Node* pCur = l.head; // pCur de chay
// 	Node* prev = NULL; // tao prev de xoa node
// 	for (Node* i = l.head; i->next!=NULL; i = i->next)
// 	{
// 		while (i->next->data.diemtb < 5)
// 		{
// 			Node* p = i->next;
// 			delete p;
// 			i = i->next;
// 		}
// 	}
// }

void delete_Head(List& l)
{
	if (l.head == nullptr)
	{
		cout << "Empty list";
		return;
	}
	while (l.head->data.diemtb < 5) // delete at head
	{
		Node* pDel = l.head;
		l.head = l.head->next;
		delete pDel;
	}
}

void delete_Tail(List& l)
{
	if (l.head == l.tail) {
		delete_Head(l);
		return;
	}
	Node* pCur = l.head;
	//duyet den cuoi
	while (pCur->next->next != nullptr)
	{
		pCur = pCur->next;
	}
	Node* Del = pCur->next;
	pCur->next = Del->next;
	delete Del;
	l.tail = pCur;
	l.tail->next = nullptr;

}

void delete_Under5(List& l)
{
	delete_Head(l);
	// if (l.tail->data.diemtb < 5)		
	// 	delete_Tail(l);
	//delete at tail
	
	for (Node* i = l.head; i->next != NULL; i = i->next) // delete middle
	{
		while (i->next->data.diemtb < 5)
		{
			Node* pDel = i->next;
			i->next = pDel->next;
			delete pDel;
		}
	}

}

void print_1hs(HOCSINH hs)
{
	cout << "Ma so: " << hs.ma << endl;
	cout << "Ten: " << hs.ten << endl;
	cout << "Dia chi: " << hs.diachi << endl;
	cout << "Diem trung binh: " << hs.diemtb << endl;


}

void print_List(List l)
{
	for (Node* p = l.head; p != NULL; p = p->next)
	{
		print_1hs(p->data);
	}

}

int main()
{
	List l;
	int n = 0;
	initialize_List(l);
	l.head = Create_Node();
	
	int i = 0;
	while (i<3)
	{
		Node* first = Create_Node();
		first->next = l.head;
		l.head = first;
		i++;
	}
	print_List(l);
	cout << "-------------------------------------\n";
	delete_Under5(l);
	print_List(l);
	return 0;
}
