#include <iostream>
using namespace std;
// calculate the x^y
// without using library math.h -> no pow
// without using multiply
// without using recursion

long long power(int x, int y)
{
	int s = 0;
	s = x;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	for (int i = 1; i<y; i++)
	{
		s = s + s + s;
	}
	return s;
}

int main()
{
	cout << power(3,0);
	return 0;
}