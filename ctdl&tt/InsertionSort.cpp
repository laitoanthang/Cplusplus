#include <iostream>
using namespace std;
// O(n^2)
void InsertionSort(int a[], int n)
{
	int i,j;
	for (int i = 1; i < n; i++)
	{
		j = i;
		while ((j > 0) && (a[j] < a[j-1]))
		{
			swap(a[j], a[j-1]);
			j--;
		}
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
	int a[n] = {5, 6, 2, 2 ,3};
	InsertionSort(a, n);
	printArray(a, n );
	//system("pause");
	return 0;
}