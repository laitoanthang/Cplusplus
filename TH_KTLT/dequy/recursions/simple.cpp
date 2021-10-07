#include <iostream>
#include <cmath>
using namespace std;

// Đệ quy
// Đệ quy đuôi
// Khử đệ quy
// bài tập: x^2 + x^4 + ... + x ^ 2n 

int dequy(int x, int n)
{
	if (n == 0)
		return 0; // => x^(2*0) = x^0 = 1
		// nhưng đề không cộng 1 => return 0;
	return pow(x,2*n) + dequy(x, n-1);
}

int dequyduoi(int x, int n, int sum)
{
	if (n == 0) // cộng đến khi nào n == 0 thì ngưng, return sum
		return sum;
	return dequyduoi(x, n-1, sum + pow(x, 2*n));
}

float khudequy(int x, int n)
{
	float tong = 0;
	for (int i = 1; i <= n; i++)
		tong = tong + pow(x, 2*i);
	return tong;
}
int main()
{
	int n = 0;
	cout << "Input n = ";
	cin >> n;
	int x = 0;
	cout << "Input x = ";
	cin >> x;
	int sum = 0;
	cout << dequy(x, n);
	cout << endl << dequyduoi(x, n, sum);
	cout << endl << khudequy(x, n);
	return 0;
}