#include <iostream>
#include <string>

using namespace std;
#include <fstream>

struct Node
{
	float data;
	Node* pNext;
};

struct Stack
{
	Node* pStack;
};

void initStack(Stack& s)
{
	s.pStack = nullptr;
}

bool isEmpty(Stack& s)
{
	return (s.pStack == nullptr);
}

Node* Create_Node(float x)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "No extra memory\n";
		return nullptr;
	}
	p->data = x;
	p->pNext = nullptr;
	return p;
}

void Push(Stack& s, float x)
{
	//if empty
	Node* p = Create_Node(x);
	if (isEmpty(s))
		s.pStack = p;
	else {
		p->pNext = s.pStack;
		s.pStack = p;
	}
}

void Pop(Stack& s, float& x)
{
	if (isEmpty(s))
	{
		cout << "Stack is empty\n";
		return;
	}
	x = s.pStack->data;
	Node* pDel = s.pStack;
	s.pStack = s.pStack->pNext;
	delete pDel;
}

float Top(Stack s)
{
	if (isEmpty(s))
	{
		return NULL;
	}
	return s.pStack->data;
}

void Prfloat_Stack(Stack s)
{
	/*for (Node* i = s.pStack; i != nullptr; i = i->pNext) PRfloat STACK AND POP THE TOP
	{
		cout << i->data << "\t";
	}*/
	while (!isEmpty(s))
	{
		float x = 0;
		Pop(s, x);
		cout << x << " ";
	}
}

void Del_Stack(Stack& s)
{
	while (!isEmpty(s))
	{
		float x = 0;
		Pop(s, x);
	}
}

float Evacuate_Postfix(Stack s, string str)
{
	for (float i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			continue;
		}
		if (isdigit(str[i])) {
			float num = str[i] - '0';
			Push(s, num);
		}
		else {
			float x = 0;
			float y = 0;
			float result = 0;
			Pop(s, y);
			Pop(s, x);
			if (str[i] == '+')
				result = x + y;
			if (str[i] == '-')
				result = x - y;
			if (str[i] == '/')
				result = x / y;
			if (str[i] == '*')
				result = x * y;
			Push(s, result);
		}
	}
	float res = 0;
	Pop(s, res);
	return res;
}

int main()
{
	Stack s;
	string str = "";
	initStack(s);
	ifstream filein;
	ofstream fileout;
	filein.open("postfix.txt", ios_base::in);
	getline(filein, str);
	cout << str << "\n";
	fileout.open("result.txt", ios_base::out);
	fileout << Evacuate_Postfix(s, str);
	system("pause");
	return 0;
}