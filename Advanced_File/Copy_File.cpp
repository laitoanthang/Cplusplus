#include <iostream>
#include <fstream>
using namespace std;

void copy_file(string path, string destination)
{
	cout << path << endl;
	ifstream fin;
	
	ofstream fout;
	fin.open(path, ios::binary);
	// tim ten anh, trong duong dan fin.
	int found = path.rfind("\\");
	path = path.substr(found, path.length() - found);
	destination += path;
	cout << destination << endl;
	fout.open(destination, ios::binary);
	while (!fin.eof())
	{
		char temp;
		fin.read((char*)&temp, sizeof(char));
		fout.write((char*)&temp, sizeof(char));
	}
	fin.close();
	fout.close();
}

int main(int argc, char* argv[])
{
	if (argc!=3) {
		cout << "Error\n";
		return 0;
	}
	string path = argv[1];
	string destination = argv[2];
	copy_file(path, destination);
	return 0;
}
