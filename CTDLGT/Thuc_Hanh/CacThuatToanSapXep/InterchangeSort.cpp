#include <iostream>
using namespace std;

int InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
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
	InterchangeSort(a, n);
	printArray(a, n );
	//system("pause");
	return 0;
}