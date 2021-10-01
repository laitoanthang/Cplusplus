#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void DocFile(ifstream &FileIn, vector<string> &arr)
{
	FileIn.open("INPUT.txt", ios_base::in);
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.txt";
		system("pause");
		exit(0); // tắt luôn chương trình
	}

	while(!FileIn.eof())
	{
		string str;
		FileIn >> str;

		//if(str[0] != '.' && str[0] != ',' && str[0] != '?' && str[0] != '!' && str[0] != ':')
		if((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
			//cout << "\nstr = " << str;
			arr.push_back(str);
	}
	FileIn.close();
}

void XuatVector(vector<string> arr)
{
	int size = arr.size();
	for(int i = 0; i < size; ++i)
		cout << arr[i] << endl;
}

string TimTuDaiNhat(vector<string> arr)
{
	int Max = arr[0].length();
	int index = 0; // đánh dấu bắt đầu từ 0

	int size = arr.size();
	for(int i = 1; i < size; ++i)
	{
		int dodai = arr[i].length();
		if(dodai > Max)
		{
			Max = dodai;
			index = i;
		}
	}
	return arr[index];
}

int TimDoDaiTuDaiNhat(vector<string> arr)
{
	int Max = arr[0].length();

	int size = arr.size();
	for(int i = 1; i < size; ++i)
	{
		int dodai = arr[i].length();
		if(dodai > Max)
			Max = dodai;
	}
	return Max;
}

void XuatTatCaCacTuCoDoDaiDaiNhat(vector<string> arr)
{
	int Max = TimDoDaiTuDaiNhat(arr);

	int size = arr.size();
	for(int i = 0; i < size; ++i)
	{
		int dodai = arr[i].length();
		if(dodai == Max)
			cout << arr[i] << endl;
	}
}

void XoaCacTuTrungNhauTrongVector(vector<string> &arr)
{
	int size = arr.size();
	for(int i = 0; i < size - 1; ++i)
	{
		for(int j = i + 1; j < size; ++j)
		{
			if(arr[i] == arr[j]) // so sánh có phân biệt hoa thường
			//if(strcmp(strupr((char *)arr[i].c_str()), strupr((char *)arr[j].c_str())) == 0) // trong trường hợp không phân biệt hoa thường thì quy chuẩn về 1 dạng (hoặc cùng viết hoa hoặc cùng viết thường) rồi sau đó xóa đi
			{
				// xóa phần tử tại vị trí j do trùng với vị trí i
				arr.erase(arr.begin() + j);	
				size--;
				j--; // nhớ: Xóa tại vị trí nào thì vị trí đó phải --. Tương tự nếu thêm phần tử vào vị trí nào thì vị trí đó phải ++
			}
		}
	}
}

void GhiFile(vector<string> arr, ofstream &FileOut)
{
	FileOut.open("OUTPUT.txt", ios_base::out);
	cout << "\nGhi ket qua vao tap tin";
	int size = arr.size();
	for(int i = size - 1; i >= 1; --i)
		FileOut << arr[i] << endl;

	FileOut << arr[0];

	FileOut.close();
}

int main()
{
	ifstream FileIn;
	ofstream FileOut;
	vector<string> arr;
	
	DocFile(FileIn, arr);
	XuatVector(arr);

	//string TuDaiNhat = TimTuDaiNhat(arr);
	//cout << "\nTu dai nhat la: " << TuDaiNhat;

	int size = arr.size();

	if(size != 0)
	{
		cout << "\nCac tu co do dai dai nhat la: ";
		XuatTatCaCacTuCoDoDaiDaiNhat(arr);

		XoaCacTuTrungNhauTrongVector(arr);
	
		cout << "\nVector sau khi xoa trung nhau\n";
		XuatVector(arr);

		GhiFile(arr, FileOut);
	}

	
	system("pause");
	return 0;
}