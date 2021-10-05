#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct coor
{
	double x;
	double y;
};

struct rectangle
{
	coor point1;
	coor point2;
};

struct Node
{
	rectangle data;
	Node* pNext = nullptr;
};

struct Linked_List
{
	Node* pHead;
	Node* pTail;
};

Node* Create_Node(rectangle x)
{
	Node* p = nullptr;
	p = new Node;
	if (p == nullptr)
	{
		cout << "No extra memory\n";
		return nullptr;
	}
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

void addTail(Linked_List& l, rectangle x)
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

double distance(coor d1, coor d2)
{
	double kc;
	kc = sqrt(double(d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
	return kc;
}

double perimeter(coor point1, coor point2)
{
	coor point3;
	coor point4;
	point3.x = point1.x;
	point3.y = point2.y;
	point4.x = point2.x;
	point4.y = point1.y;
	double distance1 = distance(point1, point3);
	double distance2 = distance(point2, point4);
	double cv = (distance1 + distance2) * 2;
	return cv;
}

void Print_1Rectangle(rectangle hcn)
{
	cout << "(" << hcn.point1.x << ";" << hcn.point1.y << ")\n";
	cout << "(" << hcn.point2.x << ";" << hcn.point2.y << ")\n";
}

void find_Min(ofstream& fout,Linked_List l)
{
	double min = 1000;
	rectangle rec;
	for (Node* i = l.pHead; i != nullptr; i = i->pNext)
	{
		double temp = perimeter(i->data.point1, i->data.point2);
		if (temp < min)
		{
			min = temp;
			rec.point1 = i->data.point1;
			rec.point2 = i->data.point2;
		}
	}
	fout<< "(" << rec.point1.x << ";" << rec.point1.y << ")\n";
	fout<< "(" << rec.point2.x << ";" << rec.point2.y << ")\n";
}

void Input_ToLinkedlist(ifstream& fin, Linked_List& l)
{
	rectangle hcn;
	while (!fin.eof())
	{
		fin >> hcn.point1.x;
		fin >> hcn.point1.y;
		fin >> hcn.point2.x;
		fin >> hcn.point2.y;
		addTail(l, hcn);
	}
}

double area(coor point1, coor point2)
{
	double dis = distance(point1, point2);
	return 1 / 2 * dis * dis;
}

void areas(ofstream& fout, Linked_List l)
{
	double a[20];
	int t = 0;
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		a[t] = area(i->data.point1, i->data.point2);
		t++;
	}
	for (int j = t-1; j >= 0; j--)
	{
		fout << a[j] << " ";
	}
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
}

void Print_Linked_List(Linked_List l)
{
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		Print_1Rectangle(i->data);
	}
	cout << "\n";
	system("pause");
}


int main()
{
	Linked_List l;
	initialize(l);
	ifstream fin;
	rectangle hcn;
	fin.open("input.txt", ios_base::in);
	Input_ToLinkedlist(fin, l);
	Print_Linked_List(l);
	ofstream fout;
	fout.open("min.txt", ios::out);
	find_Min(fout, l);
	fout.close();
	fout.open("area.txt", ios::out);
	areas(fout, l);
	Del_Linked_List(l);
	fin.close();
	fout.close();
	system("pause");
	return 0;
}