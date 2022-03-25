#include <iostream>
using namespace std;

int b[50], c[50], nb, nc; // Tạo 2 mảng tạm thời với số phần tử tương ứng của nửa đầu và nửa sau
void Distribute(int a[], int N, int& nb, int& nc, int k) {
    int i, pa, pb, pc;  // pa là index từ 0 đến n trong mảng a
                        // pb là số lượng phần tử của mảng b
                        // pc là số lượng phần tử của mảng c
    pa = pb = pc = 0;
    while (pa < N) {
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) { // vòng lặp để copy dữ liệu vào mảng con thứ nhất 
            b[pb] = a[pa];
        }
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) { // vòng lặp để copy dữ liệu vào mảng con thứ hai
            c[pc] = a[pa];
        }
    }
    nb = pb; nc = pc; 
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void MergeSubarr(int a[], int nb, int nc, int& pa, int& pb, int& pc, int k) {
    int rb, rc;
    rb = min(nb, pb + k);
    rc = min(nc, pb + k);
    while ((pb < rb) && (pc < rc)) {
        if (b[pb] > c[pc]) // Nếu sort giảm dần thì thay bằng b[pb] > c[pc]
            a[pa++] = b[pb++];
        else a[pa++] = c[pc++];
    }
    while (pb < rb) {
        a[pa++] = b[pb++];
    }
    while (pc < rc) {
        a[pa++] = c[pc++];
    }
}

void Merge(int a[], int nb, int nc, int k) {
    int pa, pb, pc;
    pa = pb = pc = 0;
    while ((pb < nb) && (pc < nc)) {
        MergeSubarr(a, nb, nc, pa, pb, pc, k); // trộn hai cái array tạm thời lại
    }
    while (pb < nb) {
        a[pa++] = b[pb++]; // Copy những phần tử còn lại của mảng b 
    }
    while (pc < nc) {
        a[pa++] = c[pc++]; // Copy những phần tử còn lại của mảng c
    }
}


void MergeSort(int a[], int N) {
    int k = 1;
    while (k < N) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
        k *= 2;
    }
}
  
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    printf("\n");
}

int main()
{
    int a[] = {5, 2, 9, 3, 7, 2, 4, 11};
    int n = sizeof(a) / sizeof(a[0]);
  
    cout << "Given array is \n";
    printArray(a, n);
    // mergeSort(a, 0, n - 1);
    MergeSort(a, n);
    cout << "\nSorted array is \n";
    printArray(a, n);
    return 0;
}
// Idea: 
// Merges two subarrays of a[].
// First subarray is a[l..m]
// Second subarray is a[m+1..r]
// void merge(int a[], int left, int mid, int right)
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
  
//     // Tạo 2 mảng tạm thời với số phần tử tương ứng của nửa đầu và nửa sau
//     int L[n1], R[n2];
  
//     // Copy dữ liệu vào 2 mảng
//     for (i = 0; i < n1; i++)
//         L[i] = a[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = a[mid + 1 + j];
  
//     // Merge 2 cái array tạm thời lại
//     i = 0; 
//     j = 0; 
//     k = left; 
//     while (i < n1 && j < n2) {// anh nào nhỏ hơn thì cho anh đấy vào a[] trước
//         if (L[i] >= R[j]) { 
//             a[k] = L[i];
//             i++;
//         }
//         else {
//             a[k] = R[j];
//             j++;
//         }
//         k++; // lặp lại quá trình như trên nhưng index của anh vừa đưa vào thì +1
//     }
  
//     /* Copy những phần tử còn lại của L[] */
//     while (i < n1) {
//         a[k] = L[i];
//         i++;
//         k++;
//     }
  
//     // Copy những phần tử còn lại của R[]
//     while (j < n2) {
//         a[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int a[], int left, int right)
// {
//     if (left < right) {
//         int mid = (left + right) / 2;
  
//         mergeSort(a, left, mid); // Sort nửa phần đầu
//         mergeSort(a, mid + 1, right); // Sort nữa phần sau
  
//         merge(a, left, mid, right);
//     }
// }
// 
