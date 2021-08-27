#include <iostream>
#include <cstdio>
using namespace std;

void read_File(FILE*& f, int& m, int& n)
{
	fopen_s(&f, "input.txt", "rt");
	if (f == nullptr)
	{
		cout << "Can not open this file\n";
	}
	else {
		fscanf_s(f, "%d %d", &m, &n);
		printf("Value in file input.txt: %d %d\n\n", m, n);
	}
	
}

int isPrime(int n)
{
	if (n < 2) 
		return 0;
	int count = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			count++;
	}
	if (count == 0)
		return 1;
	else return 0;
}

void write_File(FILE*& f, int m, int n)
{
	fopen_s(&f, "output.txt", "w");
	if (f == nullptr)
	{
		printf("Error!");
		exit(1);
	}
	for (int i = m; i <= n; i++)
	{
		if (isPrime(i))
			fprintf(f, "%d ", i);
	}
	
}

int main()
{
	int m = 0;
	int n = 0;
	FILE* fi;
	FILE* fo;
	read_File(fi, m, n);
	write_File(fo, m, n);
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}