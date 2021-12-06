#include <iostream>
#include <fstream>
using namespace std;


int b[50], c[50], nb, nc; // Ghi chú: 2 mảng này dùng để làm gì?

void Distribute(int a[], int N, int& nb, int& nc, int k) {
    int i, pa, pb, pc; //Ghi chú: các biến này có ý nghĩa gì?
    pa = pb = pc = 0;
    while (pa < N) {
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) { //Ghi chú: vòng lặp này có ý nghĩa gì?
            b[pb] = a[pa];
        }
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) { //Ghi chú: vòng lặp này có ý nghĩa gì?
            c[pc] = a[pa];
        }
    }
    nb = pb; nc = pc;
}


void MergeSubarr(int a[], int nb, int nc, int& pa, int& pb, int& pc, int k) {
    int rb, rc;
    rb = min(nb, pb + k);
    rc = min(nc, pb + k);
    while ((pb < rb) && (pc < rc)) {
        if (b[pb] < c[pc])
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

    while ((pb < nb) && (pc < nc)) 
    {
        MergeSubarr(a, nb, nc, pa, pb, pc, k);
    }

    while (pb < nb) {
        a[pa++] = b[pb++]; //Ghi chú: câu lệnh này có ý nghĩa gì?
    }
    while (pc < nc) {
        a[pa++] = c[pc++]; //Ghi chú: câu lệnh này có ý nghĩa gì?
    }
}


void mergeSort(int a[], int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(a, begin, mid);
    mergeSort(a, mid + 1, end);
    Merge(a, begin, mid, end);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
	ifstream fin;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		cout << "cannot open this file\n";
		return -1;
	}
	int n = 0;
	int a[50];
	while (!fin.eof())
	{
		fin >> a[n];
		n++;
	}
	// int n = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 0, n-1);
	cout << "Sorted array is \n";
	printArray(a, n);
	return 0;
}