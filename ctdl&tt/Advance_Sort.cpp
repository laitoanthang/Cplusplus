#include <iostream>
using namespace std;

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


// -------------------------------------------------------



int main() 
{
    int arr[] = {3,6,2,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "before ";
    print_array(arr, n);
    quicksort(arr, 0, n-1);
    cout << ("after ");
    print_array(arr, n);
    return 0;
}