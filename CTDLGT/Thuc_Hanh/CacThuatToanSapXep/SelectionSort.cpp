#include <iostream>
#include <fstream>
using namespace std;
// ý tưởng: chọn phần tử nhỏ nhất trong n phần tử và
// hoán vị cho phần tử đầu, lần lượt đối với các
// phần tử kế tiếp

void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void SelectionSort(int a[], int n) // Không sử dụng kí tự & trong hàm này vì
{// kĩ thuật lính canh
	// Tưởng tượng rằng có Array a được chia làm 2 array nhỏ, 1 là chưa sắp xếp và 2 là đã sắp xếp
	int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
	for (int i = 0; i < n-1; i++) // Vòng lặp này để move qua  
	// những ptu (đã được sắp xếp - Sorted Array)
	{
		min = i; 
		for (int j = i+1; j < n; j++) // Vòng lặp này để tìm phần tử nhỏ nhất trong Array chưa sắp xếp
		{
			if (a[j] < a[min])
			{
				min = j; // Nếu gặp anh nào nhỏ hơn thì lưu vị trí của anh đấy cho anh min
			}
		}
		if (min != i)
			Swap(a[i], a[min]); // Đem a[min] ra vị trí đầu Array chưa sắp xếp
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
	// int x[10] = {12, 2, 8, 5, 1, 6, 4, 15}; // khởi tạo các giá trị trong mảng
	// int n = 8; // số phần tử của mảng
	ifstream fin;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		cout << "Cannot open this file\n";
		return -1;
	}
	int a[50];
	int n = 0;
	while (!fin.eof())
	{
		fin >> a[n];
		n++;
	}

	SelectionSort(a, n);
	for (int i=0; i<n ; i++){
		printf("%d ", a[i]);
	}
}