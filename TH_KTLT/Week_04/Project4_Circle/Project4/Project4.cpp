#include <iostream>
#include <cmath>
using namespace std;

struct circle
{
	float x;
	float y;
	float radius;
};

void Read_File(FILE*& f, int& m, circle*& a)
{
	fopen_s(&f, "in_circles.txt", "rt");
	if (f == nullptr)
	{
		cout << "cannot read this file!";
	}
	else {
		fscanf_s(f, "%d", &m);
		a = new circle[m];
		for (int i = 0; i < m; i++)
		{
			fscanf_s(f, "%f%f%f", &a[i].x, &a[i].y, &a[i].radius);
		}
	}
}

int check_Isolated(circle* a, int m, circle t)
{
	float d = 0;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		d = sqrt(pow((a[i].x - t.x), 2) + pow((a[i].y - t.y), 2));
		if (d < (a[i].radius + t.radius))
		{
			count++;
		}
	}
	return count;
}

void List_Isolated(int m, circle* a, circle*& l, int& n)
{
	n = 0;
	l = new circle[10];
	for (int i = 0; i < m; i++)
	{
		int count = check_Isolated(a, m, a[i]);
		if (count == 1)
		{
			l[n].x = a[i].x;
			l[n].y = a[i].y;
			l[n].radius = a[i].radius;
			n++;
		}
	}
	
}

void Write_File(FILE*& f, circle*& l, int n)
{
	fopen_s(&f, "out_isolated.txt", "w");
	if (f == nullptr)
	{
		cout << "Error!";
		exit(1);
	}
	if (n == 0)
		fprintf(f, "%d", 0);
	else for (int i = 0; i < n; i++)
	{
		fprintf(f, "%0.1f\t%0.1f\t%0.1f", l[i].x, l[i].y, l[i].radius);
		fprintf(f, "\n");
	}
}

int main()
{
	circle* l = nullptr;
	circle* a = nullptr;
	int m = 0;
	int n = 0;
	FILE* fi;
	FILE* fo;
	Read_File(fi, m, a);
	List_Isolated(m, a, l, n);
	Write_File(fo, l, n);
	delete[]l;
	delete[]a;
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}