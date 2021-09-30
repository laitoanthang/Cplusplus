// ios::app--> "We cannot move the pointer. It will be only at end."
// ios::ate--> "We can move the record pointer to any other place."
// ios::binary --> to record the data in the binary mode
// ios::nocreate
// ios::noreplace
// ios::trunc <- erase the file if it exists.
#include <iostream>
#include <fstream>
using namespace std;



void writing_file()
{
	ofstream fout;
	char tentt[50];
	cin.ignore();
	cout << "Input your file\n";
	cin.getline(tentt, 51);
	fout.open(tentt, ios::out);
	if (!fout.is_open())
	{
		cout << "Error, cannot open your file";
		return;
	}
	else
	{
		fout << "Nay cau oi!!!\n";
		fout << "To co dieu muon noi\n";
		cout << "Successful process\n";
	}
	fout.close();
}

void writing_extra() 
{
	ofstream fout;
	char tentt[50];
	cout << "Input your file\n";
	cin.ignore();
	cin.getline(tentt, 51);
	fout.open(tentt, ios::app);
	// append the text you want
	fout << "That ra to thich cau\n";
	fout << "Tu rat lau roi\n";
	fout.close();
	cout << "Successful process\n";	
}

void convertTextToBinary()
{
	char* text = new char[50];
	char* binary = new char[50];
	cin.ignore();
	cout << "Input text file name: ";
	cin.getline(text, 51);
	cout << "Input binary file name: ";
	cin.getline(binary, 51);
	ifstream fin;
	fin.open(text, ios::in);
	ofstream fout;
	fout.open(binary, ios::out|ios::binary);
	if (!fin.is_open())
	{
		cout << "Error when opening your file\n";
		return;
	}
	while (!fin.eof())
	{
		int c;
		fin >> c;
		fout.write((char*)&c, sizeof(c));
	}
	
	fin.close();
	fout.close();	
}

void convertBinaryToText()
{
	
}

void Menu()
{
	int choice = 0;
	char filename[50];
	do 
	{
		cout << "\nProgram Handle File\n";
		cout << "1. Writing a new file\n";
		cout << "2. Writing more text to file\n";
		cout << "3. Reading file\n";
		cout << "4. Convert text to binary file\n";
		cout << "5. Convert binary to text file\n";
		cout << "0. Exit program\n";
		cout << "----------------------\n";
		cout << "What is your option?\n";
		cin >> choice;
		if (choice==0)
		{
			cout << "exiting...\n";
			return;	
		}
		if (choice == 1)
			writing_file();
		if (choice == 2)
			writing_extra();
		if (choice == 4)
			convertTextToBinary();
	} while (choice!=0);
}

int main()
{
	Menu();
	return 0;
}