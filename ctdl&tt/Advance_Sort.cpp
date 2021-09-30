#include <iostream>
using namespace std;

// QuickSort
// Step 1: Find pivot
// Step 2: Phân hoạch thành mảng nhỏ hơn (r -> trước) và 
// mảng lớn hơn HOẶC BẰNG pivot (l -> sau)
// dùng đệ quy

int findPivot(int a[], int n)
{ // return index of Pivot
	int pivot = 0;
	int i = 1;
	while (i < n)
	{
		if (a[i] > a[pivot])
			return i;
		else if (a[i] < a[pivot])
			return pivot;
		i++;
	}
	return -1;
}

int Partition(int a[], int low, int high, int pivot)
{ // Phân hoạch mảng
	int left = low;
	int right = high;
	while (left <= right)
	{
		while (a[left] < a[pivot])
			left++;
		while (a[right] >= a[pivot])
			right--;
		if (left < right) 
			swap(a[left], a[right]);
	}
	// neu left > right thì...
	return left;
}

int QuickSort(int i, int j)
{
	// Find Pivot
	// Phân hoạch
}

void printArray(int a[], int n)
{
	for (int i=0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int main()
{
	int n = 10;
	int a[n] = {5,4,2,1,5,12,8,10,15,8};
	int pivot = findPivot(a, n);
	cout << Partition(a, 0, n-1, pivot);
	//printArray(a, n );
	//system("pause");
	return 0;
}