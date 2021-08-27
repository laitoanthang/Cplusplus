#include <iostream>
using namespace std;

int main()
{
	char a = 'a';
	char b = 'b';

	char* pa = &a;
	char* pb = pa;

	pa = &b;
	return 0;
}