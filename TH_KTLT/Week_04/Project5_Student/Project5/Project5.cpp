#include <iostream>
#include <stdio.h>
using namespace std;

struct student
{
	char id[10];
	char name[50];
	float score;
};

void Read_File(FILE*& f, int& n, student*& a)
{
	fopen_s(&f, "in_students.csv", "rt");
	if (f == nullptr)
	{
		cout << "cannot open this file!";
	}
	else {
		fscanf_s(f, "%d", &n);
		a = new student[n];
		for (int i = 0; i < n; i++)
		{
			fscanf_s(f, "%[^,],\t%[^,],\t%f", a[i].id, 10, a[i].name, 50, &a[i].score);
			//fgets(a[i].id, 10, f);
		}
	}
}

void output(student* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].id << " " << a[i].name << " " << a[i].score << "\n";
	}
}

float max_score(student* a, int n)
{
	float max = 0;  
	for (int i = 0; i < n; i++)
	{
		if (a[i].score > max)
		{
			max = a[i].score;
		}
	}
	return max;
}

void Write_File(FILE*& f, student* a, int n)
{
	fopen_s(&f, "out_max.csv", "w");
	if (f == nullptr)
	{
		cout << "Exit__";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i].score == max_score(a, n))
		{
			fprintf(f, "%s, ", a[i].id);
			fprintf(f, "%s, ", a[i].name);
			fprintf(f, "%f", a[i].score);
			printf("\n");
		}
	}
	
}

int main()
{
	FILE* fi;
	FILE* fo;
	int n = 0;
	student* a = nullptr;
	Read_File(fi, n, a);
	output(a, n);
	Write_File(fo, a, n);
	delete[]a;
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}