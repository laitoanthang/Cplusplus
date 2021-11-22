#include <iostream>
using namespace std;

struct NODE{
	int Key;
	NODE *pNext;
};

NODE* CreateNode(int Data)
{
	NODE* pNode;
	pNode = new NODE; //Xin cấp phát bộ nhớ động để tạo một phần tử (node) mới
	if (pNode == NULL)
		return NULL;
	pNode->Key = Data;
	pNode->pNext = NULL;
	return pNode;
}

bool AddHead(NODE* &pHead, int Data)
{
	NODE *pNode;
	pNode = CreateNode(Data);
	if (pNode == NULL)
		return false;
	if (pHead == NULL)
		pHead = pNode;
	else {
		pNode->pNext = pHead;
		pHead = pNode;
	}
	return true;
}

bool AddTail(NODE* &pHead, int data)
{
	NODE* p = nullptr;
	p = CreateNode(data);
	if (p == nullptr)
		return false;
	if (pHead == nullptr)
		AddHead(pHead, data);
	NODE* pCur = pHead;
	while (pCur->pNext != nullptr)
	{
		pCur = pCur->pNext;
	}
	pCur->pNext = p;
	return true;
}

void DeleteFirst(NODE* &pHead)
{
	NODE* pCur = pHead;
	pHead = pHead->pNext;
	delete pCur;
}

void DeleteTail(NODE* &pHead)
{
	NODE* pCur = pHead;
	while (pCur->pNext->pNext != nullptr)
	{
		pCur = pCur->pNext;
	}
	NODE* pDel = pCur->pNext;
	delete pDel;
	pCur->pNext = nullptr;
}

int Count_Duplicate(NODE* pHead, int x)
{
	int count = 0;
	for (NODE* i = pHead; i != nullptr; i = i->pNext)
		if (i->Key == x)
			count++;
	return count;
}



void PrintList(NODE *pHead)
{
	NODE *pNode;
	pNode = pHead;
	while (pNode != NULL)
	{
		printf("%5d", pNode->Key);
		pNode = pNode->pNext; // Di chuyển con trỏ node đến pNode tiếp theo
	}
}

void Not_Duplicate(NODE*& pRoot)
{
	int Data;
	do
	{
		printf("Nhap vao du lieu, -1 de ket thuc: ");
		scanf("%d", &Data);
		
		if (Data == -1)
			break;
		if (pRoot == nullptr)
			AddHead(pRoot, Data);
		else {
			int count = 0;
			for (NODE* i = pRoot; i != nullptr; i = i->pNext) {
				if (i->Key == Data)
					count++;
			}
			if (count == 0) AddHead(pRoot, Data);
		}
	} while (Data != -1);
	printf("\nDu lieu da duoc nhap: \n");
	PrintList(pRoot);
}

int SumList(NODE* pHead)
{
	int s = 0;
	NODE* pCur = pHead;
	while (pCur != nullptr)
	{
		s = s + pCur->Key;
		pCur = pCur->pNext;
	}
	return s;
}

int MaxList(NODE* pHead)
{
	int max = pHead->Key;
	NODE* pCur = pHead->pNext;
	while (pCur != nullptr)
	{
		if (pCur->Key > max)
			max = pCur->Key;
		pCur = pCur->pNext;
	}
	return max;
}

int CountList(NODE* pHead)
{
	int count = 0;
	NODE* pCur = pHead;
	while (pCur != nullptr){
		count++;
		pCur = pCur->pNext;
	}
	return count;
}

void SeparateList(NODE* pHead, int x)
{
	NODE* pHead1 = nullptr; // List contains elements smaller than x
	NODE* pHead2 = nullptr; // List contains elements more than x
	for (NODE* i = pHead; i != nullptr; i = i->pNext)
	{
		if (i->Key < x)
			AddTail(pHead1, i->Key);
		if (i->Key > x)
			AddTail(pHead2, i->Key);
	}
	cout << "\nLess than 5: ";
	PrintList(pHead1);
	cout << endl;
	cout << "\nGreater than 5: ";
	cout << endl;
	PrintList(pHead2);
}

void RemoveAll(NODE* &pHead) // Tất cả các phần tử trong danh sách liên kết sẽ bị xoá bỏ ra khỏi bộ nhớ
{
	NODE *pNode;
	while (pHead != NULL)
	{
		pNode = pHead;
		pHead = pHead->pNext;
		delete pNode;
	}
	pHead = NULL; // Khởi tạo lại cho pHead giá trị NULL, nếu không thì ảnh hưởng đến pHead thật trong caller.
	// Hiểu cách khác thì gán pHead lại bằng NULL thì pHead mới thật sự là NULL, nếu không gán thì pHead 
	// chưa phải là NULL mà pHead chỉ mang địa chỉ của NULL (trỏ vào NULL) - pHead vẫn còn giữ giá trị
	// địa chỉ (vẫn chi bộ nhớ cho pHead) 
}



int main(int argc, char* argv[])
{
	NODE *pRoot;
	// Khởi tạo giá trị nullptr cho con trỏ
	pRoot = NULL;
	int Data;
	do
	{
		printf("Nhap vao du lieu, -1 de ket thuc: ");
		scanf("%d", &Data);
		if (Data == -1)
			break;
		AddHead(pRoot, Data);
	} while (Data != -1);
	printf("\nDu lieu da duoc nhap: \n");
	AddTail(pRoot, 100);
	// In danh sách liên kết
	PrintList(pRoot);
	DeleteFirst(pRoot);
	DeleteTail(pRoot);
	cout << endl;
	PrintList(pRoot);
	
	
	cout << "\nSumList is " << SumList(pRoot) << endl;
	cout << "\nMaxList is " << MaxList(pRoot) << endl;
	cout << "\nCountList is " << CountList(pRoot) << endl;
	SeparateList(pRoot, 5);
	// Tất cả các phần tử trong danh sách liên kết sẽ bị xoá bỏ ra khỏi bộ nhớ
	RemoveAll(pRoot);

	cout << "Array having not duplicated element: \n";
	NODE* pCur = NULL;
	Not_Duplicate(pCur);
	return 0;
}