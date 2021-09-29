#include <iostream>
using namespace std;
// Ý tưởng:
// Cho anh i chạy từ đầu đến kế cuối
// Cho min = anh j chạy từ phần tử cuối
// nếu j nhỏ hơn anh nào thì hoán vị j với anh đấy
// nếu có anh nào nhỏ hơn anh j thì
// j ngưng tại vị trí đấy và thay min = anh nhỏ hơn
// tiếp tục công

// Độ phức tạp thuật toán: O(n)

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	}
}

void printArray(int a[], int n)
{
	for (int i=0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int main()
{
	int n = 5;
	int a[n] = {5, 6, 2, 2 ,3};
	BubbleSort(a, n);
	printArray(a, n );
	//system("pause");
	return 0;
}