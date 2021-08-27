#include <iostream>
using namespace std;

void input(int*& a, int& n)
{
	do {
		cout << "Input n=";
		cin >> n;
	} while (n < 0);
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Input a[" << i << "]=";
		cin >> *(a + i);
	}
}

int countelementsdivisibleby6(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 6 == 0 && (*(a + i) % 10 == 6))
		{
			count++;
		}
	}
	return count;
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


float theaverageprimenumber(int* a, int n)
{
	float s = 0;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (isPrime(*(a + i)) == 1) {
			s += *(a + i);
			count++;
		}
	}
	return s / count;
}

int counttheprimenums_dist(int* a, int n)
{
	int count = 0;
	for (int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	for (int i = 0; i < n; i++)
	{
		if (isPrime(a[i]) == 1)
		{
			count++;
			if (a[i] == a[i + 1]) {
				count--;
			}
		}
	}
	count--;
	return count;
}


int main()
{
	int n = 0;
	int* a = nullptr;
	input(a, n);
	
	cout << "The number of elements of an array of integers that are devisible by 6 and the last 6 is: " << countelementsdivisibleby6(a, n);
	
	cout << "\nThe average of the prime numbers of the array is: " << theaverageprimenumber(a, n);

	cout << "\nThe numbers of the prime number that are not duplicated is: " << counttheprimenums_dist(a, n);
	delete[]a;
	system("Pause");
	return 0;
}