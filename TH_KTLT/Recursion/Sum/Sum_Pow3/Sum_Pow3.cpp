#include <iostream>
using namespace std;

float Sum_Pow3(float x, float n) // s=1+1/2+...+1/n
{
	if (n == 0)
		return x;
	else return pow(x, 2 * n + 1) + Sum_Pow3(x, n - 1);
}

float main()
{
	float n = 0;
	float x = 0;
	cout << "Input n=";
	cin >> n;
	cout << "Input x=";
	cin >> x;
	cout << Sum_Pow3(x, n);
	system("pause");
	return 0;
}