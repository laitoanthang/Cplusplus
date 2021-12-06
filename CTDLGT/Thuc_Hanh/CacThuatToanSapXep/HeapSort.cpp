#include <iostream>
#include <fstream>
using namespace std;

// 1. Build Heap
// 2. Build max heap to sort elements in ascending order
// 3. Remove and then handle the left array (remaining array)

void Shift(int a[], int left, int right) { // Tạo Max/Min Heap để sort các phần tử
	int x, curr, joint;
	curr = left; 
	joint = 2 * curr + 1; // child left của parent node curr
	x = a[curr];
	while (joint <= right) { // vòng lặp while để tìm phần tử lớn nhất
		if (joint < right) { //
			if (a[joint] > a[joint + 1]) { // xác định phần tử liên đới lớn nhất
				joint = joint + 1;
			}
		}
		if (a[joint] > x) {
			break; // Thỏa quan hệ liên đới -> Dừng
		}
		a[curr] = a[joint]; // hoán đổi vị trí để được parent lớn hơn child trong trườngh hợp child > parent
		curr = joint; // Xét tiếp khả năng hiệu chỉnh lan truyền (tức là move curr xuống child)
		joint = 2 * curr + 1;
	}
	a[curr] = x; 
}


void CreateHeap(int a[], int n) // Build Heap
{ 
	int left;
	left = n / 2 - 1; // 
	while (left >= 0)
	{
		Shift(a, left, n - 1); // Create Max Heap to sort elements
		left = left - 1;
	}
}

void HeapSort (int a[], int n)
{ 
	int right;
	CreateHeap(a, n); 							// Gđ1: Hiệu chỉnh dãy ban đầu thành heap
	right = n - 1; 			 	  				// right là vị trí phần tử cuối cùng
	while (right > 0) // Gđ2: Sắp xếp dãy số dựa trên heap
	{
		swap(a[0], a[right]); // đổi vị trí phần tử đầu (là max) và phần tử index cuối
		right = right - 1; // Remove node cuối (Cố định nó)
		if (right > 0)
			Shift(a, 0, right); // Xử lí mảng hiện hành sau khi remove node lớn nhất, hiệu chỉnh lại thành heap
	}
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
	ifstream fin;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		cout << "cannot open this file\n";
		return -1;
	}
	int n = 0;
	int a[50];
	while (!fin.eof())
	{
		fin >> a[n];
		n++;
	}
	// int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	cout << "Sorted array is \n";
	printArray(a, n);
	return 0;
}