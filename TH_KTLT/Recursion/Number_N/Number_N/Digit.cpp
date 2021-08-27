#include <iostream>
using namespace std;

int Count_Digits(int count, int n)
{
	if (n == 0)
		return 0;
	else return count + 1 + Count_Digits(count, n / 10);
}

int Count_EvenDigits(int count, int n)
{
	int t = n % 10;
	if (n == 0)
		return 0;
	else {
		if (t % 2 == 0)
			return count + Count_EvenDigits(count, n / 10);
		else return count + 1 + Count_EvenDigits(count, n / 10);
	}
}

int Sum_Digits(int s, int n)
{
	int t = n % 10;
	if (n == 0)
		return 0;
	else return s + t + Sum_Digits(s, n / 10);
}

int Check_TotalOdd(int n)
{
	int t = n % 10;
	if (n == 0)
		return 1;
	if (t % 2 == 1)
		return 0;
	else return Check_TotalOdd(n / 10);
}

int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	int count = 0;
	int s = 0;
	cout << Count_Digits(count, n);
	count = 0;
	cout << endl << Count_EvenDigits(count, n);
	cout << endl << Sum_Digits(s, n);
	if (Check_TotalOdd(n) == 1) cout << endl << "n contains the whole digits that are odd numbers\n";
	else cout << "\nn don't contain the whole digits that are the odd numbers\n";
	system("pause");
	return 0;
}