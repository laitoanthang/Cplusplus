#include <iostream>
using namespace std;

int multiply(int x, int y)
{
	if (x==0)
		return 0;
	if (x%2==0)
		return multiply(x>>1,y<<1);
	if (x%2==1)
		return multiply(x>>1, y<<1) + y;
}

int main()
{
	int x = 0;
	int y = 0;
	cout << "Input x=";
	cin >> x;
	cout << "Input y=";
	cin >> y;
	cout << multiply(x, y);
	return 0;
}