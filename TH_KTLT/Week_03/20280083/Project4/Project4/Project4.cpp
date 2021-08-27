#include <iostream>
using namespace std;

void input_array(int**& a, int& m, int& n)
{
	for (int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Input a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
}

void output_array(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << '\n';
	}
}

int sumpos_elements(int** a, int m, int n)
{
	int s = 0;
	for (int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
				s += a[i][j];
		}
	return s;
}

int isPrime(int n)
{
	int count = 0;
	if (n < 2)
		return 0;
	for (int i = 2; i < n - 1; ++i)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int count_Prime(int** a, int m, int n)
{
	int count = 0;
	for (int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if (isPrime(a[i][j]) == 1)
				count++;
		}
	return count;
}

int max_borderline(int** a, int m, int n)
{
	int max = a[0][0];
	for (int i = 0; i < m; i++)
	{
		if (a[i][0] > max) max = a[i][0];
		if (a[i][n - 1] > max) max = a[i][n - 1];
	}
	for (int j = 0; j < n; j++)
	{
		if (a[0][j] > max) max = a[0][j];
		if (a[0][n - 1] > max) max = a[0][n - 1];
	}
	return max;
}

void list_1negative(int** a, int m, int n)
{
	cout << "\nList lines that contain at least one negative value: ";
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < 0) count++;
		}
		if (count > 0)
			cout << i << "\t";
	}
}

void list_even(int** a, int m, int n)
{
	cout << endl << "List consists of lines contains even numbers: ";
	int i = 0;
	while (i < m)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				count++;
		if (count == n) cout << i << "   ";
		i++;
	}
	cout << endl;
}

void Count_Saddle(int** a, int m, int n)
{

	int i = 0;
	int j = 0;
	int count = 0;
	int tam = 0;
	int col=0;
	float max=0;
	float min=0;
	cout << endl << "Saddle point: ";
	for (i = 0; i < m; i++)
	{
		max = a[i][0];
		col = 0;
		for (j = 1; j < n; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				col = j;
			}
		}

		min = a[0][col];
		for (int t = 1; t < m; t++)
		{
			if (min > a[t][col])
			{
				min = a[t][col];
			}
		}


		if (max == min)
		{
			cout << max << "\t";
			count++;
		}
	}
	cout << endl << "Numbers of saddle point: " << count << endl;
}

bool max_diagonal(int** a, int m, int n, int i, int j)
{
	int k = 0;
	int h = 0;
	for (k = i, h = j; k >= 0 && h < m; k--, h++)
		if (a[k][h] > a[i][j])
			return false;

	for (k = i + 1, h = j - 1; k < n && h >= 0; k++, h--)
		if (a[k][h] > a[i][j])
			return false;

	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
		if (a[k][h] > a[i][j])
			return false;

	for (k = i + 1, h = j + 1; k < n && h < m; k++, h++)
		if (a[k][h] > a[i][j])
			return false;

	return true;
}

void Count_Queenpoint(int** a, int m, int n)
{

	int count = 0;
	int col=0;
	float max1 = 0;
	float max2=0;
	float min=0;
	cout << endl << "Queen point: ";
	for (int i = 0; i < m; i++)
	{
		max1 = a[i][0];
		int row = 0;
		col = 0;
		for (int j = 1; j < n; j++)
		{
			if (max1 < a[i][j])
			{
				max1 = a[i][j];
				col = j;
			}
		}

		max2 = a[0][col];
		for (int t = 1; t < m; t++)
		{
			if (max2 < a[t][col])
			{
				max2 = a[t][col];
				row = t;
			}
		}
		if (max1 == max2 && max_diagonal(a, m, n, row, col) == 1)
		{
			cout << max1 << " position: a[" << row << "][" << col << "]     ";
			count++;
		}
	}
	cout << endl << "There are " << count << " queen points" << endl;
}

bool find_extreme(int** a, int m, int n, int i, int j)
{
	if (i == 0 && j == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]))
			return true;
	}

	if (i == m - 1 && j == 0)
	{
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j + 1]))
			return true;
	}

	if (i == 0 && j == n - 1)
	{
		if ((a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1]))
			return true;
	}

	if (i == m - 1 && j == n - 1)
	{
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1]))
			return true;
	}

	if (i == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]))
			return true;
	}

	if (j == 0)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i - 1][j]))
			return true;
	}

	if (i == m - 1)
	{
		if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j]))
			return true;
	}

	if (j == n - 1)
		if ((a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]))
			return true;

	if ((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]) && a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j])
		return true;
	return false;
}

int Sum_Extreme(int** a, int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (find_extreme(a,m,n,i,j)==1) s += a[i][j];
	return s;
}

void value_appearMost(int** a, int m, int n)
{
	cout << endl;
	int max = 0;
	int num = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int dem = 1;

			for (int x = i + 1; x < m; x++)
				for (int y = j + 1; y < n; y++)
					if (a[i][j] == a[x][y]) dem++;
			if (dem > max) {
				max = dem;
				num = a[i][j];
			}
		}
	cout << "The number " << num << " appears the most " << endl;
}

void Ascend_Boundary(int** a, int m, int n)
{
	cout << endl << " Arranges in ascending order the elements located on the matrix boundary clockwise" << endl;
	int b[100], k = 0;
	for (int j = 0; j < n; j++)
	{
		b[k] = a[0][j];
		k++;
	}
	for (int i = 1; i < m; i++)
	{
		b[k] = a[i][n - 1];
		k++;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		b[k] = a[m - 1][i];
		k++;
	}
	for (int i = m - 2; i > 0; i--)
	{
		b[k] = a[i][0];
		k++;
	}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (b[i] > b[j])
			{
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}

	int t = 0;
	for (int j = 0; j < n; j++)
	{
		a[0][j] = b[t];
		t++;
	}
	for (int i = 1; i < m; i++)
	{
		a[i][n - 1] = b[t];
		t++;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		a[m - 1][i] = b[t];
		t++;
	}
	for (int i = m - 2; i > 0; i--)
	{
		a[i][0] = b[t];
		t++;
	}
	output_array(a, m, n);
}

int main()
{
	int m = 0;
	int n = 0;
	cout << "How many rows: ";
	cin >> m;
	cout << "How many cols: ";
	cin >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	input_array(a, m, n);

	output_array(a, m, n);

	cout << "\nThe sum of the positive elements in the matrix is " << sumpos_elements(a, m, n);

	cout << "\nThere are " << count_Prime(a, m, n) << " Prime number in the array";
	
	cout << "\nMax in the border line of the matrix is " << max_borderline(a, m, n);
	
	list_1negative(a, m, n);

	list_even(a, m, n);

	Count_Saddle(a, m, n);

	Count_Queenpoint(a, m, n);

	//cout << "\nSum extreme points in the array: " << Sum_Extreme(a, m, n);
	
	value_appearMost(a, m, n);
	
	Ascend_Boundary(a, m, n);
	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	system("Pause");
	return 0;
}