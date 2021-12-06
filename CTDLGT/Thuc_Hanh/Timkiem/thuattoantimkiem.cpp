#include <iostream>
using namespace std;
#include <time.h>

int LinearExhaustive(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1; // nếu kết thúc vòng lặp mà chưa return thì
	// return -1 để thông báo không có x trong mảng
}

int LinearSentinel(int a[], int n, int x) {
	a[n] = x; //Tại sao gán x cho a[n] mà không phải cho a[n-1]?
	for (int i = 0; ; i++) { //Tại sao vòng lặp for là lặp vô tận?
		if (a[i] == x) { // Vì khi i = n, tức a[i] = a[n] = x
			return i; // thì return i
		}
	}
	// Vì a[n] luôn bằng x rồi nên trong vòng lăp sẽ trả về vị trí của x
}

int BinarySearch(int a[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			return m;
		}
		else {
			if (x < a[m]) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
	}
	return -1;
}

int BinarySearch_Recursion(int a[], int l, int r, int x) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (a[m] == x) 
		return m;
	if (x < a[m]) 
		return BinarySearch_Recursion(a, l, m - 1, x);
	else	return BinarySearch_Recursion(a, m + 1, r, x);
}

int main()
{
	
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	int x;
	printf("Nhap gia tri phan tu can tim kiem: ");
	scanf("%d", &x);

	clock_t start, end;
	double cpu_time_used;
	start = clock();
		
	int i = LinearSentinel(a, n, x);
	if (i == n) {
		printf("Khong tim thay x trong mang A\n");
	}
	else {
		printf("Vi tri x trong mang A la: %d\n", i + 1);
		// In vị trí thứ tự của x trong mảng
	}

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nThoi gian xu ly la: %f\n", cpu_time_used);

	start = clock();
	cout << "\n Binary Search\n";
	int l = 0;
	int r = n - 1;
	int j = BinarySearch_Recursion(a, l, r, x);
	if (j == -1) {
		cout << "Element not found\n";
	}
	else cout << x << " is present at index " << i + 1;

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nThoi gian xu ly la: %f\n", cpu_time_used);
	return 0;
}




// struct WORD {
// 	char Name[256];
// 	char Meaning[512];
// }

