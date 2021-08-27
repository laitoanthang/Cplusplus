#include <iostream>
using namespace std;

long multi(int n)
{
	if (n == 1)
		return 1;
	else return n * multi(n - 1);
}

float main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	cout << "1 x 2 x ... x n = " << multi(n);
	system("pause");
	return 0;
}