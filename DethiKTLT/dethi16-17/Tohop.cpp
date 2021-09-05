#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	int* a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Input a[" << i << "]=";
		cin >> a[i];
	}

	return 0;
}