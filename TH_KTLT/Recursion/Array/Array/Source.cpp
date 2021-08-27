#include <iostream>
using namespace std;

void Input_Array(int& n, int*& a)
{
	cout << "Input n=";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Input a[" << i << "]=";
		cin >> a[i];
	}
}

int Sum_Even(int s, int n, int* a)
{
	if (n == -1)
		return 0;
	if (a[n] % 2 != 0)
		return s + Sum_Even(s, n - 1, a);
	else return s + a[n] + Sum_Even(s, n - 1, a);
}

int isPrime(int n)
{
	for (int i = 2; i < n - 1; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

long Multi_Prime(long Mul, int n, int* a)
{
	if (n == -1)
		return 1;
	if (!isPrime(a[n]))
		return Mul * Multi_Prime(Mul, n - 1, a);
	else return Mul * a[n] * Multi_Prime(Mul, n - 1, a);
}

int isNegative(int n, int* a)
{
	if (n == -1)
		return 1;
	if (a[n] > 0) return 0;
	else return isNegative(n - 1, a);
}

int Find_MinPos(int min, int n, int* a)
{
	if (n == -1)
		return min;
	if (a[n] < 0)
		return Find_MinPos(min, n - 1, a);
	if (a[n] > 0)
	{
		if (a[n] < min) {
			min = a[n];
		}
		return Find_MinPos(min, n - 1, a);
	}
}

int Count_equalX(int count, int x , int n, int* a)
{
	if (n == -1)
		return count;
	if (a[n] != x)
		return count + Count_equalX(count, x, n - 1, a);
	else return count + 1 + Count_equalX(count, x, n - 1, a);
}

int Count_Differ(int n, int* a)
{
	int* b = new int[n];
	b[0] = a[0];
	int x = 1;
	for (int i = 1; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < x; j++)
		{
			if (b[j] == a[i])
			{
				count++;
			}
		}
		if (count == 0)
		{
			b[x] = a[i];
			x++;
		}
	}
	delete[]b;
	return x;
}

int main()
{
	int n = 0;
	int* a = nullptr;
	Input_Array(n, a);
	int s = 0;
	cout << "Sum of even numbers: " << Sum_Even(s, n - 1, a) << "\n";
	long Mul = 1;
	cout << "Multiply Prime Numbers: " << Multi_Prime(Mul, n - 1, a) << "\n";
	cout << "Negative: " << isNegative(n - 1, a) << "\n";
	int min = a[n - 1];
	cout << "Min&Positive: " << Find_MinPos(min, n - 1, a) << "\n";
	int x = 0;
	cout << "Input x=";
	cin >> x;
	int count = 0;
	cout << "In the array, " << Count_equalX(count, x, n - 1, a) << " numbers equal X\n";
	cout << "There are " << Count_Differ(n, a) << " numbers that are not duplicated\n";

	delete[] a;
	system("pause");
	return 0;
}