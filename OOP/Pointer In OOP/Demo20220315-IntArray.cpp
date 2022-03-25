#include "IntArray.h"

int main() {
    cout << "m1" << endl;
    IntArray m1;
    m1.print();
    cout << endl;
    
    cout << "m2" << endl;
    IntArray m2;
    m2.input();
    m2.print();
    cout << endl;
    
    cout << "m3" << endl;
    IntArray m3(m2);
//    m3.setB(false);
    m3.print();
    cout << endl;
    
    cout << "m4" << endl;
    IntArray m4;
    
    // default assignment operator
    m4 = m2;
    m4.print();
    cout << endl;
    
    return 0;
}
