#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int* ptr = nullptr;
	float b = 5.6;

	printf("- Value: a=%d\n", a);
	printf("- Address: a=%d\n", &a);
	ptr = &a;
	printf("- Value: ptr = %d\n", ptr);
	printf("- Address: ptr = %d\n", &ptr);
	cout << endl << ptr;
	return 0;

}