// #include <iostream>
// using namespace std;

// int Hash(int k, int M)
// {
// 	if (M == 0)
// 		return 0;
// 	return (k % M);
// }

// void InitHash(int*& U, int M)
// {
// 	int K[5] = { 1,2,4,6,9 };
// 	int i, pos;
// 	for (i = 0; i < M; i++)
// 		U[i] = 0;
// 	for (i = 0; i < 5; i++)
// 	{
// 		pos = Hash(K[i], M);
// 		U[pos] = K[i];
// 	}
// }

// int main(int argc, char* argv[])
// {
// 	int M = 10;
// 	int* U = new int[M];
// 	int pos;
// 	InitHash(U, M);
// 	cout << "\n---------------------------\n";
// 	for (int i = 0; i < M; i++)
// 	{
// 		cout << U[i] << "\t";
// 	}
// 	cout << "\n---------------------------\n";
	
// 	int x;
// 	printf("Nhap khoa tim kiem: ");
// 	scanf("%d", &x);
// 	pos = Hash(x, M);
// 	if (U[pos] == 0) {
// 		printf("Khong tim thay khoa trong bang bam\n");
// 	}
// 	else {
// 		printf("Gia tri phan tu can tim kiem: %d\n", U[pos]);
// 	}
// 	return 0;
// }

#include <iostream>
#include <string.h>
using namespace std;

struct Word
{
	int key;
	char value[128];
};

int Hash(int k, int M)
{
	if (M == 0)
		return 0;
	return (k % M);
}

Word Input1sv()
{
	Word sv;
	cout << "Nhap ma so sinh vien = ";
	cin >> sv.key;
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	cin.getline(sv.value, 129);
	return sv;
}

void InitHash(Word*& U, int M)
{
	
	int n = 0;
	cout << "Nhap so luong sinh vien = ";
	cin >> n;
	Word K[n];
	for (int i = 0; i < n; i++)
	{
		K[i] = Input1sv();
	}
	int i, pos;
	for (i = 0; i < M; i++)
		U[i].key = 0;
	for (i = 0; i < 5; i++)
	{
		pos = Hash(K[i].key, M);
		U[pos] = K[i];
	}
}

int main()
{
	int M = 10;
	Word* U = new Word[M];
	int pos;
	InitHash(U, M);
	int x;
	printf("Nhap MSSV tim kiem: ");
	scanf("%d", &x);
	pos = Hash(x, M);
	if (U[pos].key == 0) {
		printf("Khong tim thay SV nao trong bang bam\n");
	}
	else {
		printf("Ten cua SV can tim kiem la: %s\n", U[pos].value);
	}
	return 0;
}