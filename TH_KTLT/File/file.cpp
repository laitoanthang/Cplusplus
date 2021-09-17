// ios::app--> "We cannot move the pointer. It will be only at end."

// ios::ate--> "We can move the record pointer to any other place."

// ios::binary --> to record the data in the binary mode

// ios::nocreate
// ios::noreplace
// ios::trunc <- erase the file if it exists.
#include <iostream>
#include <fstream>
using namespace std;

ofstream fout;

void writing_file()
{
	char tentt[50];
	cin.ignore();
	cout << "Input your file\n";
	cin.getline(tentt, 51);
	fout.open(tentt);
	if (!fout.is_open())
	{
		cout << "Error, cannot open your file";
		return;
	}
	else
	{
		fout << "Nay cau oi!!!\n";
		fout << "To co dieu muon noi\n";
		fout.close();
		cout << "Successful process\n";
	}
}

void writing_extra() 
{
	char tentt[50];
	cout << "Input your file\n";
	cin.ignore();
	cin.getline(tentt, 51);
	fout.open(tentt, ios::app);
	fout << "That ra to thich cau\n";
	fout << "Tu rat lau roi\n";
	fout.close();
	cout << "Successful process\n";	
}

void Menu()
{
	int choice = 0;
	char filename[50];
	do 
	{
		cout << "\nProgram Handle File\n";
		cout << "1. Writing file\n";
		cout << "2. Writing more text to file\n";
		cout << "3. Reading file\n";
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
	} while (choice!=0);
}

int main()
{
	Menu();
	return 0;
}