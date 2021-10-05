#include <iostream>
#include <time.h>
using namespace std;

// QUICK SORT

void print_array(int *arr, int ize) {
    int i = 0;
    for(; i < ize; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(int *&arr, int low, int high) 
{ // low is the index of the first element
// and high is the index of the last element
    int pivot = arr[high]; // set the pivot is the last element
    int i = low - 1; // i: index of smaller element
    for(int j = low; j <= high - 1; ++j) {
        // j: the variable of loop
        // chạy từ đầu đến phần tử kế cuối
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
        // nếu a[j] <= pivot thì swap phần tử lớn
        // hơn pivot (a[i]) vs phần tử nhỏ hơn pivot (a[j])
        // nếu a[j] > pivot thì tăng j tiếp
    }
    // lúc này vẫn có a[i+1] > pivot nên swap nó với pivot
    i++; 
    swap(arr[i], arr[high]);
    return i;
    // return phần tử bên trái của mảng con >= pivot
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1); // sort before pivot
        quicksort(arr, pivot + 1, high); // sort after pivot
    }
}

void QuickSort(int a[], int left, int right){
    int i, j, x;
    if (left >= right)
        return;

    x = a[right]; // chọn phần tử giữa làm giá trị mốc
    i = left; j = right;
    while (i < j) 
    {
        while (a[i] < x)
            i++;
        while(a[j] > x)
            j--;
        
        if(i <= j) {
            swap(a[i], a[j]);
            i++ ;
            j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}
// -------------------------------------------------------
// HEAP SORT
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// -------------------------------------------------------
// Merge Sort



int main() 
{
    clock_t start, finish;
    start = clock();
    int arr[] = {3,6,2,1,5,8,10,10,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "before ";
    print_array(arr, n);
    // quicksort(arr, 0, n-1);
    // heapSort(arr, n);
    QuickSort(arr, 0, n-1);
    cout << ("after ");
    print_array(arr, n);
    finish = clock();
    clock_t duration = finish - start;
    // cout << endl << duration; 
    return 0;
}