#include <iostream>
using namespace std;

struct NODE{
	int Key;
	NODE *pLeft;
	NODE *pRight;
};

void Init(NODE *&TREE)
{
	TREE = NULL;
}

void Insert (NODE *&pRoot, int x)
{
	if (pRoot == NULL)
	{
		NODE *q;
		q = new NODE;
		q->Key = x;
		q->pLeft = q->pRight = NULL;
		pRoot = q;
	}
	else {
		if (x < pRoot->Key)
			Insert (pRoot->pLeft, x);
		else if (x > pRoot->Key)
			Insert (pRoot->pRight, x);
	}
}

void CreateTree(NODE *&pRoot, int& count)
{
	int Data;
	do  {
		printf("Nhap vao du lieu, -1 de ket thuc: ");
		scanf("%d", &Data);
		if (Data == -1)
			break;
		Insert(pRoot, Data);
		count++;
	} while(1);
}

void NLR(NODE* pTree)
{
	if(pTree != NULL)
	{
		printf("%4d", pTree->Key);
		NLR(pTree->pLeft);
		NLR(pTree->pRight);
	}
}

NODE* Search(NODE* pRoot, int x)
{
	if(pRoot == NULL)
		return NULL;
	if(x < pRoot->Key)
		Search(pRoot->pLeft, x);
	else if (x > pRoot->Key)
		Search(pRoot->pRight, x);
	else
	{	// Neu pRoot->Key == x thi return pRoot
		return pRoot;
	}
}

int Height(NODE* pNode)
{
	if(pNode == NULL)
		return 0;
	int HL, HR;
	HL = Height(pNode->pLeft);
	HR = Height(pNode->pRight);
	if(HL > HR)
		return (1 + HL);
	return (1 + HR);
}

void SearchStandFor(NODE* &Tree, NODE* &q)
{
	if (Tree->pRight)
		SearchStandFor(Tree->pRight,q);
	else
	{
		q->Key = Tree->Key;
		q = Tree;
		Tree = Tree->pLeft;
	}
}

// void SearchStandFor(NODE* &Tree, NODE* &q)
// {
// 	if (Tree->pLeft)
// 		SearchStandFor(Tree->pLeft,q);
// 	else
// 	{
// 		q->Key = Tree->Key;
// 		q = Tree;
// 		Tree = Tree->pRight;
// 	}
// }

void RemoveNode(NODE* &Tree, int x)
{
	NODE* p;
	if(Tree == NULL)
		printf("%d khong co trong cay", x);
	else
	{
		if (x < Tree->Key)
			RemoveNode(Tree->pLeft,x);
		else if (x > Tree->Key)
			RemoveNode(Tree->pRight,x);
		else {
			// Truong hop tim duoc Node Tree->Key == x thi tien hanh remove it
			p = Tree;
			if(p->pRight == NULL)
				Tree = p->pLeft; // copy toan bo cay con trai vao vi tri cua tree
			else if (p->pLeft == NULL)
				Tree = p->pRight; // copy cay con phai vao vi tri cua tree 
			else {
				// Truong hop ma tree luc nay co ca cay con trai va cay con phai
				// CACH 1: THAY THE BANG PHAN TU LON NHAT TRONG CAY CON TRAI
				// SearchStandFor de thay the node co Key cao nhat ben trai vao vi tri cua node p (Luc nay la Tree or Root)
				// Buoc Lam: Neu van con ton tai Node con phai cua tree->pLeft thi move qua node con phai day (Tree = pRight)
				// Den khi nao ma node con phai = nullptr
				// Copy Key cua Tree vao trong p (p la key can Remove) -> Thay the gia tri
				// Roi lien ket dia chi lai cho hop ly
				SearchStandFor(Tree->pLeft,p);
			}

			// else {
			// 	// Neu Tree->pRight thi dung cach 2: THAY THE BANG PHAN TU
			// 	// NHO NHAT TRONG CAY CON PHAI
			// 	SearchStandFor(Tree->pRight,p);
			// }
		
		}
	}
}

void SumTree(NODE* pTree, int &s)
{	
	if(pTree != NULL)
	{

		s = s + pTree->Key;
		SumTree(pTree->pLeft, s);
		SumTree(pTree->pRight, s);
	}
}

void MaxTree(NODE* pTree, int &max)
{	
	if(pTree != NULL)
	{
		if (pTree->Key > max)
			max = pTree->Key;
		MaxTree(pTree->pLeft, max);
		MaxTree(pTree->pRight, max);
	}
}

void CountNode(NODE* pTree, int &count)
{	
	if(pTree != NULL)
	{
		// if (pTree->Key > 0) // Theo de bai ta co du lieu la int roi a. Nen em them "duong" vao de bai
		// 	count++;
		count++;
		CountNode(pTree->pLeft, count);
		CountNode(pTree->pRight, count);
	}
}

void CountLeaf(NODE* pTree, int &count)
{	
	if(pTree != NULL)
	{
		if ((pTree->pLeft == NULL) && (pTree->pRight == NULL))
			count++;
		CountLeaf(pTree->pLeft, count);
		CountLeaf(pTree->pRight, count);
	}
}


int main()
{
	NODE* pTree, *p;
	int x;
	Init(pTree);
	int countInput = 0;
	CreateTree(pTree, countInput);
	cout << endl;
	NLR(pTree);
	printf("\n--------------\n");
	
	int s = 0;
	SumTree(pTree, s);
	cout << "Sum = " << s << endl;

	int max = pTree->Key;
	MaxTree(pTree, max);
	cout << "Max = " << max << endl;
	// MIN OF TREE
	NODE* temp = pTree;
	while (temp->pLeft != nullptr)
		temp = temp->pLeft;
	cout << "Min = " << temp->Key << endl;
	int count = 0;
	CountNode(pTree, count);
	cout << "Count Node is integer: "  << count << endl;
	int count2 = 0;
	CountLeaf(pTree, count2);
	cout << "Leaf Nodes =  " << count2 << endl;
	printf("Nhap vao 1 gia tri de tim: ");
	scanf("%d", &x);
	p = Search(pTree, x);
	if(p != NULL)
	{
		printf ("%d co xuat hien trong cay.\n", x);
		printf("Chieu cao cua nut %d la %d\n", x, Height(p));
		RemoveNode(pTree, x);
		NLR(pTree);
	}
	else printf("%d khong co trong cay.\n", x);
	cout << endl;
	cout << countInput - count << " Nodes is not duplicated\n";
	return 0;
}