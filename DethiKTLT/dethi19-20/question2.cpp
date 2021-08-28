#include <iostream>
#include <math.h>
using namespace std;

void sortArray(int a[], int n)
{
	for (int i = 0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
		{
			if (a[i]<a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} //sort array acording the decending order
	int x = round(n/2);
	for (int i = 0; i<x; i++)
	{
		cout<<a[i] << "\t"<< a[n-i-1] << "\t";
	}
	if (n%2 == 1)
		cout<<a[x];


}

int main()
{
	int a[100];
	int n = 0;

	cout << "Input n = ";
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >>a[i];
	}
	sortArray(a, n);


	return 0;
}