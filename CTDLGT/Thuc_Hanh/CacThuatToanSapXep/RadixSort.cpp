#include <iostream>
using namespace std;
 
int getMax(int arr[], int n) // get max trong array
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
void countSort(int arr[], int n, int exp)
{
	int output[n]; 
	int i = 0;
	int count[10] = {0};
	
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++; // count là mảng có phần tử là bao nhiêu số các số có chữ số hàng exp tăng dần
	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // mảng output chứa các chữ số có chữ số hàng exp (ví dụ như hàng đơn vị) tăng dần
		count[(arr[i] / exp) % 10]--;
	}
	
	for (i = 0; i < n; i++) // copy dữ liệu vào mảng arr
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	
	int m = getMax(arr, n); // tìm max để lấy được số chữ số của max
	
	for (int exp = 1; m / exp > 0; exp = exp * 10) // CountSort lần lượt cho hàng đơn vị, chục, trăm, ngàn...
		countSort(arr, n, exp); // Note: Khi số không có chữ số để so sánh thì pass qua..
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	radixsort(arr, n);
	printArray(arr, n);
	return 0;
}