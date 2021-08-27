#include <iostream>
using namespace std;

int Hailstone(int n)
{
	cout << n << "  ";
	if (n == 1)
		return 0;
	if (n % 2 == 0)
		return Hailstone(n / 2);
	if (n % 2 == 1)
		return Hailstone(n * 3 + 1);

}

int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	Hailstone(n);
	system("pause");
	return 0;
}