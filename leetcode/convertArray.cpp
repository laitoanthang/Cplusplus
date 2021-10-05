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

// dùng phương pháp quy hoạch động
int find_way(int a[][50], int row, int col, int i, int j, int &multi)
{ 
// it's kind of really difficult		
}

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

/*
Bạn được cho một ma trận kích thước N x M, ô ở hàng i và
cột j gọi là ô (i, j) và có giá trị là grid[i][j]. Bạn 
hiện tại đang đứng tại ô (0, 0), mỗi lần di chuyển, bạn
chỉ được phép di chuyển sang phải hoặc xuống dưới. 
Hãy làm sao để có thể đến được ô (n - 1, m - 1) sao cho 
tích của các số trên đường đi là lớn nhất và phải là
một số nguyên không âm. Nếu như không tồn tại một 
đường đi có tích là số nguyên không âm thì trả về -1,
ngược lại thì trả về tích có giá trị lớn nhất. 
Vì tích khá lớn nên ta đưa ra kết quả mod cho 10^9 + 7. 
*/
	int multi = b[0][0];
	if (multi == -1)
	{
		cout << "-1";
		return 0;
	}
	


	
	fin.close();
	return 0;
}