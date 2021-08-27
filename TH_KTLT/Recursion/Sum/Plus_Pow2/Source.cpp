#include <iostream>
using namespace std;

float Sum_Pow2(float x, float n) // s=1+1/2+...+1/n
{
	if (n == 1)
		return x;
	else return pow(x, n) + Sum_Pow2(x, n - 1);
}

float main()
{
	float n = 0;
	float x = 0;
	cout << "Input n=";
	cin >> n;
	cout << "Input x=";
	cin >> x;
	cout << Sum_Pow2(x, n);
	system("pause");
	return 0;
}