// MSSV: 20280083
// Ho ten: Lai Toan Thang

// #include <stdio.h>
// struct DIEM
// {
// 	int hoanhDo, tungDo;
// };

// int main()
// {
// 	// khoi tao cac bien gia tri
// 	int a = 10;
// 	DIEM d;
// 	d.hoanhDo = 1;
// 	d.tungDo = 2;
// 	// khai bao bien con tro va tro den vung nho cua cac bien gia tri da co
// 	int *pa = &a;
// 	int *pb = pa;
// 	DIEM *pd = &d;
// 	// xac dinh dia chi o nho: toan tu &
// 	printf("Dia chi o nho: %d \n", &a);
// 	// truy xuat gia tri o nho tu bien con tro: toan tu *
// 	printf("Gia tri a: %d \n", *pa);
// 	// truy xuat thanh phan trong cau truc
// 	printf("Diem D: (%d,%d)\n", d.hoanhDo, d.tungDo);//doi voi bien gia tri: .
// 	printf("Diem D: (%d,%d)\n", pd->hoanhDo, pd->tungDo);
// 	// doi voi bien con tro: ->

// 	delete pd;
// 	return 0;
// }

// #include <stdio.h>
// #include <iostream>
// using namespace std;
// int main()
// {
// 	// MANG 1 CHIEU
// 	int n;
// 	printf("Nhap so luong phan tu: ");
// 	scanf("%d", &n);
// 	//khai bao bien con tro a va xin cap phat vung nho chua n so interger
// 	int* a = new int[n];
// 	int sum = 0;
// 	//dung vong lap de nhap cac gia tri a[i]
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("Nhap a[%d]: ",i);
// 		scanf("%d", &a[i]);
// 		sum += a[i];
// 	}
// 	cout << "The total is " << sum << endl;
// 	// printf("a[0] = %d\n", a[0]);
// 	// printf("*a = %d\n", *a);
// 	//xuat cac gia tri a[i]
// 	// for (int i = 0; i < n; i++)
// 	// {
// 	// 	printf("a[%d] = %d\n",i, a[i]);
// 	// }
// 	return 0;
// }

// #include <iostream>
// using namespace std;

// void input_array(int **a, int row, int col)
// {
// 	for (int i = 0; i < row; i++)
// 		for (int j = 0; j < col; j++)
// 			cin >> a[i][j];
// }

// void print_array(int **&a, int row, int col)
// {
// 	for (int i = 0; i < row; i++) {
// 		for (int j = 0; j < col; j++)
// 			cout << a[i][j] << "\t";
// 		cout << endl;
// 	}
// }

// int main() 
// {
// 	int row = 0;
// 	int col = 0;
// 	cout << "Input row = ";
// 	cin >> row;
// 	cout << "Input col = ";
// 	cin >> col;
// 	int **a = new int*[row]; // cấp phát con trỏ cấp 2 gồm row phần tử
// 	// kiểu int*. Mỗi phần tử là con trỏ cấp 1 (vd như a[i] ở dưới)
// 	for (int i = 0; i < row; i++)
// 	{
// 		a[i] = new int[col]; // cấp phát con trỏ cấp 1 gồm col phần tử
// 	}
// 	input_array(a, row, col);
// 	print_array(a, row, col);
// 	for (int i = 0; i < row; i++) // giải phóng mảng 2 chiều
// 		delete[] a; // giải phóng từng hàng
// 	delete a; // giải phóng con trỏ cấp 2
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// struct DIEM
// {
// 	int x, y;
// };
// void TruyenThamTri(int a)
// {
// 	a = a * 10;
// }
// void TruyenThamBien(int &a)
// {
// 	a = a * 10;
// }
// void ThamTriConTro(DIEM* d)
// {
// 	d->x = d->x * 10;
// 	d->y = d->y * 10;
// }
// void ThamBienConTro(DIEM* &d, DIEM* p)
// {
// 	d->x = d->x * 10;
// 	d->y = d->y * 10;
// 	d = p;
// }
// int main()
// {
// 	// tham tri, tham bien voi bien du lieu
// 	int a = 1, b = 10;
// 	printf("a = %d\n", a);
// 	TruyenThamTri(a);
// 	printf("a sau ham TruyenThamTri = %d\n", a);
// 	TruyenThamBien(a);
// 	printf("a sau ham TruyenThamBien = %d\n", a);
// 	// bien con tro
// 	DIEM* d2 = new DIEM;
// 	d2->x = 5; d2->y = 5;
// 	printf("Diem d2(%d, %d)\n", d2->x, d2->y);
// 	ThamTriConTro(d2);
// 	printf("d2 sau khi goi ham ThamTriConTro: (%d,%d)\n", d2->x, d2->y);
// 	printf("\n");
// 	DIEM* d1 = new DIEM;
// 	d1->x = 7; d1-> y = 8;
// 	d2->x = 5; d2->y = 5;
// 	printf("Diem d2(%d, %d)\n", d2->x, d2->y);
// 	ThamBienConTro(d2, d1);
// 	printf("d2 sau khi goi ham ThamBienConTro: (%d,%d)\n", d2->x, d2->y);
// 	return 0;
// }


// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
// 	ifstream fin;
// 	fin.open("20280083.txt", ios::in);
// 	if (!fin.is_open())
// 	{
// 		cout << "Cannot open file in\n";
// 		return -1;
// 	}
// 	int n = 0;
// 	fin >> n;
// 	int a[n];
// 	for (int i = 0; i < n; i++)
// 		fin >> a[i];
// 	fin.close();
// 	ofstream fout;
// 	fout.open("sum.txt", ios::out);
// 	if (!fout.is_open())
// 	{
// 		cout << "Cannot open file out\n";
// 		return -1;
// 	}
// 	int sum = 0;
// 	for (int i = 0; i < n; i++)
// 		sum += a[i];
// 	fout << sum;
// 	fout.close();
// 	return 0;
// }

// #include <stdio.h>
// void DocHetFile1(char* tenFile)
// {
// 	FILE* fi = fopen(tenFile, "rt");
// 	float temp;
// 	while (!feof(fi))
// 	{
// 		fscanf(fi, "%f", &temp);
// 		printf("%0.1f ", temp);
// 	}
// 	printf("\n");
// 	fclose(fi);
// }
// void DocHetFile2(char* tenFile)
// {
// 	FILE* fi = fopen(tenFile, "rt");
// 	float temp;
// 	while (!feof(fi))
// 	{
// 		if (fscanf(fi, "%f", &temp)>0)
// 			printf("%0.1f ", temp);
// 		else
// 			break;
// 	}
// 	printf("\n");
// 	fclose(fi);
// }
// int main()
// {
// 	printf("Doc khi khong biet so luong phan tu, doc den het file thi dung:\n");
// 	DocHetFile2("input2.txt");
// 	DocHetFile2("input3.txt");
// 	return 0;
// }

#include <stdio.h>
int Tong(int* a, int n)
{
	if ( n == 0)
		return a[0];
	return Tong(a, n-1) + a[n];
}

int Multi(int* a, int n)
{
	if ( n == 0)
		return a[0];
	return Multi(a, n-1) * a[n];
}

int SumOddNumbers(int* a, int n)
{
	if (n == -1)
		return 0;
	if (a[n] % 2 != 0)
		return SumOddNumbers(a, n-1) + a[n];
	else return SumOddNumbers(a, n-1);
}
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	printf("%d\n",SumOddNumbers(a, n-1));
	printf("%d\n",Multi(a, n-1));
	printf("%d\n",Tong(a, n-1));
	return 0;
}


