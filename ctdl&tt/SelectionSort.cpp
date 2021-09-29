#include <iostream>
using namespace std;
// ý tưởng: chọn phần tử nhỏ nhất trong n phần tử và
// hoán vị cho phần tử đầu, lần lượt đối với các
// phần tử kế tiếp

void SelectionSort(int a[], int n)
{// kĩ thuật lính canh
	for (int i = 0; i < n-1; i++)
	{
		int lowindex = i;
		int lowkey = a[i];
		for (int j = i; j < n; j++)
		{
			if (a[j] < lowkey)
			{
				lowkey = a[j];
				lowindex = j;
			}
		}
		swap(a[i], a[lowindex]);
	}

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
	int n = 5;
	int a[n] = {3, 2, 2, 6, 1};
	SelectionSort(a, n);
	printArray(a, n);
	system("pause");
	return 0;
}