#include <iostream>
using namespace std;


void QuickSort(int a[], int left, int right) {
    int i, j, x;
    if (left >= right) {
        return;
    }
    x = a[(left + right) / 2]; // chọn phần tử giữa làm giá trị mốc
    i = left; j = right;
    while (i < j) {
        while (a[i] < x) {
            i++;
        }
        while (a[j] > x) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}


void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void posandneg(int a[], int n)
{
    int b[50], c[50];
    int num1 = 0;     
    int num2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0) {
            b[num1] = a[i];
            num1++;
        }
        if (a[i] >= 0) {
            c[num2] = a[i];
            num2++;
        }
    }
    QuickSort(b, 0, num1-1);
    QuickSort(c, 0, num2-1);
    for (int i = num1-1; i >= 0; i--)
        cout << b[i] << " ";
    printArray(c, num2);
}

int main()
{
	
	int a[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
	int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n-1);
	cout << "Sorted array is \n";
	printArray(a, n);
    cout << "The third greatest position is " << a[n - 3];
    int count = 1;
    int i = n-1;
    while (i >= 0)
    {
        if (a[i] == a[i - 1])
            count++;
        else break;
        i--;
    }
    cout << "\nThe number of the greatest number is " << count;
	
    cout << "\n The array that sorts abs number in ascending order is ";
    int b[50];
    for (int i = 0; i < n; i++)
        b[i] = abs(a[i]);
    QuickSort(b, 0, n-1);
    printArray(b, n);
    cout << "\n Array that have the positive number in ascending and the negative number in decending is:\n";
    posandneg(a, n);
    // cau 6 tuong tu cau 5
    return 0;
}