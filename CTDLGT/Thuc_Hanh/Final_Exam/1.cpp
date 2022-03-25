#include <iostream>
#include <time.h>

using namespace std;

void randomValue(int* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand() % 1001;
}

void bubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

void quickSort(int* a, int left, int right)
{
	int i, j, x;
	if (left >= right) {
		return;
	}
	x = a[(left + right) / 2];
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
			j--;
		}
	}
	quickSort(a, left, j);
	quickSort(a, i, right);
}

int main()
{
	clock_t start, end;
	double cpu_time_used;
	int const size = 50000;
	int* arr_1 = new int[size];
	int* arr_2 = new int[size];

	randomValue(arr_1, size);
	randomValue(arr_2, size);

	start = clock();
	bubbleSort(arr_1, size);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Thoi gian xu ly bubble sort la: "<< cpu_time_used << endl;

	start = clock();
	quickSort(arr_2, 0, size - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Thoi gian xu ly quick sort la: " << cpu_time_used << endl;

	delete[] arr_1;
	delete[] arr_2;
	return 0;
}

/*Thời gian chạy trung bình (sau 3 lần chạy) của thuật toán bubble sort là 53.414s, của thuật toán quick sort là 0.03s
* Trong khi đó độ phức tạp về thời gian của bubble sort là O(n^2) và của quick sort là O(nlogn), O(n^2) > O(nlogn)
* Qua đó ta thấy được độ phức tạp thời gian tỉ lệ thuận tương đối với thời gian chạy trên cùng 1 máy
* Độ phức tạp thể hiện tương đối tốc độ nhanh hay chậm của 1 thuật toán. Với đầu vào nhỏ thời gian chạy
* của thuật toán bubble sort O(n^2) và quick sort O(nlogn) có thể khác biệt không đáng kể, nhưng với đầu vào lớn
* như 50000 ở bài trên ta thấy tốc độ của bubble sort và quick sort có sự khác biệt rõ rệt.
*/
