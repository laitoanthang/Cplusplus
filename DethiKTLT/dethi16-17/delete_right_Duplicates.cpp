#include <iostream>
using namespace std;

// 1 3 6 3 1 5
// 1 3 6 5

struct Node {
	int data;
	Node* next;
};

void deleteRightDuplicates(Node*& head)
{
	//idea: 
	Node* pCur = head;
	while (pCur!=NULL)
	{
		// pCheck: duyet cac bien ben phai pCur
		// prev: bien truoc cua pCheck, tien cho viec xoa
		Node* pCheck = pCur->next;
		Node* prev = pCur;
		while (pCheck != NULL)
		{
			//Neu gtri cua pCur = pCheck thi xoa pCheck
			if (pCheck->data == pCur->data)
			{
				prev->next = pCheck->next;
				delete pCheck;
				pCheck = prev->next;
			}
			prev = pCheck;
			pCheck = pCheck->next;
		}
		pCur = pCur->next;
	}
}

void Create_List(Node*& list, int n, int a[])
// add mang co 6 phan tu vao trong list
{
	Node* head = NULL;
	for (int i = 0; i < n; i++)
	{
		if (head==NULL) // trường hợp head chưa có ptu nào
		{
			head = new Node; 
			// nếu head = null thì cấp phát động cho cái node mới đấy
			head->data = a[i];
			head->next = NULL;// add thong tin vao
		}
		else { // trường hợp đã có ptu. head da co data
			// cho chay den cuoi list
			Node* pCur = head;
			while (pCur->next!=NULL)
			{
				pCur = pCur->next;
			} // pCur = pTail = 5 cua list
			pCur->next = new Node; // cap phat dong ne
			pCur = pCur->next;
			pCur->data = a[i];
			pCur->next = NULL;
		}
	}
	list = head;
}

void print_List(Node* list)
{
	while (list!=NULL)
	{
		cout << list->data << '\t';
		list = list->next;
	}
}

int main()
{
	int a[] = {1,3,6,3,1,5};
	int n = 6;
	//tao mot mang -> add vao list node
	Node* head = NULL;
	Create_List(head, n, a);
	print_List(head);
	cout << endl << endl;
	deleteRightDuplicates(head);
	print_List(head);
	return 0;
}