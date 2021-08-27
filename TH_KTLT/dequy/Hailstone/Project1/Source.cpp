#include <iostream>
using namespace std;

int f(int n, int a)
{
	if (n == 0)
		return a;
	if (n == 1)
		return 2 * a + f(n - 1, a);
	else
		return 2 * f(n - 1, a) + 3 * f(n - 2, a);
}

int main()
{
	int n = 0;
	int a = 0;
	cout << "Input n=";
	cin >> n;
	cout << "Input a=";
	cin >> a;
	cout << f(n, a);

	system("pause");
	return 0;
}