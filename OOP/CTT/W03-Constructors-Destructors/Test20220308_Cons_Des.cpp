#include "Point2D.h"

int main(){
//    Triangle t1;
//    t1.print();
//    cout << endl;
    
    Triangle t2; // (0, 0), (1, 0), (0, 1)
    t2.print();
    cout << endl;
    
    return 0;
}

//#include "Point2D.h"
//
//void f1(Point2D p);
//void f2(Point2D &p);
//void f3(Point2D *p);
//Point2D f4();
//
//int main(){
////    Point2D p1;
////    cout << "p1" << endl;
////    p1.print();
////    cout << endl;
//
////    Point2D p2; // (0, 0)
////    cout << "p2" << endl;
////    p2.set(0, 0);
////    p2.print();
////    cout << endl;
//
//    Point2D p3; // (0, 0)
//    cout << "p3" << endl;
//    p3.print();
//    cout << endl;
//
//    Point2D p4(3, 4); // (3, 4)
//    cout << "p4" << endl;
//    p4.print();
//    cout << endl;
//
//    Point2D p5(10); // (10, 10)
//    cout << "p5" << endl;
//    p5.print();
//    cout << endl;
//
//    // Thực tế, đa số trường hợp, ko cần viết copy constructor,
//    // thì code vẫn chạy được
//    // Nếu trong 1 class, dev ko viết copy constructor, thì sẽ có default copy constructor,
//    // và default copy constructor hoạt động tốt với đa số trường hợp
//    Point2D p6(p4); // (3, 4)
//    cout << "p6" << endl;
//    p6.print();
//    cout << endl;
//
//    // ko cần viết thêm constructor nào nữa
//    Point2D p7(-10, 7);
//    cout << "p7" << endl;
//    p7.print();
//    cout << endl;
//
//
//    // initialize
//    Point2D p8 = p5; // tương đương cách viết Point2D p8(p5);
//    cout << "p8" << endl;
//    p8.print();
//    cout << endl;
//
//    //  Trình:  gọi hàm dựng 1 tham số => SAI!!!
//    // Others: gọi hàm dựng sao chép => SAI!!!
//    // assign
//    Point2D p9;
//    cout << "p9" << endl;
//    p9 = p5;
//    p9.print();
//    cout << endl;
//
////    int x = 3; // init
////    x = 5; // assign
////
////    const double pi = 3.14;
////    pi = 3.141;
//
//    // Nếu trong 1 class, dev ko khai báo bất kì constructor nào,
//    // thì class đó sẽ có sẵn 1 default constructor
//    // Tuy nhiên, khi dev đã biết bất kì 1 constructor nào rồi,
//    // thì default constructor có sẵn, sẽ ko còn nữa
//    // xem xét: viết default constructor
//
////    // C++ sẽ hiểu nhầm thành function declaration
////    // Hàm p10()
////    // ko tham số
////    // return về Point2D
////    // code, body, definition, chưa có
////    Point2D p10();
//
//    Point2D p11 = {3, 4}; // tương đương với Point2D p11(3, 4);
//    cout << "p11" << endl;
//    p11.print();
//    cout << endl;
//
//    Point2D p12(2, 3);
//    cout << "p12" << endl;
//    p12 = 4; // tương đương p12 = Point2D(4); => anonymous / no-name object
//    p12.print();
//    cout << endl;
//
//    Point2D *p13; // chưa gọi cons vì chưa tạo object mới
//    cout << "*p13" << endl;
////    p13 = new Point2D;
//    p13 = new Point2D(7);
//    p13->print();
//    cout << endl;
//
//    Point2D *p14;
//    cout << "*p14" << endl;
//    p14 = &p11; // ko gọi cons vì ở đây là đang point/reference an existing object
//    p14->print();
//    cout << endl;
//
//    // Khi truyền tham số dạng tham trị (passed by value),
//    // thì trước khi thực hiện hàm, thì copy constructor sẽ ĐƯỢC GỌI
//    f1(p11);
//    cout << endl;
//
//    // Khi truyền tham số dạng tham chiếu (passed by reference),
//    // thì trước khi thực hiện hàm, thì copy constructor sẽ KHÔNG ĐƯỢC GỌI
//    f2(p11);
//    cout << endl;
//
//    // Khi truyền tham số dạng con trỏ,
//    // thì copy constructor sẽ KHÔNG ĐƯỢC GỌI
//    f3(&p11);
//    cout << endl;
//
////    delete p13;
//
//    // 2 param
//    // copy
//    // -1, -1
//    Point2D p15;
//    cout << "p15" << endl;
//    p15 = f4();
//    p15.print();
//    cout << endl;
//
//    delete p13;
//    cout << endl;
//
//    delete p14; // runtime error!!
//    cout << endl;
//
//    for(int i = 0; i < 3; i++){
//        Point2D p16;
//        p16.print();
//        cout << endl;
//    }
//    cout << "End of for loop" << endl;
//
//    return 0;
//}
//// Constructor là hàm được gọi NGAY SAU KHI 1 object được sinh ra
//// Khởi tạo các giá trị hợp lệ cho tất cả các thuộc tính của object
//
//// Destructor là hàm được gọi NGAY TRƯỚC KHI 1 object được hủy
//// Dọn dẹp trước khi "ra đi"
//
//// Con người
//// Constructor
//
//// Mặc định trong 1 class có sẵn 4 hàm:
//// Default constructor
//// Copy constructor
//// Assignment operator
//// Destructor
//
//Point2D f4(){
//    Point2D p(-1, -1);
//    cout << "p-f4()" << endl;
//    return p;
//}
//
//void f3(Point2D *p){
//    cout << "f3" << endl;
//    p->print();
//}
//
//void f2(Point2D &p){
//    cout << "f2" << endl;
//    p.print();
//}
//
//void f1(Point2D p){
//    cout << "f1" << endl;
//    p.print();
//}
