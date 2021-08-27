#include <iostream>
using namespace std;

void allocating(int**& a, int& m, int& n)
{
	a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
}

void Read_File(FILE*& f, int& m, int& n, int**& a)
{
	fopen_s(&f, "in_matrix.txt", "rt");
	if (f == nullptr)
	{
		cout << "cannot open this file!";
	}
	else {
		fscanf_s(f, "%d%d", &m, &n);
		allocating(a, m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf_s(f, "%d", &a[i][j]);
			}
		}
	}
}

void Write_File(FILE*& f, int m, int n, int**& a)
{
	fopen_s(&f, "out_matrix.txt", "w");
	if (f == nullptr)
	{
		cout << "Error!\n";
		exit(1);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(f, "%d ", a[i][j]);
		}
		fprintf(f, "\n");
	}
}

void Sort_Array(int**& a, int m, int n)
{
	for (int temp = 0; temp <= (m / 2); temp++)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (a[temp * 2][i] > a[temp * 2][j])
				{
					int t = a[temp * 2][i];
					a[temp * 2][i] = a[temp * 2][j];
					a[temp * 2][j] = t;

				}
				if (a[temp * 2 + 1][i] < a[temp * 2 + 1][j])
				{
					int t = a[temp * 2 + 1][i];
					a[temp * 2 + 1][i] = a[temp * 2 + 1][j];
					a[temp * 2 + 1][j] = t;

				}
			}
	}
}

void free(int**& a, int& m, int& n)
{
	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[] a;
}

int main()
{
	int** a = nullptr;
	int m = 0;
	int n = 0;
	FILE* fi;
	FILE* fo;
	Read_File(fi, m, n, a);
	Sort_Array(a, m, n);
	Write_File(fo, m, n, a);
	free(a, m, n);
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}