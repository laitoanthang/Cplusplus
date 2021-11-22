#include <iostream>
using namespace std;

int calculate(int arr[], int a, int n)
{
	arr[0] = a;
	arr[1] = 2 * a;
	for (int i = 2; i <= n; i++)
		arr[i] = 2 * arr[i-1] + 3 * arr[i-2];
	return arr[n];
}

int min_fn(int a, int M)
{
	int arr[50];
	arr[0] = a;
	arr[1] = 2 * a;
	int  i = 1;
	while (arr[i] <= M)
	{
		arr[i+1] = 2 * arr[i] + 3 * arr[i-1];
		i++;
	}
	return i;
}

int main()
{
	int a = 0;
	int n = 0;
	cout << "Input a = ";
	cin >> a;
	cout << "Input n = ";
	cin >> n;
	int arr[n];
	int result = calculate(arr, a, n);
	for (int i = 0; i <= n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << result << endl;

	cout << "--------------------------------------------------\n";
	cout << "Input a = ";
	cin >> a;
	int M = 0;
	cout << "Input M = ";
	cin >> M;
	cout << min_fn(a, M);
	return 0;
}