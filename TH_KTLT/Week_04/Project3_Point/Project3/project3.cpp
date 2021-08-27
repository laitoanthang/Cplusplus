#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct point
{
	float x;
	float y;
};

void Read_File(FILE*& f, int& m, point*& a)
{
	fopen_s(&f, "in_points.txt", "rt");
	if (f == nullptr)
	{
		cout << "cannot open this file!";
	}
	else {
		fscanf_s(f, "%d", &m);
		a = new point[m];
		for (int i = 0; i < m; i++)
		{
			fscanf_s(f, "%f%f", &a[i].x, &a[i].y);
		}
	}
}

float distance(point t1, point t2)
{
	return sqrt(pow((t2.y - t1.y), 2) + pow((t2.x - t1.x), 2));
}

void nearest(point*& a, int m, point& temp1, point& temp2)
{
	float dis = 10000;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (distance(a[i], a[j]) < dis)
			{
				dis = distance(a[i], a[j]);
				temp1.x = a[i].x;
				temp1.y = a[i].y;

				temp2.x = a[j].x;
				temp2.y = a[j].y;
			}
		}
	}
}

void Write_File(FILE*& f, point t1, point t2)
{
	fopen_s(&f, "out_nearest.txt", "w");
	if (f == nullptr)
	{
		cout << "Error!";
		exit(1);
	}
	fprintf(f, "(%0.1f:%0.1f)\n(%0.1f:%0.1f)", t1.x, t1.y, t2.x, t2.y);
}


int main()
{
	point* a;
	int m = 0;
	point temp1;
	point temp2;
	FILE* fi;
	FILE* fo;
	Read_File(fi, m, a);
	nearest(a, m, temp1, temp2);
	Write_File(fo, temp1, temp2);
	delete[] a;
	fclose(fi);
	fclose(fo);
	system("pause");
	return 0;
}