#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point() { 
        // cout << "constructor without parameter (Default constructor)\n";
        x = 0; 
        y = 0;
    } ;
    Point(double a, double b)     {
        // cout << "construtor with 2 parameters \n";
        this->x = a; // setX
        this->y = b; // setY
    };
    
    Point(double t) {
        // cout <<  "constructor with 1 parameter\n";
        x = y = t; 
    };
    
    Point(const Point &p) { 
        // cout << "copy constructor - not essential\n";
        x = p.x;
        y = p.y;
    };
    ~Point() {
        // cout << "Des - Point\n";
    };
    // ~Point() {
    //  cout << "Destructor" << endl;
    // }
    double getX() {
        return x;
    };
    double getY() {
        return y;
    };
    void setXY(double x, double y) { // **************
        this->x = x;
        this->y = y;
    };
    double distance(double x2, double y2)
    {
        return sqrt(pow(this->x - x2, 2) + pow(this->y - y2, 2));
    };
    double distance(Point another) {
        // return sqrt((another.x-this->x)*(another.x-this->x)+(another.y-this->y)*(another.y-this->y));
        return distance(another.getX(), another.getY());
    };
    void print() {
        // cout << "Coordinates of the point: ";
        cout << "\t(" << x << "; " << y << ")" << endl;
    };

    friend double calculate_area_triangle(Point A, Point B, Point C) {
        // return (0.5*abs(b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
        return (0.5*abs((C.x-A.x)*(B.y-A.y)-(B.x-A.x)*(C.y-A.y)));
    };
};

class Polygon {
private:  
    Point* p;
    int n;
    double area;
public:
    // polygon - constructor with parameter m - vertex
    Polygon(int m) {
        n = m;
        p = new Point[m];
        area = 0;
    };

    void setPolygon();
    ~Polygon() {
        delete []p;
        cout << "Des - Polygon\n";
    };
};

void Polygon::setPolygon() {
     {
        double a, b;
        for (int i = 0; i < n; i++)
        {
            cout << "Input the vertex " << i + 1 << ":\n";
            cout << "x("<<i+1<<") = ";
            cin >> a;
            cout << "y("<<i+1<<") = ";
            cin >> b;
            p[i] = {a, b};
        }

        for (int i = 0; i < n; i++)
        {
            p[i].print();
        }

        cout << endl;
        for(int i = 0; i < n - 1; i++) {
            area = area + calculate_area_triangle(p[0], p[i], p[i+1]);
        }
        cout << "|| area = " << abs(area) << endl;

    };
}

int main () {
    Point a(0, 0);
    Point b(2, 0);
    Point c(0, 4);
    
    // cout << calculate_area_triangle(a, b, c);
    int m = 0;
    cout << endl << "Input the number of vertex: \n";
    cin >> m;
    Polygon P(m);
    P.setPolygon();

    return 0;
}