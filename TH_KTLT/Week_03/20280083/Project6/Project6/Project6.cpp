#include <iostream> 
using namespace std;

struct circle {
	int radius;
	int x;
	int y;
};

void input(circle& t) {
	cout << "Input x: ";
	cin >> t.x;
	cout << "Input y: ";
	cin >> t.y;
	cout << "Input radius: ";
	cin >> t.radius;

}

void output(circle t) {
	cout << "Coordinates: " << endl;
	cout << "(x;y) = "<<"("<<t.x<<";"<< t.y <<")"<< endl;
	cout << "Radius: " << t.radius << endl;
}

void input_array(circle*& a, int& n) {
	cout << "Input the numbers of the circle you want: ";
	cin >> n;
	a = new circle[n];
	for (int i = 0; i < n; i++)
	{
		input(a[i]);
	}
}

void perimeter_area(circle c) {
	int p = 0;
	int s = 0;
	p = 2 * 3.14 * c.radius;
	s = 3.14 * c.radius * c.radius;
	cout << "Perimeter: " << p << endl;
	cout << "Area: " << s << endl;
}

void output_array(circle* a, int n) {
	for (int i = 0; i < n; i++) {
		output(a[i]);
	}
}

void sort_Circle(circle* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].radius > a[j].radius) {
				int temp = a[i].radius;
				a[i].radius = a[j].radius;
				a[j].radius = temp;
			}
		}
	}
}

void circle_intersects(circle* a, int n) {
	int d = 0;
	cout << "Circle intersection in the array: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d = sqrt(pow(a[j].x - a[i].x, 2) - pow(a[j].y - a[i].y, 2));
			if (d < a[i].radius + a[j].radius) {
				cout << i << "," << j << endl;
			}
		}
	}
}


int main() {
	int n = 0;
	circle t;
	input(t);
	output(t);
	
	perimeter_area(t);
	
	circle* a = nullptr;
	input_array(a, n);
	cout << endl;
	output_array(a, n);
	cout << endl;
	sort_Circle(a, n);
	circle_intersects(a, n);

	delete[]a;
	system("pause");
	return 0;
	
}