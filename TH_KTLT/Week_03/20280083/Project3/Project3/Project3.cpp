#include <iostream>
using namespace std;

void input(int*& a, int& m)
{
	cout << "Input the elements of the array: \n";
	for (int i = 0; i < m; i++)
	{
		cin >> *(a + i);
	}
}

void findinAnotinB(int* a, int m, int* b, int n)
{
	cout << "The elements that in array A but B is: \n";
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
				count++;
		}
		if (count == 0)
			cout << a[i] << '\t';
	}
}

void out(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << '\t';
	}
}

void Matching_Up(int* a, int m, int* b, int n)
{
	cout << "Array after array a vs b without duplicate: \n";
	int* c = nullptr;
	c = new int[m + n];
	int t = 0;
	for (int i = 0; i < m; i++) {
		c[t] = a[i];
		t++;
	}
	
	for (int j = 0; j < n; j++) {
		c[t] = b[j];
		t++;
	}

	for (int i=0;i<t-1;i++)
		for (int j = i + 1; j < t; j++)
		{
			if (c[i] > c[j])
			{
				int temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	for (int i = 0; i < t; i++)
	{
		if (c[i] == c[i + 1]) i++;
		else cout << c[i] << '\t';
	}
}

int main()
{
	int* a = nullptr;
	int* b = nullptr;
	int m = 0;
	int n = 0;
	cout << "Input m=";
	cin >> m;
	a = new int[m];
	input(a, m);
	cout << "Input n=";
	cin >> n;
	b = new int[n];
	input(b, n);
	findinAnotinB(a, m, b, n);
	cout << endl;
	Matching_Up(a, m, b, n);
	delete[]a;
	delete[]b;
	system("Pause");
	return 0;
}