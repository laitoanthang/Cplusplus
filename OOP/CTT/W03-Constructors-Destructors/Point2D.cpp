#include "Point2D.h"

void Point2D::print(){
    cout << "print" << endl;
    cout << "(" << x << ", " << y << ")" << endl;
}

void Point2D::set(double x, double y){
    this->x=x;
    this->y=y;
}

Point2D::Point2D(){
    cout << "Default cons" << endl;
    x = 0;
    y = 0;
}

Point2D::Point2D(double hd, double td){
    cout << "Cons with 2 params" << endl;
    x = hd;
    y = td;
}

Point2D::Point2D(double u) {
    cout << "Cons with 1 param" << endl;
    x = y = u;
}

Point2D::Point2D(const Point2D &oldObject){
    cout << "Copy cons" << endl;
//    for(int i = 0; i < 100000000; i++){
//        int u = 10;
//        u++;
//    }
    x = oldObject.x;
    y = oldObject.y;
}

Point2D::~Point2D(){
    cout << "Des" << endl;
}
//---------------------------
void Triangle::print(){
    cout << "A: ";
    A.print();
    cout << "B: ";
    B.print();
    cout << "C: ";
    C.print();
}

//// v1
//Triangle::Triangle(){
//    cout << "Default cons - Triangle" << endl;
//}

//// v2 - Trọng  An
//Triangle::Triangle(){
//    cout << "Default cons - Triangle" << endl;
//    A = {0, 0};
//    B = {1, 0};
//    C = {0, 1};
//}

//// v3 - Văn Tài
//Triangle::Triangle(){
//    cout << "Default cons - Triangle" << endl;
//}

//// v4 - Tú Trình
//Triangle::Triangle(){
//    cout << "Default cons - Triangle" << endl;
//}

// v5
Triangle::Triangle(): A(0, 0), B(1, 0), C(0, 1)
{
    cout << "Default cons - Triangle" << endl;
}

Triangle::~Triangle(){
    cout << "Des - Triangle" << endl;
}
