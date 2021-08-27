#include <iostream>
using namespace std;

int main()
{
	char a = 'a';
	char* pa = &a;

	float x = 5.6f;
	float* px = &x;
	//pa = &x;
	int i = 1;
	int* pi = &i;
	cout << "x=" << x << "\t" << "a=" << a << endl;
	printf(" pa = %d\n px = %d\n pi = %d\n", pa, px, pi);
	return 0;
}