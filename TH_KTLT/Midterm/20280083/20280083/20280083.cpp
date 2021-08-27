#include <iostream>
using namespace std;

void Input_N(int& n)
{
	cout << "Input n=";
	cin >> n;
}

void Input_Array(int*& a, int& n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Input a[" << i << "]=";
		cin >> a[i];
	}
}

int Sum_evenNumbers(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			s += a[i];
		}
	}
	return s;
}

int Sum_evenPosition(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n / 2; i++)
	{
		s += a[i * 2];
	}
	return s;
}

void Find_TheSecond(int* a, int n)
{
	int max = a[0];
	if (n < 2)
	{
		cout << "-1";
		return;
	}

	int count = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (a[i] > max)
		{
			count++;
			temp = max;
			max = a[i];
		}
	}
	if (count == 0) cout << "-1";
	cout << "The second is " << temp;

}

void free_array(int*& a, int& n)
{
	delete[] a;
}

void Output_Array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int main()
{
	int* a = nullptr;
	int n = 0;
	Input_N(n);
	Input_Array(a, n);
	//cout << "Sum of the numbers having even positions is " << Sum_evenPosition(a, n) << endl;
	cout << "\nSum of even numbers in the array is " << Sum_evenNumbers(a, n) << endl;
	Find_TheSecond(a, n);
	free_array(a, n);
	system("pause");
	return 0;
}