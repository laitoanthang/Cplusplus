#ifndef IntArray_h
#define IntArray_h

#include <iostream>
using namespace std;

class IntArray{
private:
//    bool b; // Trọng An
    int *a;
    int n;
public:
    void print();
    void input();
//    void setB(bool x){
//        b = x;
//    }
    
    // default cons
    IntArray();
    
    // copy cons
    IntArray(const IntArray &other);
    
    // assignment operator
    IntArray& operator=(const IntArray& other);
    
    // des
    ~IntArray();
};

#endif /* IntArray_h */
