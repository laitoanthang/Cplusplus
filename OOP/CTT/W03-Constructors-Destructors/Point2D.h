//
//  Point2D.h
//  Test20220308_Cons_Des
//
//  Created by Thanh Ho on 3/8/22.
//

#ifndef Point2D_h
#define Point2D_h

#include <iostream>
using namespace std;

class Point2D{
private:
    double x, y;
public:
    void print();
    void set(double x, double y);
    
    // Hàm dựng mặc định
    // Default constructor
    // Constructor with 0 parameter
    Point2D();
    
    // Hàm dựng có 2 tham số
    // Constructor with 2 parameters
    Point2D(double hd, double td);
    
    // Hàm dựng có 1 tham số
    // Constructor with 1 parameter
    Point2D(double u);
    
    // Hàm dựng sao chép
    // Copy constructor
    // Clone
    Point2D(const Point2D &oldObject);
    
    ~Point2D();
};

class Triangle{
private:
//    // v1, v2
//    Point2D A, B, C;
    
//    // v3 - Văn Tài
//    Point2D A(0, 0);
//    Point2D B(1, 0);
//    Point2D C(0, 1);
    
//    // v4 - Tú Trình
//    Point2D A{0, 0};
//    Point2D B{1, 0};
//    Point2D C{0, 1};
    
    // v5
    Point2D A, B, C;
public:
    void print();
    Triangle();
    ~Triangle();
};
#endif /* Point2D_h */
