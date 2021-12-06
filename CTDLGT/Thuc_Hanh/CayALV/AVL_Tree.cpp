#include <iostream>
#include <fstream>
using namespace std;

struct AVLNODE
{
	int Key;
	int bal; // thuộc tính cho biết giá trị cân bằng
	// 0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
};

AVLNODE* CreateNode(int Data)
{
	AVLNODE* pNode;
	pNode = new AVLNODE; //Xin cấp phát bộ nhớ động để tạo một phần tử (node) mới
	if (pNode == NULL){
		return NULL;
	}
	pNode->Key = Data;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->bal = 0; // AVLNODE Left và AVLNODE Right đều là nullptr nên giá trị balance = 0 (Node cân bằng)
	return pNode;
}

void LeftRotate(AVLNODE* &P)
{
	AVLNODE *Q;
	Q = P->pRight;
	P->pRight = Q->pLeft;
	Q->pLeft = P;	
	P = Q;
}

void RightRotate(AVLNODE* &P)
{
	AVLNODE *Q;
	Q = P->pLeft;
	P->pLeft = Q->pRight;
	Q->pRight = P;	
	P = Q;
}

void LeftBalance(AVLNODE* &P)
{
	switch (P->pLeft->bal) {
		case 1: //mất cân bằng trái trái (Xoay phải)
			RightRotate(P);
			P->bal = 0;
			P->pRight->bal = 0;
			break;
		case 2: //Trường hợp mất cân bằng trái phải (Xoay trái rùi xoay phải)
			LeftRotate(P->pLeft);
			RightRotate(P);
			switch(P->bal) {
				case 0:
					P->pLeft->bal= 0;
					P->pRight->bal= 0;
					break;
				case 1:
					P->pLeft->bal= 0;
					P->pRight->bal= 2;
					break;
				case 2:
					P->pLeft->bal= 1;
					P->pRight->bal= 0;
					break;
			}
			P->bal = 0;
			break;
	}
}

void RightBalance(AVLNODE* &P)
{
	switch (P->pRight->bal){
	case 1: // Trường hợp mất cân bằng phải trái
		RightRotate(P->pRight);
		LeftRotate(P);
		switch(P->bal){
		case 0:
			P->pLeft->bal= 0;
			P->pRight->bal= 0;
			break;
		case 1:
			P->pLeft->bal= 1;
			P->pRight->bal= 0;
			break;
		case 2:
			P->pLeft->bal= 0;
			P->pRight->bal= 2;
			break;
		}
		P->bal = 0;
		break;
	case 2: // Trường hợp mất cân bằng phải phải
		LeftRotate(P);
		P->bal = 0;
		P->pLeft->bal = 0;
		break;
	}
}

int InsertNode(AVLNODE* &tree, int x)
{
	int res;
	if(tree==NULL){ // Trường hợp cây đang rỗng
		tree = CreateNode(x);
		if(tree==NULL){
			return -1; //thêm ko thành công vì thiếu bộ nhớ
		}
		return 2;//thêm thành công và làm tăng chiều cao cây
	}
	else {
		if(tree->Key==x){
			return 0; //khóa này đã tồn tại trong cây
		}
		else if(tree->Key > x){
			res = InsertNode(tree->pLeft,x);
			if(res < 2) {
				return res;
			}
			// Lúc này tức res đã bằng 2, tức đang thêm node thành công vào bên trái node Key
			// Tiếp theo là công việc cân bằng cây, tree đang là node parent của node vừa thêm
			switch (tree->bal) { // trường hợp node xét đang có bao nhiêu node con
			case 0: // trường hợp bal trước khi thêm node là 0
				tree->bal = 1;
				return 2;
			case 1: // Thêm vào vào bên trái thì cân bằng bên trái
				LeftBalance(tree);
				return 1;
			case 2: 
				tree->bal = 0;
				return 1;
			}
		}
		else { // Thêm vào bên phải và cân bằng
			res = InsertNode(tree->pRight,x);
			if (res<2) {
				return res;
			}
			switch(tree->bal){ // cân bằng sau khi thêm
			case 0:
				tree->bal=2;
				return 2;
			case 1:
				tree->bal = 0;
				return 1;
			case 2:
				RightBalance(tree);
				return 1;
			}
		}
	}
}

void Traverse(AVLNODE* t) // In ra
{
	if (t != NULL)
	{
		Traverse(t->pLeft);
		printf("Khoa: %d, can bang: %d\n", t->Key, t->bal);
		Traverse(t->pRight);
	}
}

void RemoveAll(AVLNODE*& t)
{
	if (t != NULL) {
		RemoveAll(t->pLeft);
		RemoveAll(t->pRight);
		delete t;
	}
}

