#include <iostream>
using namespace std;
// O(n^2)
void BubbleSort(int a[], int n)
{
	
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
	BubbleSort(a, n);
	printArray(a, n );
	//system("pause");
	return 0;
}