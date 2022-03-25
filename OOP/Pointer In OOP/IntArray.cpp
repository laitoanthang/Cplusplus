#include "IntArray.h"

void IntArray::print(){
    if(n == 0){
        cout << "Empty array" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void IntArray::input(){
    // a cũ
    if(n == 0){
        delete []a;
        a = NULL;
        n = 0;
    }
    
    cout << "Enter n: ";
    cin >> n;
    
    a = new int[n];
    
    for(int i = 0; i < n; i++){
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

IntArray::IntArray(){
    cout << "default cons" << endl;
//    b = true;
    a = NULL;
    n = 0;
}

IntArray::~IntArray(){
    cout << "des" << endl;
    
//    if(n != 0 && b == true){
    
    if(n != 0){
        delete []a;
        a = NULL;
        n = 0;
    }
}

// deep copy
IntArray::IntArray(const IntArray &other)
{
    cout << "copy cons" << endl;
    n = other.n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = other.a[i];
}


//// shallow copy
//// giống y chang với default copy cons làm
//// nếu code như vầy, thì chúng ta ko cần code
//// ko nên code theo cách này
//IntArray::IntArray(const IntArray &other)
//{
//    cout << "copy cons" << endl;
//    n = other.n;
//    a = other.a;
//}

//// Đức Huy tham khảo từ stackoverflow
//// ko được: 10 0 269618092 -1073741824
//// đừng dùng
//IntArray::IntArray(const IntArray &other)
//{
//    cout << "copy cons" << endl;
//    n = other.n;
//    a = new int(*other.a); // new int(10)
//}

//// Nhất Anh => OK
//IntArray& IntArray::operator=(const IntArray& other)
//{
//    n = other.n;
//    a = new int[n];
//    memcpy(a, other.a, n * sizeof(int));
//    return *this;
//}

IntArray& IntArray::operator=(const IntArray& other)
{
    // tránh gài bẫy: m2 = m2
    if (this == &other){
        return *this;
    }

    if (a == nullptr){
        a = new (std::nothrow) int[other.n];
        if (a == nullptr) { return *this; }
        n = other.n;
    }
    if (a != nullptr && n != other.n){
        return *this;
        
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = other.a[i];
    }
    return *this;
}
