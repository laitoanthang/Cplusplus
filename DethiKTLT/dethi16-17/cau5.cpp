#include <iostream>
#include <fstream>
using namespace std;
//Thông tin sinh viên gồm họ tên, mã số, năm sinh, lớp học
// điểm trung bình và được lưu vào trong tập nhị phân

// Một tập tin lưu thông tin các sinh viên dưới dạng binary
// 1. Khai báo kiểu cấu trúc biểu diễn 1 sinh viên 
// 2. Viết hàm binaryToText(char* binFile, char* textFile)
// (Khi chuyển sang tập text thì có dạng ...-...-...-...)

// Để kiểm tra thì làm 2 hàm cmdToBinary và binaryToText

struct sinhvien
{
	char* hoten = new char[50];
	int maso;
	int namsinh;
	char* lophoc = new char[20];
	float diemtb;
	
};

void Input_1sv(sinhvien& sv)
{
	cin.ignore();
	cout << "Input hoten: ";
	cin.getline(sv.hoten, 51);
	cout << "Input maso ";
	cin >> sv.maso;
	cout << "Input nam sinh ";
	cin >> sv.namsinh;
	cout << "Input lop hoc ";
	cin.ignore();
	cin.getline(sv.lophoc, 21);
	cout << "Input diem trung binh ";
	cin >> sv.diemtb;
	cout << "------------------------------------\n";
}

void Input_sv(int& n, sinhvien*& a)
{
	cout << "Input the number of sinh vien: ";
	cin >> n;
	a = new sinhvien[n];
	for (int i = 0; i < n; i++)
	{
		Input_1sv(a[i]);
	}
}

void cmdToFile(sinhvien* a, int n)
{
	ofstream fout;
	fout.open("cmdToText.txt", ios:: binary | ios:: out);
	if (!fout.is_open())
	{
		cout << "Cannot open this file\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fout << a[i].maso << '-' << a[i].hoten << '-' << a[i].namsinh << '-' << a[i].lophoc << '-' << a[i].diemtb << endl;
	}
	fout.close();
}

void cmdToBinFile(sinhvien* a, int n)
{
	ofstream fout;
	fout.open("cmdToBinFile.txt", ios::binary | ios:: out);
	if (!fout.is_open()){
		cout << "Cannot open this file\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fout.write((char*)&a[i], sizeof(sinhvien));
		
	}
	fout.close();
}

void binaryToText(string binFile, string textFile)
{
	sinhvien* a = new sinhvien[100];

	ifstream fin;
	fin.open(binFile, ios::binary);
	if (!fin.is_open())
	{
		cout << "Cannot open BinFile\n";
		return;
	}
	int n = 0;
	while (!fin.eof())
	{
		fin.read((char*)&a[n].hoten, sizeof(char*));
		fin.read((char*)&a[n].maso, sizeof(int));
		fin.read((char*)&a[n].namsinh, sizeof(int));
		fin.read((char*)&a[n].lophoc, sizeof(char*));
		fin.read((char*)&a[n].diemtb, sizeof(float));
		n++;
	}
	fin.close();
	cout << "----------------" <<n << "----------------";
	ofstream fout;
	fout.open(textFile, ios::binary | ios::out);
	if (!fout.is_open())
	{
		cout << "Cannot open textFile\n";
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		fout << a[i].maso << '-' << a[i].hoten << '-' << a[i].namsinh << '-' << a[i].lophoc << '-' << a[i].diemtb << endl;
	}
	fout.close();
	delete a;
}

int main()
{
// 	int n = 0;
// 	sinhvien* a;
	
// 	Input_sv(n, a);
// 	cmdToFile(a, n);
// 	cmdToBinFile(a, n);


	binaryToText("cmdToBinFile.txt", "TextFile.txt");
	return 0;
}