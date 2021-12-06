#include <iostream>
#include <fstream>
using namespace std;


void QuickSort(int a[], int left, int right, int& sophepgan, int& sophepsosanh) {
    int i, j, x;
    if (left >= right) {
        sophepsosanh++;
        return;
    }
    x = a[(left + right) / 2]; // chọn phần tử giữa làm giá trị mốc
    i = left; j = right;
    sophepgan = sophepgan + 3;
    while (i < j) {
        sophepsosanh++;
        while (a[i] < x) {
            i++;
            sophepgan++;
            sophepsosanh++;
        }
        while (a[j] > x) {
            j--;
            sophepgan++;
            sophepsosanh++;
        }
        sophepsosanh++;
        if (i <= j) {
            sophepsosanh++;
            swap(a[i], a[j]);
            i++;
            sophepgan++;
            j--;
            sophepgan++;
        }
    }
    QuickSort(a, left, j, sophepgan, sophepsosanh);
    QuickSort(a, i, right, sophepgan, sophepsosanh);
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
    int sophepgan = 0;
    int sophepsosanh = 0;
	QuickSort(a, 0, n-1, sophepgan, sophepsosanh);
	cout << "Sorted array is \n";
	printArray(a, n);
    cout << "So phep gan: " << sophepgan << endl;
    cout << "So phep so sanh: "<< sophepsosanh << endl;
	return 0;
}