#include <iostream>
using namespace std;

void allocated(int**& m, int n)
{
	m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
	} 
}

void InputMatrix(int**& a, int n)
{
	for (int i = 0; i<n ; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}
}

void free_matrix(int**& m, int n)
{
	for (int i = 0; i < n; i++)
		delete m[i];
	delete m;
}

int** tichmatrix(int** a, int** b, int n)
{
	int** m = NULL;
	allocated(m, n);
	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				m[i][j] += a[i][k] * a[k][j];
			}
		}
	return m;
}

void printmatrixtich(int** m, int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n ; j++)
		{
			cout << m[i][j] <<"\t";
		}
		cout << endl;
	}
}



int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	cout << "Input matrix a\n";
	int** a = NULL;
	allocated(a, n);
	InputMatrix(a, n);
	cout << "Input matrix b\n";

	int** b = NULL;
	allocated(b, n);
	InputMatrix(b, n);
	
	printmatrixtich(tichmatrix(a, b, n), n);


	free_matrix(a, n);
	free_matrix(a, n);

	return 0;
}