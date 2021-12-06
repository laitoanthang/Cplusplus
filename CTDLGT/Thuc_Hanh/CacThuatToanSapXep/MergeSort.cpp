#include <iostream>
using namespace std;
  
// Merges two subarrays of a[].
// First subarray is a[l..m]
// Second subarray is a[m+1..r]
void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
  
    // Tạo 2 mảng tạm thời với số phần tử tương ứng của nửa đầu và nửa sau
    int L[n1], R[n2];
  
    // Copy dữ liệu vào 2 mảng
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
  
    // Merge 2 cái array tạm thời lại
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {// anh nào nhỏ hơn thì cho anh đấy vào a[] trước
        if (L[i] >= R[j]) { 
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++; // lặp lại quá trình như trên nhưng index của anh vừa đưa vào thì +1
    }
  
    /* Copy những phần tử còn lại của L[] */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
  
    // Copy những phần tử còn lại của R[]
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
  
        mergeSort(a, left, mid); // Sort nửa phần đầu
        mergeSort(a, mid + 1, right); // Sort nữa phần sau
  
        merge(a, left, mid, right);
    }
}
  
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    printf("\n");
}
  
/* Driveright code */
int main()
{
    int a[] = {5, 2, 9, 3, 7, 2, 4, 11};
    int n = sizeof(a) / sizeof(a[0]);
  
    cout << "Given array is \n";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
  
    cout << "\nSorted array is \n";
    printArray(a, n);
    return 0;
}