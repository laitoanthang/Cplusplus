#include <iostream>
using namespace std;

int InterchangeSort(int a[], int n, int x)
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

int main()
{
	
	system("pause");
	return 0;
}