
#include <stdio.h>
int Hash(int k, int M)
{
	if (M == 0)
		return 0;
	return (k % M);
}
void InitHash(int*& U, int M)
{
	int K[5] = { 1,2,4,6,9 };
	int i, pos;
	for (i = 0; i < M; i++)
		U[i] = 0;
	for (i = 0; i < 5; i++)
	{
		pos = Hash(K[i], M);
		U[pos] = K[i];
	}
}
int main(int argc, char* argv[])
{
	int M = 10;
	int* U = new int[M];
	int pos;
	InitHash(U, M);
	int x;
	printf("Nhap khoa tim kiem: ");
	scanf("%d", &x);
	pos = Hash(x, M);
	if (U[pos] == 0) {
		printf("Khong tim thay khoa trong bang bam\n");
	}
	else {
		printf("Gia tri phan tu can tim kiem: %d\n", U[pos]);
	}
	return 0;
}

// #include <stdio.h>
// #include <string.h>
// struct Word
// {
// 	int key;
// 	char value[128];
// };
// int Hash(int k, int M)
// {
// 	if (M == 0)
// 		return 0;
// 	return (k % M);
// }
// void InitHash(Word*& U, int M)
// {
// 	Word K[5];
// 	K[0].key = 1;//MSSV
// 	strcpy(K[0].value, "Messi");
// 	K[1].key = 3;
// 	strcpy(K[1].value, "Ronaldo");
// 	K[2].key = 5;
// 	strcpy(K[2].value, "Rooney");
// 	K[3].key = 7;
// 	strcpy(K[3].value, "Drogba");
// 	K[4].key = 9;
// 	strcpy(K[4].value, "Xavi");
// 	int i, pos;
// 	for (i = 0; i < M; i++)
// 		U[i].key = 0;
// 	for (i = 0; i < 5; i++)
// 	{
// 		pos = Hash(K[i].key, M);
// 		U[pos] = K[i];
// 	}
// }
// int main(int argc, char* argv[])
// {
// 	int M = 10;
// 	Word* U = new Word[M];
// 	int pos;
// 	InitHash(U, M);
// 	int x;
// 	printf("Nhap MSSV tim kiem: ");
// 	scanf("%d", &x);
// 	pos = Hash(x, M);
// 	if (U[pos].key == 0) {
// 		printf("Khong tim thay SV nao trong bang bam\n");
// 	}
// 	else {
// 		printf("Ten cua SV can tim kiem la: %s\n", U[pos].value);
// 	}
// 	return 0;
// }