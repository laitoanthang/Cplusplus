#include <iostream>
using namespace std;

float Sum_1n(float n) // s=1+1/2+...+1/n
{
	if (n == 1)
		return 1;
	else return (1 / n) + Sum_1n(n - 1);
}

float main()
{
	float n = 0;
	cout << "Input n=";
	cin >> n;
	cout<<Sum_1n(n);
	system("pause");
	return 0;
}