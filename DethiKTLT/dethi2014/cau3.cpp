// biểu diễn nhị phân của một số n
// nếu n = 1 hoặc n = 0 thì xuất ra n
// còn lại thì xuất ra n%2 (theo đệ quy)

#include <iostream>
using namespace std;

void recursionTo2(int n)
{
	if (n==1 || n==0)
		cout << n;
	else {
		recursionTo2(n/2);
		cout << n%2;
	}	
}

int main()
{
	int n = 0;
	int s = 0;
	cout << "Input n=";
	cin >> n;
	recursionTo2(n);
	return 0;
}