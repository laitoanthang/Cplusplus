#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct sale
{
	int id;
	string name;
	float value;
};

void readandShow(const char* filename)
// read a binary file -> calculate -> print total sales of each staff
{
	ifstream fin;
	sale* info = nullptr;
	info = new sale[100];
	fin.open(filename, ios::binary);
	if (!fin.is_open())
	{
		cout << "Cannot open this file\n";
		return;
	}
	int n = 0;
	while (!fin.eof())
	{
		fin.read((char*)&info[n], sizeof(sale));
		n++;
		
	}
	cout << "Sale infomation details\n";
	for (int i = 0; i < n-1; i++)
	{
		cout << "ID: " << info[i].id << endl;
		cout << "Name: " << info[i].name << endl;
		cout << "Sales: " << info[i].value << endl;
	}
}

int main()
{
	/*ofstream wf("saleinfo_out.txt", ios::out | ios::binary);
	if (!wf) {
		cout << "Cannot open file!" << endl;
		return 1;
	}
	sale wstu[3];
	wstu[0].id = 1;
	wstu[0].name = "Ram";
	wstu[0].value = 100.5;
	wstu[1].id = 2;
	wstu[1].name = "Shyam";
	wstu[1].value = 204.5;
	wstu[2].id = 3;
	wstu[2].name = "Madhu";
	wstu[2].value = 599.5;
	for (int i = 0; i < 3; i++)
		wf.write((char*)&wstu[i], sizeof(sale));
	wf.close();*/
	// the code above was made to create the binary file name saleinfo_out.txt
	// uncomment it to run


	readandShow("saleinfo_out.txt");

	
	return 0;
}