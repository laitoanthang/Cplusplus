#include <iostream>
using namespace std;

float Factorial(float n)
{
	/*float s = 0;
	for (int i = 1; i < n; i++)
	{
		s *= i;
	}
	return s;*/
	if (n == 1)
		return 1;
	else return n * Factorial(n - 1);
}

float SUM(float x, float n)
{
	if (n == 0)
		return 0;
	else return pow(x, n) / Factorial(n) + SUM(x, n - 1);
}

int main()
{
	float x = 0;
	float n = 0;
	cout << "Input n=";
	cin >> n;
	cout << "Input x=";
	cin >> x;
	cout << "S4 = " << SUM(x, n);

	system("pause");
	return 0;
}