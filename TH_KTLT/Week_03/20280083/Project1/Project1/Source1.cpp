#include <iostream>
using namespace std;

void input(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	if (arr == NULL)
	{
		cout << "Could not allocate memory on Heap partition\n";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		//Set value for each element
		cout << "Input element " << i + 1 << " = ";
		cin >> *(arr + i);
	}
	cout << "Input a number: ";
	cin >> x;
}

void copyarr(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	for (int i = 0; i < n; i++)
	{
		if (x % *(arr + i) != 0)
		{
			*(arrb + m) = *(arr + i);
			*(arrc + m) = *(arr + i);
			m++;
		}
	}
}

void sortarr(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
		{
			if (*(arrc + i) > *(arrc + j))
			{
				int temp = *(arrc + i);
				*(arrc + i) = *(arrc + j);
				*(arrc + j) = temp;
			}
		}

}

void finddivisor(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x % *(arr + i) == 0)
		{
			cout << *(arr + i) << " at position " << i << endl;
			count++;
			*(arrb + m) = *(arr + i);
			*(arrc + m) = *(arr + i);
			m++;
		}
	}
	if (count == 0) cout << "No divisor in the array\n";
}

void arrMoved(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	cout << "array after move elements: \n";
	for (int i = 0; i < m; i++)
	{
		cout << *(arrb + i) << '\t';
	}
}

void arrSort(int*& arr, int& n, int& m, int*& arrb, int*& arrc, int& x)
{
	cout << "\narray after softed elements (which is not divisor of x) in ascending other\n";
	for (int i = 0; i < m; i++)
	{
		cout << *(arrc + i) << '\t';
	}
}
int main()
{
	int n = 0;

	int* arr = nullptr;
	int x = 0;
	cout << "Input nnumber of elements you want to create:\n";
	cin >> n;

	if (n > 0)
		arr = new int[n];
	else cout << "Something's wrong. Please re-input\n";
	int* arrb = nullptr;
	arrb = new int[n];
	int* arrc = nullptr;
	arrc = new int[n];
	int count = 0;
	int m = 0;
	input(arr, n, m, arrb, arrc, x);
	
	copyarr(arr, n, m, arrb, arrc, x);

	sortarr(arr, n, m, arrb, arrc, x);

	finddivisor(arr, n, m, arrb, arrc, x);

	arrMoved(arr, n, m, arrb, arrc, x);
	
	arrSort(arr, n, m, arrb, arrc, x);
	delete[] arrc;
	delete[] arrb;
	delete[] arr;
	system("pause");
	return 0;
}