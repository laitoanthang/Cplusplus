#include <stdio.h>
#include <iostream>
using namespace std;
int search(int arr[],int n,int x)
{
	for (int i = 0 ; i < n ; i++) 
		if(arr[i]==x) return i;
	return -1;
}

int main()
{
	int a[10] = {1,2,3,4,5,3};
	cout << search(a, 10, 3);
	return 0;
}