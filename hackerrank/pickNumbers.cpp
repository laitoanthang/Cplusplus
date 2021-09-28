#include <iostream>
#include <algorithm>
using namespace std;
// input length of array: 2 <= n <= 100
// input 0 < a[i] < 100
// 6
// 4 6 5 3 3 1
// output: 3
// Because the longest array is {4 3 3}

// solution: sử dụng kĩ thuật đếm phân phối 
// nếu 0 < a[i] < 10^9 thì kĩ thuật trên chịu, không làm được
// cách 2: sắp xếp mảng tăng dần (dùng quicksort)
// 1 3 3 4 5 6
// có thể là {1} {3 3 4} {3 4} {4 5} {5 6}


void demphanphoi(int a[], int n, int b[])
{
	for (int i = 0; i<n; i++)
	{
		b[a[i]]++;
	}
	// 1 2 3 4 5 6 7 8 9 10 ... 99
	// 1 0 2 1 1 1 0 0 0 0 ... 0
}

int index_max(int b[])
{
	int m = 0;
	int j = 0;
	for (int i = 0; i<100; i++)
	{
		if (b[i] > m)
		{
			m = b[i];
			j = i;
		}
	}
	return j;
}

int main()
{
	int a[100] = {1,2,2,3,1,2};
	int n = 6;
	int b[100] = {0};
	demphanphoi(a, n, b); // O(n)
	// mảng b là mảng phân phối của array a
	int m = index_max(b); // O(100)
	if (b[m-1] > b[m+1]) cout << endl << b[m]+b[m-1]; // O(1)
	else cout << endl << b[m]+b[m+1];
	// Do phuc tap O(n+100)
	// cao nhat khi n = 100
	

	

	return 0;
}