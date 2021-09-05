#include <iostream>
using namespace std;

//Dãy số Hailstone được bắt đầu bằng N
//Dùng đệ quy để tạo các trường hợp sau
// Nếu số hiện tại là số chẵn thì số tiếp theo sẽ bằng số đó chia 2
// Nếu số hiện tại là số lẽ thì số tiếp theo sẽ bằng số đó nhân 3 cộng 1
// Nếu số hiện tại là 1 thì end

int Hailstone(int n)
{
	cout << n << "\t";
	if (n==1) 
		return 0;
	if (n%2==0) {
		return Hailstone(n/2);
	}
	if (n%2==1)
		return Hailstone(n*3+1);
}

int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	Hailstone(n);
	return 0;
}