#include <iostream>
using namespace std;

/*
	Binary Search: (mang tang dan)
		tìm kiếm x trong mảng a tăng dần
		ý tưởng: nếu x nhỏ hơn a[mid] thì tìm kiếm bên trái
		ngược lại thì bên phải
*/
int BinarySearch(int a[], int n, int x)
{ // O(log n) -> (log2n)
// x^2 = n (chia 2 den khi bang 1)
	int left = a[0];
	int right = a[n-1];
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right)/2;
		if (a[mid] == x) return mid;
		if (x < a[mid]) {
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return -1;
	
}

int LinearSearch(int a[], int n, int x)
{ // O(n)
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
			return i;
	}
	return -1;
}

int main()
{
	int n = 5;
	int a[n] = {1, 2, 3, 5, 7};
	int x = 5;
	// print the index of a[i] == x
	cout << BinarySearch(a, n, x) << endl;
	cout << LinearSearch(a, n, x) << endl;

	system("pause");
	return 0;
}