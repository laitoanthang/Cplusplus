#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
		return 0;

	if (string(argv[1]) != "-r")
		return 0;

	ifstream fin;
	fin.open(argv[2]);


	string data = "";
	string tmp;
	while (!fin.eof())
	{
		getline(fin, tmp);
		data += tmp;
	}
	fin.close();
	cout << data << endl;
	system("pause");
	return 0;
}