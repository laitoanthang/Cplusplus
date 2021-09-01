#include <iostream>
using namespace std;

void printPermutation(int a[], int n, int k)
{
	int b[100];
	if (k>n || k<0) {
		cout << "Error when running the code\n";
		return;
	}
	// int m = 0;
	// for (int i = 0; i < k; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		b[m] = a[j];
	// 		m++;
	// 	}
	// }
	if (k == 1) {
		for (int i = 0; i<n; i++)
			cout << a[i] <<"\t";
	}	
	else {
		for (int i = 0; i<n; i++)
			for (int j=0; j<n; j++)
			{
				if (a[i] != a[j])
					cout << a[i] << "\t" << a[j] << "\n";
			}
	}

	
}
int main()
{
	int n = 3;
	int a[n] = {4, 5, 1};
	printPermutation(a, n, 2);
	return 0;
}