AVLNODE* Search(AVLNODE* tree, int x)
{
	if(tree == NULL)
		return NULL;
	if(x < tree->Key)
		Search(tree->pLeft, x);
	else if (x > tree->Key)
		Search(tree->pRight, x);
	else
	{	// Neu tree->Key == x thi return tree
		return tree;
	}
}

void print2D(AVLNODE* pTree, int space)
{
	if (pTree == nullptr)
		return;
	space += 5;
	print2D(pTree->pRight, space);
	cout << endl;
	for (int i = 5; i < space; i++)
		cout << " ";
	cout << pTree->Key << "\n";
	print2D(pTree->pLeft, space);
}

void NLR(AVLNODE* pTree)
{
	if(pTree != NULL)
	{
		printf("%4d", pTree->Key);
		NLR(pTree->pLeft);
		NLR(pTree->pRight);
	}
}

int Height(AVLNODE* pNode)
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

void SearchStandFor(AVLNODE* &Tree, AVLNODE* &q)
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

void RemoveNode(AVLNODE* &Tree, int x)
{
	AVLNODE* p;
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

// --------------------- BAI 1 -----------------------
// a) Tạo cây AVL từ dãy A. Cho biết số phép so sánh cần thực hiện để tìm phần tử 21 trên cây AVL vừa tạo
AVLNODE* Search_21(AVLNODE* tree, int& count)
{
	if(tree == NULL)
		return NULL;
	if(21 < tree->Key) {
		count++;
		Search_21(tree->pLeft, count);
	}
	else if (21 > tree->Key) {
		count++;
		Search_21(tree->pRight, count);
	}
	else	{	// Neu tree->Key == x thi return tree
		return tree;
	}
}

// b) Tạo cây nhị phân tìm kiếm từ dãy A.
// Cho biết số phép so sánh cần thực hiện để tìm phần tử 21 trên cây nhị phân tìm kiếm vừa tạo.
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

NODE* SearchBST_21(NODE* tree, int& count)
{
	if(tree == NULL)
		return NULL;
	if(21 > tree->Key) {
		count++;
		SearchBST_21(tree->pRight, count);
	}
	else if (21 < tree->Key) {
		count++;
		SearchBST_21(tree->pLeft, count);
	}
	else {	// Neu tree->Key == x thi return tree
		return tree;
	}
}

void print2D(NODE* pTree, int space)
{
	if (pTree == nullptr)
		return;
	space += 5;
	print2D(pTree->pRight, space);
	cout << endl;
	for (int i = 5; i < space; i++)
		cout << " ";
	cout << pTree->Key << "\n";
	print2D(pTree->pLeft, space);
}

int main()
{
	AVLNODE* tree; // AVL Tree
	cout << "----------------- AVL TREE--------------------\n";

	// Phép gán phía dưới để nhằm muốn tree trở thành một null pointer.
	// Tức là con trỏ không trỏ đến bất kì địa chỉ của vùng nhớ nào.
	tree = NULL;
	int Data;
	do
	{
		printf("Nhap vao du lieu, -1 de ket thuc: ");
		scanf("%d", &Data);
		if (Data == -1)
			break;
		InsertNode(tree, Data); // Hàm insert AVLNODE
	} while (Data != -1);
	printf("\nCay AVL vua tao: \n");
	Traverse(tree);
	cout << "\n Ham tim kiem: ";
	cout << "\n Nhap vao mot gia tri de tim kiem ";
	int x = 0;
	cin >> x;
	AVLNODE* p = Search(tree, x);
	if (p != NULL)
	{
		cout << x << " co xuat hien trong cay\n";
		printf("Chieu cao cua nut %d la %d\n", x, Height(p));
		// RemoveNode(tree, x);
		NLR(tree);
	}
	else printf("%d khong co trong cay.\n", x);
	cout << endl;
	int space = 5;
	cout << "\n -------------------------- \n Cay can bang \n";
	print2D(tree, space); 
	
	// PHẦN ÁP DỤNG - NÂNG CAO
	// Bài 1a)
	int count = 0;
	Search_21(tree, count);
	cout << "Co tat ca " << count << " phep so sanh can thuc hien de tim ptu 21 trong AVL\n";
	// Bài 1b)
	cout << "----------------BINARY SEARCH TREE----------------\n";
	NODE* pTree; // Binary Search Tree
	Init(pTree);
	int countInput = 0;
	CreateTree(pTree, countInput);
	cout << endl;
	NLR(pTree);
	cout << "\n -------------------------- \n Cay nhi phan tim kiem \n";
	count = 0;
	SearchBST_21(pTree, count);
	space = 5;
	print2D(pTree, space);
	cout << "Co tat ca " << count << " phep so sanh can thuc hien de tim ptu 21 trong BST\n";

	// Bài 2
	// Cài đặt chương trình đọc các số nguyên từ tập tin input.txt (không biết trước số lượng số
	// nguyên trên tập tin) và tạo cây AVL từ dữ liệu đọc được
	
	return 0;
}