#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

class Point {
private: 
	double x; // tác dụng của private là gì?
	double y; // public và private khác gì nhau?
public: 
	Point() { 
		cout << "constructor without parameter (Default constructor)\n";
		x = 0; 
		y = 0;
	} 
	Point(double a, double b) 
	{
		cout << "construtor with 2 parameters \n";
		this->x = a; // setX
		this->y = b; // setY
	}
	
	Point(double t) {
		cout <<  "constructor with 1 parameter\n";
		x = y = t; 
	}
	
	Point(const Point &p) { 
		cout << "copy constructor - not essential\n";
		x = p.x;
		y = p.y;
	}
	~Point() {
		cout << "Des - Point\n";
	}
	// ~Point() {
	// 	cout << "Destructor" << endl;
	// }
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void setXY(double x, double y) { // **************
		this->x = x;
		this->y = y;
	}
	double distance(double x2, double y2)
	{
		return sqrt(pow(this->x - x2, 2) + 
				pow(this->y - y2, 2));
	}
	double distance(Point another) {
		// return sqrt((another.x-this->x)*(another.x-this->x)+(another.y-this->y)*(another.y-this->y));
		return distance(another.getX(), another.getY());
	}
	void print()
	{
		// cout << "Coordinates of the point: ";
		cout << "\t(" << x << "; " << y << ")" << endl;
	}
};

class Triangle {
private:
	Point a, b, c;

public:
	// ':' init first time
	Triangle(): a{0}, b(2,0), c(0,1) { 
		cout << "Default Cons - Triangle\n";
	}
	Triangle(Point p1, Point p2, Point p3) {
		a = p1;
		b = p2;
		c = p3;
	}
	~Triangle() {
		cout << "\nDes - Triangle" << endl;
	}

	Point getA() {
		return a;
	}
	Point getB() {
		return b;
	}
	Point getC() {
		return c;
	}
	vector<double> edges() {
		vector<double> temp;
		temp.push_back(a.distance(b));
		temp.push_back(b.distance(c));
		temp.push_back(c.distance(a));
		return temp;
	}
	void print() {
		cout << "A: ";
		a.print();
		cout << "B: ";
		b.print();
		cout << "C: ";
		c.print();
	}

	bool check_whether_triangle() {
		// check condition
		double a = edges()[0];
		double b = edges()[1];
		double c = edges()[2];
	    if (a + b > c && a + c > b && b + c > a)
	        return 1;
	    else return 0;
	}
	double getArea() {
		double a = edges()[0];
		double b = edges()[1];
		double c = edges()[2];
		double p = getPerimeter() / 2;
		return (sqrt(p*(p-a)*(p-b)*(p-c)));
	}
	double getPerimeter() {
		double a = edges()[0];
		double b = edges()[1];
		double c = edges()[2];
		return (a + b + c);
	}

};

class TriangleArray {
private:
	vector<Triangle> triangle_array;
public:
	int getSize() {
		triangle_array.shrink_to_fit();
		return this->triangle_array.size();
	}
	
	void addTriangle(Triangle new_triangle) {
		if (new_triangle.check_whether_triangle() == 1) {
			cout << "Ok\n";
			this->triangle_array.push_back(new_triangle);
		}
		else cout << "Not Ok\n";
	}
	double getMaximumTriangle() {
		double max = triangle_array[0].getArea();
		for (int i = 1; i < getSize(); i++)
		{
			double area = triangle_array[i].getArea();
			if (area > max) {
				max = area;
			}
		}
		return max;
	}
};


int main()
{
	// ifstream fin;
	// string path = "Point_Triangle.txt";
	// fin.open(path);
	// if (!fin.is_open()){
	// 	cout << "Cannot open this file\n";
	// 	return 0;
	// }
	// else cout << "Reading this file...\n";
	// double x1 = 0;
	// double y1 = 0;
	// double x2 = 0;
	// double y2 = 0;
	// double x3 = 0;
	// double y3 = 0;
	// TriangleArray array;
	// while (!fin.eof()) {	
	// 	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// 	// Check whether triangle is valid or not
	// 	Point p1, p2, p3;
	// 	p1.setXY(x1, y1);
	// 	p2.setXY(x2, y2);
	// 	p3.setXY(x3, y3);
	// 	Triangle new_triangle(p1, p2, p3);
	// 	array.addTriangle(new_triangle);
	// }
	// int size = array.getSize();
	// cout << size << " Triangle is Valid\n";
	// cout << array.getMaximumTriangle();

	// cout << endl << endl;
	// Point t(5.5);
	// t.print();
	// Point t2(t);
	// t2.print();
	// Point t3 = t;
	// t3.print();
	// Point t5 = 4;
	// t5.print();

	// Point *t6;
	// t6 = new Point(6, 6.7);
	// t6->print();

	// Point *t7;
	// t7 = &t; // khong goi den constructor nao vi
	// // no chi tro den dia chi cua 1 object t
	// t7->print();
	// cout << endl;
	
	Point p1(3,5);
	cout << endl;
	Point p2(0);
	cout << endl;
	Point p3 = {7,1.5};
	cout << endl;
	p3.print();
	cout << endl;
	Triangle t1;
	cout << endl;
	t1.print();
	cout << endl;
	return 0;
}
