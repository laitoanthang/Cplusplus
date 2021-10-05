/*
	Ta cần chuyển 1 dãy số dưới dạng mảng 1 chiều sang
	ma trận 2 chiều kích thước n * m. Chuyển bằng cách
	m số đầu tiên của dãy nằm trên dòng 1 trên ma trận,
	m số tiếp theo của dãy trên dòng 2 của ma trận .....,
	m số cuối cùng của dãy trên dòng thứ n của ma trận.
	Nếu không chuyển được, ta trả về một mảng rỗng. 
	Demand: dùng file để nhập mảng
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int row = 0;
	int col = 0;
	int n = 0;
	ifstream fin;
	fin.open("convertArray.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "Cannot open this file\n";
		return -1;
	}
	fin >> row >> col;
	fin >> n;
	if (row * col != n)
		return -1;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	int b[row][col];
	int k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = a[k];
			k++;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	
	fin.close();
	return 0;
}